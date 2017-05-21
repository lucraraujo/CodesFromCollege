#include <QtGui>

#include "mainwindow.h"

//![0]
MainWindow::MainWindow()
{
    /*Passa a reconhecer os caracteres especiais*/
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    mediaObject = new Phonon::MediaObject(this);
    metaInformationResolver = new Phonon::MediaObject(this);

    mediaObject->setTickInterval(1000);
    //![0]
    //![2]
    connect(mediaObject, SIGNAL(tick(qint64)), this, SLOT(tick(qint64)));
    connect(mediaObject, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this, SLOT(stateChanged(Phonon::State,Phonon::State)));
    connect(metaInformationResolver, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this, SLOT(metaStateChanged(Phonon::State,Phonon::State)));
    connect(mediaObject, SIGNAL(currentSourceChanged(Phonon::MediaSource)),
            this, SLOT(sourceChanged(Phonon::MediaSource)));
    connect(mediaObject, SIGNAL(aboutToFinish()), this, SLOT(aboutToFinish()));
    //![2]

    //![1]
    Phonon::createPath(mediaObject, audioOutput);
    //![1]


    setupActions();
    setupMenus();
    setupUi();
    timeLcd->display("00:00");

    qsrand(time(NULL));
    totalTimeLcd->display("00:00");
    readSettings();
}

//![6]
void MainWindow::addFiles()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      tr("Selecione os Arquivos de Música"),
                                                      QDesktopServices::storageLocation(QDesktopServices::MusicLocation),
                                                      tr("Músicas MP3 (*.mp3)"));
    if (files.isEmpty())
        return;
    allFiles += files;

    int index = sources.size();
    foreach (QString string, files) {
        Phonon::MediaSource source(string);

        sources.append(source);
    }
    if (!sources.isEmpty())
        metaInformationResolver->setCurrentSource(sources.at(index));

}
//![6]

void MainWindow::about()
{
    QMessageBox::information(this, tr("Sobre LinAmp"),
                             tr("The Music Player example shows how to use Phonon - the multimedia"
                                " framework that comes with Qt - to create a simple music player."));
}

//![9]
void MainWindow::stateChanged(Phonon::State newState, Phonon::State /* oldState */)
{
    if ((musicTable->currentRow() >= (musicTable->rowCount() -1)) && !shufflePushButton->isChecked())
        nextAction->setEnabled(false);
    else
        nextAction->setEnabled(true);

    if ((musicTable->currentRow() <= 0) && !shufflePushButton->isChecked())
        previousAction->setEnabled(false);
    else
        previousAction->setEnabled(true);

    if (newState == Phonon::PlayingState)
    {
        ffAction->setEnabled(true);
        rwdAction->setEnabled(true);
    }
    else
    {
        ffAction->setEnabled(false);
        rwdAction->setEnabled(false);
    }

    switch (newState) {
    case Phonon::ErrorState:
        if (mediaObject->errorType() == Phonon::FatalError) {
            QMessageBox::warning(this, tr("Fatal Error"),
                                 mediaObject->errorString());
        } else {
            QMessageBox::warning(this, tr("Error"),
                                 mediaObject->errorString());
        }
        break;
        //![9]
        //![10]
        case Phonon::PlayingState:
        playAction->setEnabled(false);
        playAction->setVisible(false);
        pauseAction->setEnabled(true);
        pauseAction->setVisible(true);
        stopAction->setEnabled(true);
        break;
        case Phonon::StoppedState:
        stopAction->setEnabled(false);
        pauseAction->setEnabled(false);
        pauseAction->setVisible(false);
        playAction->setVisible(true);
        playAction->setEnabled(true);
        timeLcd->display("00:00");
        break;
        case Phonon::PausedState:
        pauseAction->setEnabled(false);
        pauseAction->setVisible(false);
        stopAction->setEnabled(true);
        playAction->setVisible(true);
        playAction->setEnabled(true);
        break;
        //![10]
        case Phonon::BufferingState:
        break;
        default:
        ;
    }
}

//![11]
void MainWindow::tick(qint64 time)
{
    QTime displayTime(0, (time / 60000) % 60, (time / 1000) % 60);

    timeLcd->display(displayTime.toString("mm:ss"));
}
//![11]

//![12]
void MainWindow::tableDoubleClicked(int row, int /* column */)
{
    mediaObject->stop();
    mediaObject->clearQueue();

    if (row >= sources.size())
        return;

    mediaObject->setCurrentSource(sources[row]);

    mediaObject->play();
}
//![12]

//![13]
void MainWindow::sourceChanged(const Phonon::MediaSource &source)
{
    musicTable->selectRow(sources.indexOf(source));
    timeLcd->display("00:00");

    qint64 time = mediaObject->totalTime();
    QTime displayTime(0, (time / 60000) % 60, (time / 1000) % 60);
    totalTimeLcd->display(displayTime.toString("mm:ss"));
}
//![13]

//![14]
void MainWindow::metaStateChanged(Phonon::State newState, Phonon::State /* oldState */)
{
    if (newState == Phonon::ErrorState) {
        QMessageBox::warning(this, tr("Erro ao abrir arquivos"),
                             metaInformationResolver->errorString());
        while (!sources.isEmpty() &&
               !(sources.takeLast() == metaInformationResolver->currentSource())) {}  /* loop */;
        return;
    }

    if (newState != Phonon::StoppedState && newState != Phonon::PausedState)
        return;

    if (metaInformationResolver->currentSource().type() == Phonon::MediaSource::Invalid)
        return;

    QMap<QString, QString> metaData = metaInformationResolver->metaData();

    QString title = metaData.value("TITLE");
    if (title == "")
        title = metaInformationResolver->currentSource().fileName();

    QTableWidgetItem *titleItem = new QTableWidgetItem(title);
    titleItem->setFlags(titleItem->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem *artistItem = new QTableWidgetItem(metaData.value("ARTIST"));
    artistItem->setFlags(artistItem->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem *albumItem = new QTableWidgetItem(metaData.value("ALBUM"));
    albumItem->setFlags(albumItem->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem *yearItem = new QTableWidgetItem(metaData.value("DATE"));
    yearItem->setFlags(yearItem->flags() ^ Qt::ItemIsEditable);
    //![14]

    int currentRow = musicTable->rowCount();
    musicTable->insertRow(currentRow);
    musicTable->setItem(currentRow, 0, titleItem);
    musicTable->setItem(currentRow, 1, artistItem);
    musicTable->setItem(currentRow, 2, albumItem);
    musicTable->setItem(currentRow, 3, yearItem);

    //![15]
    if (musicTable->selectedItems().isEmpty()) {
        musicTable->selectRow(0);
        mediaObject->setCurrentSource(metaInformationResolver->currentSource());
    }

    Phonon::MediaSource source = metaInformationResolver->currentSource();
    int index = sources.indexOf(metaInformationResolver->currentSource()) + 1;
    if (sources.size() > index) {
        metaInformationResolver->setCurrentSource(sources.at(index));
    }
    else {
        musicTable->resizeColumnsToContents();
        if (musicTable->columnWidth(0) > 300)
            musicTable->setColumnWidth(0, 300);
    }
}
//![15]

//![16]
void MainWindow::aboutToFinish()
{
    int index = sources.indexOf(mediaObject->currentSource()) + 1;
    if (sources.size() > index) {
        mediaObject->enqueue(sources.at(index));
    }
}
//![16]

void MainWindow::setupActions()
{
    playAction = new QAction(style()->standardIcon(QStyle::SP_MediaPlay), tr("Tocar"), this);
    playAction->setShortcut(tr("Ctrl+P"));
    playAction->setDisabled(true);

    pauseAction = new QAction(style()->standardIcon(QStyle::SP_MediaPause), tr("Pausar"), this);
    pauseAction->setShortcut(tr("Ctrl+A"));
    pauseAction->setDisabled(true);
    pauseAction->setVisible(false);

    stopAction = new QAction(style()->standardIcon(QStyle::SP_MediaStop), tr("Parar"), this);
    stopAction->setShortcut(tr("Ctrl+S"));
    stopAction->setDisabled(true);

    nextAction = new QAction(style()->standardIcon(QStyle::SP_MediaSkipForward), tr("Próxima"), this);
    nextAction->setShortcut(tr("Ctrl+N"));
    nextAction->setDisabled(true);

    previousAction = new QAction(style()->standardIcon(QStyle::SP_MediaSkipBackward), tr("Anterior"), this);
    previousAction->setShortcut(tr("Ctrl+R"));
    previousAction->setDisabled(true);

    addFilesAction = new QAction(tr("&Adicionar Arquivos"), this);
    addFilesAction->setShortcut(tr("Ctrl+F"));

    exitAction = new QAction(tr("&Sair"), this);
    exitAction->setShortcuts(QKeySequence::Quit);

    aboutAction = new QAction(tr("S&obre"), this);
    aboutAction->setShortcut(tr("Ctrl+B"));

    aboutQtAction = new QAction(tr("Sobre &Qt"), this);
    aboutQtAction->setShortcut(tr("Ctrl+Q"));

    rwdAction = new QPushButton(style()->standardIcon(QStyle::SP_MediaSeekBackward),"");
    rwdAction->setShortcut(tr("Ctrl+,"));
    rwdAction->setDisabled(true);
    rwdAction->setAutoRepeat(true);
    rwdAction->setAutoRepeatInterval(1000);
    rwdAction->setAutoRepeatDelay(1000);

    ffAction = new QPushButton(style()->standardIcon(QStyle::SP_MediaSeekForward),"");
    ffAction->setShortcut(tr("Ctrl+."));
    ffAction->setDisabled(true);
    ffAction->setAutoRepeat(true);
    ffAction->setAutoRepeatInterval(1000);
    ffAction->setAutoRepeatDelay(1000);

    clearPlaylistAction = new QAction(style()->standardIcon(QStyle::SP_TrashIcon),tr("Limpar Playlist"), this);
    clearPlaylistAction->setShortcut(tr("Ctrl+Shift+Del"));

    //![5]
    connect(playAction, SIGNAL(triggered()), mediaObject, SLOT(play()));
    connect(pauseAction, SIGNAL(triggered()), mediaObject, SLOT(pause()) );
    connect(stopAction, SIGNAL(triggered()), mediaObject, SLOT(stop()));
    //![5]
    connect(addFilesAction, SIGNAL(triggered()), this, SLOT(addFiles()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    connect(nextAction, SIGNAL(triggered()), this, SLOT(on_nextAction_triggered()));
    connect(previousAction, SIGNAL(triggered()), this, SLOT(on_previousAction_triggered()));
    connect(ffAction,SIGNAL(clicked()),this,SLOT(on_ffAction_triggered()));
    connect(rwdAction,SIGNAL(clicked()),this,SLOT(on_rwdAction_triggered()));
    connect(clearPlaylistAction, SIGNAL(triggered()), this, SLOT(on_clearPlaylistAction_triggered()));
}

void MainWindow::setupMenus()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&Arquivo"));
    fileMenu->addAction(addFilesAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    QMenu *aboutMenu = menuBar()->addMenu(tr("A&juda"));
    aboutMenu->addAction(aboutAction);
    aboutMenu->addAction(aboutQtAction);
}

//![3]
void MainWindow::setupUi()
{
    //![3]
    shufflePushButton = new QPushButton(tr("Aleatório"));
    shufflePushButton->setCheckable(true);

    volumeSpinBox = new QDoubleSpinBox;
    volumeSpinBox->setRange(0,100);
    volumeSpinBox->setSingleStep(1);
    volumeSpinBox->setDecimals(0);
    connect(audioOutput, SIGNAL(volumeChanged(qreal)), this, SLOT(on_audioOutput_volumeChanged(qreal)));
    connect(volumeSpinBox, SIGNAL(valueChanged(double)), SLOT(on_volumeSpinBox_valueChanged(double)));

    QToolBar *bar = new QToolBar;
    bar->addWidget(rwdAction);
    bar->addAction(previousAction);
    bar->addAction(pauseAction);
    bar->addAction(playAction);
    bar->addAction(stopAction);
    bar->addAction(nextAction);
    bar->addWidget(ffAction);
    bar->addAction(clearPlaylistAction);
    bar->addWidget(shufflePushButton);

    //![4]
    seekSlider = new Phonon::SeekSlider(this);
    seekSlider->setMediaObject(mediaObject);
    seekSlider->setPageStep(1000);

    volumeSlider = new Phonon::VolumeSlider(this);
    volumeSlider->setAudioOutput(audioOutput);
    //![4]
    volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    volumeSlider->setPageStep(1);

    QLabel *volumeLabel = new QLabel;
    volumeLabel->setPixmap(QPixmap("images/volume.png"));

    QPalette palette;
    palette.setBrush(QPalette::Light, Qt::darkGray);

    timeLcd = new QLCDNumber;
    timeLcd->setPalette(palette);

    totalTimeLcd = new QLCDNumber;
    totalTimeLcd->setPalette(palette);

    QStringList headers;
    headers << tr("Título") << tr("Artista") << tr("Álbum") << tr("Ano");

    musicTable = new QTableWidget(0, 4);
    musicTable->setHorizontalHeaderLabels(headers);
    musicTable->setSelectionMode(QAbstractItemView::SingleSelection);
    musicTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(musicTable, SIGNAL(cellDoubleClicked(int,int)),
            this, SLOT(tableDoubleClicked(int,int)));

    QHBoxLayout *seekerLayout = new QHBoxLayout;
    seekerLayout->addWidget(timeLcd);
    seekerLayout->addWidget(seekSlider);
    seekerLayout->addWidget(totalTimeLcd);


    QHBoxLayout *playbackLayout = new QHBoxLayout;
    playbackLayout->addWidget(bar);
    playbackLayout->addStretch();
    playbackLayout->addWidget(volumeLabel);
    playbackLayout->addWidget(volumeSlider);
    playbackLayout->addWidget(volumeSpinBox);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(musicTable);
    mainLayout->addLayout(seekerLayout);
    mainLayout->addLayout(playbackLayout);

    QWidget *widget = new QWidget;
    widget->setLayout(mainLayout);

    setCentralWidget(widget);
    setWindowTitle("LinAmp Music Player");
}

/*
 *
 *
 *
 *
 *
 *
 *
 */

//slot
void MainWindow::on_nextAction_triggered()
{
    bool wasPlaying = mediaObject->state() == Phonon::PlayingState;
    mediaObject->clearQueue();
    int proximaMusica;

    if (shufflePushButton->isChecked())
        proximaMusica = qrand() % musicTable->rowCount();
    else
        proximaMusica = musicTable->currentRow() + 1;

    emit tableDoubleClicked(proximaMusica,0);

    if (wasPlaying)
        mediaObject->play();
    else
        mediaObject->stop();
}

//slot
void MainWindow::on_previousAction_triggered()
{
    bool wasPlaying = mediaObject->state() == Phonon::PlayingState;
    mediaObject->clearQueue();
    int proximaMusica;

    if (shufflePushButton->isChecked())
        proximaMusica = qrand() % musicTable->rowCount();
    else
        proximaMusica = musicTable->currentRow() - 1;

    emit tableDoubleClicked(proximaMusica,0);

    if (wasPlaying)
        mediaObject->play();
    else
        mediaObject->stop();
}

//slot
void MainWindow::on_audioOutput_volumeChanged(qreal value)
{
    volumeSpinBox->setValue(value*100);
}
//slot
void MainWindow::on_volumeSpinBox_valueChanged(double value)
{
    audioOutput->setVolume(value/100);
}

//slot
void MainWindow::on_ffAction_triggered()
{
    if ((mediaObject->totalTime())-(mediaObject->currentTime()) <= 5000)
        mediaObject->seek(mediaObject->totalTime());
    else
        mediaObject->seek((mediaObject->currentTime())+5000);
}
//slot
void MainWindow::on_rwdAction_triggered()
{
    if ((mediaObject->currentTime()) < 5000)
        mediaObject->seek(0);
    else
        mediaObject->seek((mediaObject->currentTime())-5000);
}

//slot
void MainWindow::on_clearPlaylistAction_triggered()
{
    mediaObject->stop();
    mediaObject->clear();
    mediaObject->clearQueue();
    allFiles.clear();
    musicTable->clearContents();
    musicTable->setRowCount(0);
}

//reescrita da close event
void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings("Camundongo SofterHouse", "LinAmp");
    settings.setValue("playlist",allFiles);
    settings.setValue("volume",audioOutput->volume());
    settings.setValue("musica",musicTable->currentRow());
    settings.setValue("shuffle", shufflePushButton->isChecked());
    event->accept();
}

void MainWindow::readSettings()
{
    QSettings settings("Camundongo SofterHouse", "LinAmp");
    if (settings.contains("volume"))
    {
        volumeSpinBox->setValue(settings.value("volume").toDouble()*100);
        shufflePushButton->setChecked(settings.value("shuffle").toBool());

        if (!settings.value("playlist").toStringList().isEmpty())
        {
            allFiles = settings.value("playlist").toStringList();
            int lastSong = settings.value("musica").toInt();
            emit addFiles(allFiles);
            emit sourceChanged(sources.at(lastSong));
            emit mediaObject->setCurrentSource(sources.at(lastSong));
            mediaObject->stop();
        }
    }
    else
        volumeSpinBox->setValue(100);
}

void MainWindow::addFiles(const QStringList &files)
{

    if (files.isEmpty())
        return;

    int index = sources.size();
    foreach (QString string, files) {
        Phonon::MediaSource source(string);

        sources.append(source);
    }
    if (!sources.isEmpty())
        metaInformationResolver->setCurrentSource(sources.at(index));
}
