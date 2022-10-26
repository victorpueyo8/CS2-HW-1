#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cust
{
private:
	string ID;
	string custName;
	Cust* related;
public:
	Cust()
	{
		ID = " ";
		custName = " ";
		related = nullptr;
	}
	Cust(string id, string name)
	{
		ID = id;
		custName = name;
		related = nullptr;
	}
	void setId(string id)
	{
		ID = id;
	}
	void setcustName(string name)
	{
		custName = name;
	}
	void setRelated(Cust* ptrrelated)
	{
		related = ptrrelated;
	}

	void setRelated(Cust &relatedCust)
	{
		// Set the address of the customer of relatedCust
		this->related = &relatedCust;
		relatedCust.related = this;
	}

	string getId() const
	{
		return ID;
	}
	string getcustName() const
	{
		return custName;
	}
	Cust* getRelated() const
	{
		return related;
	}

};

