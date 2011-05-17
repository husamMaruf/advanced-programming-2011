#pragma once

class Subject;

class Observer {
public:
	virtual			~Observer();
    virtual void	Update(Subject* ChngSubject) = 0;

	void setChanged();
	void clearChanged();
	bool isChanged() const;

protected:
	Observer();
	Subject* sbj;

	bool changed;
};
