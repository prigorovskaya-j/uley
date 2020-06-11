#pragma once
#include "Bees.h"

class Builder : public Bees {
public:
	Builder(Hive* hive);
	~Builder();
	void eat_akt();
	void die();
	void build();
	void buildHoneycombs();
}