#ifndef _INSTRUMENTO_H_
#define _INSTRUMENTO_H_

template < typename Musica>
class Instrumento
{
public:
	virtual play() = 0;
	virtual playMusica(const Musica&);
	virtual ajusta() = 0;
	virtual verifica() = 0;
	virtual afina() = 0;
	virtual ~Instrumento();
};
template < typename Musica>
class InstSopro : public Instrumento
{
	virtual play() = 0;
	virtual playMusica(const Musica&);
	virtual ajusta() = 0;
	virtual verifica() = 0;
	virtual afina() = 0;
	virtual ~Instrumento();
}
template < typename Musica>
class InstSopro : public Instrumento
{
	virtual play() = 0;
	virtual playMusica(const Musica&);
	virtual ajusta() = 0;
	virtual verifica() = 0;
	virtual afina() = 0;
	virtual ~Instrumento();
}


#endif
