#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <phonon/audiooutput.h>
#include <phonon/seekslider.h>
#include <phonon/mediaobject.h>
#include <phonon/volumeslider.h>
#include <phonon/backendcapabilities.h>
#include <QList>

QT_BEGIN_NAMESPACE
class QAction;
class QTableWidget;
class QLCDNumber;
class QStringList;
class QDoubleSpinBox;
class QPushButton;
QT_END_NAMESPACE

//![0]

class MainWindow : public QMainWindow
{
    //![0]
    Q_OBJECT

public:
    MainWindow();

    QSize sizeHint() const {
        return QSize(800, 600);
    }

private slots:
    void addFiles();
    void about();
    //![1]
    void stateChanged(Phonon::State newState, Phonon::State oldState);
    void tick(qint64 time);
    void sourceChanged(const Phonon::MediaSource &source);
    void metaStateChanged(Phonon::State newState, Phonon::State oldState);
    void aboutToFinish();
    void tableDoubleClicked(int row, int column); //reescrito pra aceitar somente duplo clique
    //![1]

    /*slots criados*/
    void on_nextAction_triggered();
    void on_previousAction_triggered();
    void on_audioOutput_volumeChanged(qreal);
    void on_volumeSpinBox_valueChanged(double);
    void on_ffAction_triggered();
    void on_rwdAction_triggered();
    void on_clearPlaylistAction_triggered();
    void addFiles(const QStringList&);

private:
    void setupActions();
    void setupMenus();
    void setupUi();    

    /*Métodos privados*/
    void readSettings();		//Restaura as configurações quando o programa é iniciado

    //![2]
    Phonon::SeekSlider *seekSlider;
    Phonon::MediaObject *mediaObject;
    Phonon::MediaObject *metaInformationResolver;
    Phonon::AudioOutput *audioOutput;
    Phonon::VolumeSlider *volumeSlider;
    QList<Phonon::MediaSource> sources;
    //![2]

    QAction *playAction;
    QAction *pauseAction;
    QAction *stopAction;
    QAction *nextAction;
    QAction *previousAction;
    QAction *addFilesAction;
    QAction *exitAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
    QLCDNumber *timeLcd;
    QTableWidget *musicTable;

    /*actions criadas*/
    QPushButton *rwdAction;				//Avancar
    QPushButton *ffAction;				//Retroceder
    QAction *clearPlaylistAction;	//Limpar Playlist
    QPushButton *shufflePushButton;		//Modo Aleatório

    QStringList allFiles;			//Armazena todas as músicas para poderem ser salvas
    QDoubleSpinBox *volumeSpinBox;	//SpinBox do volume
    QLCDNumber *totalTimeLcd;		//LCD com o tempo total da musica

protected:
    /*Reescrita do Close Event*/
    void closeEvent(QCloseEvent *event);
};

#endif
