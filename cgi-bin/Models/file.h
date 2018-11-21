#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <dirent.h>

#include "storable.h"

class File : public Storable {
	public:
		File(const std::string& name, std::string& address);
};

#endif


