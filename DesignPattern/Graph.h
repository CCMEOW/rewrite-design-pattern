#ifndef _GRAPH_H_
#define _GRAPH_H_

class Graph{
public:
	virtual void display() = 0;
	virtual int getId() const = 0;
protected:
	int id;
};

#endif
