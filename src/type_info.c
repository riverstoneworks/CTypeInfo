/*
 * type_info.c
 *
 *  Created on: Jul 24, 2018
 *      Author: Like.Z
 */
#include "CTypeInfo/type_info.h"

//fetch sub object
const ObjectInfo* fetchSub(ObjectInfo* obj, char* name){
	int i=0,list_size=obj->typeInf->size[1];

	while(list_size>i&&strcmp(name,obj->typeInf->subObjInfo[i].name))++i;

	return i<list_size?obj->typeInf->subObjInfo+i:NULL;
}
//get the number of sub objects
size_t getSubNum(TypeInf* typeInf){
	return typeInf->size[1];
}

size_t getSize(TypeInf* typeInf){
	return typeInf->size[0];
}

const TypeInf T_INF_INT8={
		.name="int8",
		.type=INT8,
		.size={sizeof(char)},
		.subObjInfo=(void*)(0)
};

const TypeInf T_INF_UINT8={
		.name="uint8",
		.type=UINT8,
		.size={sizeof(char)},
		.subObjInfo=(void*)(0)
};

const TypeInf T_INF_INT16={
		.name="int16",
		.type=INT16,
		.size={sizeof(short)},
		.subObjInfo=(void*)(0)
};

const TypeInf T_INF_UINT16={
		.name="uint16",
		.type=UINT16,
		.size={sizeof(short)},
		.subObjInfo=(void*)(0)
};

const TypeInf T_INF_INT32={
		.name="int32",
		.type=INT32,
		.size={sizeof(int)},
		.subObjInfo=(void*)(0)
};

const TypeInf T_INF_UINT32={
		.name="uint32",
		.type=UINT32,
		.size={sizeof(int)},
		.subObjInfo=(void*)(0)
};

const TypeInf T_INF_UINT64={
		.name="uint64",
		.type=UINT64,
		.size={sizeof(long long)},
		.subObjInfo=(void*)(0)
};

const TypeInf T_INF_INT64={
		.name="int64",
		.type=INT64,
		.size={sizeof(long long)},
		.subObjInfo=(void*)(0)
};

const TypeInf T_INF_FLOAT={
		.name="float",
		.type=FLOAT,
		.size={sizeof(float)},
		.subObjInfo=(void*)(0)
};

const TypeInf T_INF_DOUBLE={
		.name="double",
		.type=DOUBLE,
		.size={sizeof(double)},
		.subObjInfo=(void*)(0)
};

const TypeInf T_INF_LDOUBLE={
		.name="long double",
		.type=LDOUBLE,
		.size={sizeof(long double)},
		.subObjInfo=(void*)(0)
};

const TypeInf T_INF_BOOLEAN={
		.name="boolean",
		.type=BOOLEAN,
		.size={sizeof(bool)},
		.subObjInfo=(void*)(0)
};

const TypeInf T_INF_ACHAR={
		.name="ascii char",
		.type=ACHAR,
		.size={sizeof(char)},
		.subObjInfo=(void*)(0)
};
