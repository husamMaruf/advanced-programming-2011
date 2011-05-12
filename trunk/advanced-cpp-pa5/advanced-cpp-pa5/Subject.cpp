#include "Subject.h"
#include "Observer.h"

void Subject::Attach (Observer* ob) { 
	m_observers.push_back(ob); 
} 

void Subject ::Detach (Observer* ob) { 
	int i=0; 
	for (i = 0; i < m_observers.size(); i++) 
		if (m_observers[i] == ob) break; 
	m_observers.erase(m_observers.begin() + i); 
} 


void Subject ::Notify () { 
	for (int i = 0; i < m_observers.size(); i++) 
		(m_observers[i])->Update(this); 
}

void main() {

}