#pragma once
#include "Bees.h"

class Builder : Bees {
public:
	Builder(Hive* hive);
	~Builder();
	void eat_akt();
	void die();
	void build();
	void build_soty();
}