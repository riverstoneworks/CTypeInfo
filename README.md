# **CTypeInfo Reference Manual** 
## I. Purpose
C language data type description is designed to access the object's properties in a uniform way without object's id. So that app can unify access to different objects with different data structures. *[Here's an application with it.][1]*
## II. TypeInf & ObjectInfo
   1. *TypeInf* describes C data type infomation and *ObjectInfo* describes C object information. They are struct with the following relationships:
      > ![class diagram](https://raw.github.com/riverstoneworks/CTypeInfo/master/doc/TypeInf_ObjectInfo.svg?sanitize=true)
       
      *ObjectInfo* :
   
      Attribute |Type|Note
      :--:|:--:|:--:
      name | char* | object name 
      typeInfo | TypeInf* | pointer to the TypeInf of the object type
      offset | long | The offset relative to the parent object's starting address or memory address without parent

      *TypeInf* :

      Attribute |Type|Note
      :--:|:--:|:--:
      name | char* | type name 
      type | int | type enums 
      subObject | subObject* | pointer to the subObject array 
      size | long[2] | long[0]: size of the type; long[1]: number of subobjects
   2. Type enums
      > STRING,	ARRAY,	OBJECT,	BOOLEAN, ACHAR,	INT8,INT16,NT32,INT64,	FLOAT,	DOUBLE,	LDOUBLE,	UINT8,	UINT16,	UINT32,	UINT64,	PTR
   3. For example:
      ```C
      // type A
      struct A {
		int  age;
		char title[20];
      }a;

      //description of type A
	  static const TypeInf T_INF_A=(TypeInf){
		  .name="struct A",
		  .type=OBJECT,
		  .size={24,2},
		  .subObjInfo=(ObjectInfo*)&(ObjectInfo){
			  {
				  .name="age",
				  .typeInf=TYPE_INF_INT,
				  .offset=0
			  },{
				  .name="title",
				  .typeInf={
					  .name="char20",
					  .type=STRING,
					  .size={20,20},
					  .subObjInfo=NULL
				  },
				  .offset=(void*)4
			  }
		  }
	  }

      //description of A a
	  ObjectInfo a_inf={
		  .name="a",
		  .typeInfo=&T_INF_A,
		  .offset=(void*)&a
	  }
	  ```

## III. Predefined type descriptions
There is a set of predefined type decriptions for base data types.
```C
const TypeInf T_INF_INT8;
const TypeInf T_INF_UINT8;
const TypeInf T_INF_INT16;
const TypeInf T_INF_UINT16;
const TypeInf T_INF_INT32;
const TypeInf T_INF_UINT32;
const TypeInf T_INF_INT64;
const TypeInf T_INF_UINT64;
const TypeInf T_INF_FLOAT;
const TypeInf T_INF_DOUBLE;
const TypeInf T_INF_LDOUBLE;
const TypeInf T_INF_BOOLEAN;
const TypeInf T_INF_ACHAR;
```
## IV. Predefined macro
There is a set of predefined macro to simplify coding.
```C
/*
* Struct Type
* na: type name
* attr_num: subobject number
*/
#define	T(na,attr_num,...)
/*
* Array type
* el_ty_na: element type name 
* el_type: element type decription
*/
#define T_ARRAY(el_ty_na,el_num,el_type)
//String type
#define T_STRING(length)
/*pointer type to object
* na: type name
* ty: the type decription of object that is pointed to
*/
#define	T_PTR_OBJ(na,ty)
/*pointer type to string
* na: type name
* len: string length
*/
#define	T_PTR_STR(na,len) 
/*pointer type to array
* na: type name
* el_ty_na: element type name
* el_num: element number
* el_type: element type decription
*/
#define	T_PTR_ARRAY(na,el_ty_na,el_num,el_type)

/*ObjectInfo
* na : name 
* ty : type decription
* offs: offset relative to the parent object's starting address or memory address without parent
*/
#define O(na,ty,offs)
//string object info
#define O_STR(na,len,offs)
/*array object info
* na : array name 
* el_ty_na: element type name
* el_num: element number
* el_ty : type decription
* offs: offset relative to the array starting address
*/
#define O_ARRAY(na,el_ty_na,el_num,el_type,offs)
/*pointer
* na : pointer name 
* ty: type decription
* offs: offset
*/
#define O_PTR_OBJ(na,ty,offs)
//pointer to string
#define O_PTR_STR(na,len,offs) 
/*pointer to array
* na : pointer name 
* el_ty_na: element type name
* el_num: element number
* el_type: element type decription
* offs: offset
*/
#define O_PTR_ARRAY(na,el_ty_na,el_num,el_type,offs)

//8 bit int
#define O_INT8(na,offs)
#define O_ARRAY_INT8(na,el_num,offs)
//8 bit usigned int
#define O_UINT8(na,offs)
#define O_ARRAY_UINT8(na,el_num,offs)

#define O_INT16(na,offs)
#define O_ARRAY_INT16(na,el_num,offs)

#define O_UINT16(na,offs) 
#define O_ARRAY_UINT16(na,el_num,offs)

#define O_INT32(na,offs)
#define O_ARRAY_INT32(na,el_num,offs)

#define O_UINT32(na,offs) 
#define O_ARRAY_UINT32(na,el_num,offs)

#define O_INT64(na,offs) 
#define O_ARRAY_INT64(na,el_num,offs) 

#define O_UINT64(na,offs)
#define O_ARRAY_UINT64(na,el_num,offs)

#define O_FLOAT(na,offs)
#define O_ARRAY_FLOAT(na,el_num,offs)

#define O_DOUBLE(na,offs) 
#define O_ARRAY_DOUBLE(na,el_num,offs)

//long double
#define O_LDOUBLE(na,offs)
#define O_ARRAY_LDOUBLE(na,el_num,offs)

//boolean
#define O_BOOLEAN(na,offs)
#define O_ARRAY_BOOLEAN(na,el_num,offs)

//char
#define O_ACHAR(na,offs)
#define O_ARRAY_ACHAR(na,el_num,offs)
```
[1]:https://github.com/riverstoneworks/JsonCObject
