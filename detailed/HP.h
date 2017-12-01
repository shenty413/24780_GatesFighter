#ifndef HP_h
#define HP_h

class HP 
{
protected: 
	int hp_left, hp_right;
public:
	int GetHP_left(void) const; 
	int GetHP_right(void) const;
	void SetHP_left(int hp); 
	void SetHP_right(int hp);
};
#endif
