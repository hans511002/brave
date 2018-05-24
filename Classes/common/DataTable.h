// ==============================================================
//progame      Common::DataTable  DataTable table mapping
//company      hans
//copyright    Copyright (c) hans  2007-4     2008-03
//version      1.0
//Author       hans
//date         2007-4     2008-03
//description  Common namespace
//				This library is free software. Permission to use, copy,
//				modify and redistribute it for any purpose is hereby granted
//				without fee, provided that the above copyright notice appear
//				in all copies.
// ==============================================================

#ifndef __Common_DataTable_H__
#define __Common_DataTable_H__
#include "Common.h"
namespace Common
{
/*
otl_var_char	1	null terminated string
otl_var_double	2	8-byte floating point number
otl_var_float	3	4-byte floating point number
otl_var_int	4	signed 32-bit? integer  32
otl_var_unsigned_int	5	unsigned? 32-bit integer 32
otl_var_short	6	signed 16-bit integer    16
otl_var_long_int	7	signed 32-bit integer  
otl_var_timestamp	8	datatype that is mapped into TIMESTAMP_STRUCT, ODBC and DB2-CLI only
otl_var_varchar_long	9	datatype that is mapped into LONG in Oracle 7/8, TEXT in MS SQL Server and Sybase, CLOB in DB2
otl_var_raw_long	10	datatype that is mapped into LONG RAW in Oracle 7/8, IMAGE in MS SQL Server ad Sybase, BLOB in DB2
otl_var_clob	11	datatype that is mapped into CLOB in Oracle 8
otl_var_blob	12	datatype that is mapped into BLOB in Oracle 8
otl_var_db2time	16	DB2 TIME type
otl_var_db2date 	17	DB2 DATE type
otl_var_tz_timestamp	18	Oracle 9i/10g TIMESTAMP WITH TIME ZONE type
otl_var_ltz_timestamp	19	Oracle 9i/10g TIMESTAMP WITH LOCAL TIME ZONE type
otl_var_bigint	20	MS SQL Server, DB2, MySQL, PostgreSQL, etc. BIGINT (signed 64-bit integer) type
otl_var_raw	23	RAW, BINARY, VARBINARY, BYTEA, VARCHAR BYTE, CHAR BYTE, etc.

*/


	//
	//
	//摘要：
	//	导出表数据到对应类型的结构数组中,只能存储 20亿 大小记录数 2147483647
	//	不同类型存储.要柝构释放内存空间
    // 作 者: 邹远贵
    // 日 期: 2007-5-21
    // 版 本: 1.0
	//
	class DataTable 
	{
		Array<string> KeysStr;
		Array<int> KeysIndex;
		map<string,int> valueIndexMap;
		char p[40];
		int setIndexSeq;
		int allRowCount;
	public:
		Log *log;
		string nullDate;
		static String dbStr;
		static bool stringObject;
		String keySplit;
		int printUnit;
		int RowCount;
		int ColCount;
		Array<ColumnInfo> Columns;
		Array<unsigned char *> Data;
#ifndef USE_SEPARATE_STORAGE_POINT
		bool useMaxLen;
#endif

#if defined(__Common_ResultSet__) 
		//
		//摘要：
		//	参数类型
		//
//添加基本方法//
	protected:
		void _init()
		{
			this->nullDate="1900-01-01 00:00:00";
			this->keySplit="\1\2\1";
			this->printUnit=200000;
			this->RowCount=-1;
			this->ColCount=-1;
			this->allRowCount=-1;
			this->KeysStr.clear();
			this->KeysIndex.clear();
			this->valueIndexMap.clear();
			this->Columns.clear();
			this->Data.clear();
#ifndef USE_SEPARATE_STORAGE_POINT
			useMaxLen=false;
#endif
		};
	public:
		//bool setKeys(String key1,int num=1,...); 		//不支持64编译
		//bool setKeys(int key1,...);					//不支持64编译
		//添加设置key
		DataTable()
		{
			_init();
			this->log=NULL;
		}
		~DataTable()
		{
			clear();
		}
		bool setKey(string key)
		{
			this->KeysStr.clear();
			this->KeysIndex.clear();
			this->KeysStr[0]=key;
			return true;
		}
		bool setKeys(Array<string> &keys)
		{
			this->KeysStr.clear();
			this->KeysIndex.clear();
			this->KeysStr=keys;
			return true;
		}
		bool addKey(string key)
		{
			if(this->KeysStr.size()==0)
			{
				return setKey(key);
			}
			else
			{
				this->KeysStr[this->KeysStr.size()]=key;
				return true;
			}
		}
		bool addKeys(Array<string> &keys)
		{
			if(this->KeysStr.size()==0)
			{
				return setKeys(keys);
			}
			else
			{
				int len=this->KeysStr.size();
				for(int i=keys.size()-1;i>=0;i--)
				{
					this->KeysStr[len+i]=keys[i];
				}
				return true;
			}
		}
		bool setKey(int index)
		{
			this->KeysStr.clear();
			this->KeysIndex.clear();
			this->KeysIndex[0]=index;
			return true;
		}
		bool setKeys(Array<int> &indexs)
		{
			this->KeysStr.clear();
			this->KeysIndex.clear();
			this->KeysIndex=indexs;
			return true;
		}
		bool addKey(int index)
		{
			if(this->KeysIndex.size()==0)
			{
				return setKey(index);
			}
			else 
			{
				this->KeysIndex[this->KeysIndex.size()]=index;
				return true;
			}
		}
		bool addKeys(Array<int> &indexs)
		{
			if(this->KeysIndex.size()==0)
			{
				return setKeys(indexs);
			}
			else
			{
				int len=this->KeysIndex.size();
				for(int i=indexs.size()-1;i>=0;i--)
				{
					this->KeysIndex[len+i]=indexs[i];
				}
				return true;
			}
		}


		//清除key
		void clearKeys(){KeysStr.clear();KeysIndex.clear();};
		void clear(bool all=true)
		{
			if(this->RowCount>0)
			{
				for(int i=0;i<this->ColCount;i++)
				{
					switch(this->Columns[i].otl_var_dbtype)
					{
					case otl_var_char:
					{
						if(stringObject)
						{
							string * temp=(string *)Data[i]; //对象存储
							delete[] temp; 
						}
						else
						{
	#if defined(USE_SEPARATE_STORAGE_POINT)
							unsigned char * temp=(unsigned char *)Data[i];   //按字节存储
							delete[] temp;
	#else
							char ** temp=(char **)Data[i];
							for(int index=0;index<this->allRowCount;index++)
							{
								char * temp1=temp[index];
								if(temp1)delete[] temp1;
							}
							delete[] temp;
	#endif
						}
						break;
					}
					case otl_var_raw:
					{
						string * temp=(string *)Data[i]; //对象存储
						delete[] temp;
						break;
					}
					case otl_var_int:
					{
						int * temp=(int *)Data[i];
						delete[] temp;
						break;
					}
					case otl_var_unsigned_int:
					{
						unsigned int * temp=(unsigned int *)Data[i];delete[] temp;
						break;
					}
					case otl_var_long_int:
					{
						long int * temp=(long int *)Data[i];delete[] temp;
						break;
					}
					case otl_var_short:
					{
						short int * temp=(short int *)Data[i];delete[] temp;
						break;
					}
					case otl_var_float:
					{
						float * temp=(float *)Data[i];delete[] temp;
						break;
					}
					case otl_var_double:
					{
						double * temp=(double *)Data[i];delete[] temp;
						break;
					}
					case otl_var_timestamp:
					{
						DateTime * temp=(DateTime *)Data[i];delete[] temp;
						break;
					}
					case otl_var_bigint:
					{
							long long * temp=(long long *)Data[i];delete[] temp;
							break;
						}
					}
				}
			}
			this->RowCount=-1;
			this->ColCount=-1;
			this->allRowCount=-1;
			this->valueIndexMap.clear();
			this->Columns.clear();
			this->Data.clear();
			if(all)_init();
		}
		//
		//摘要：
        //  填充表格数据
		bool Fill(String sql,String connStr=dbStr,int preFetch=5000,int maxCount=-1)
		{
			if(connStr.empty() || connStr.Trim()=="")
			{
				cout<<"数据库连接字符串为空"<<endl;
				return false;
			}
			this->clear(false);
			this->RowCount=maxCount;
			this->allRowCount=maxCount;
			bool result=false;
			String temp="select count(1) rc from ("+sql+") a ";
			Connection con;
			ResultSet rs;
			try
			{
				Connection::otl_initialize();
				con.rlogon(connStr.c_str()); // connect to Oracle
				rs.open(preFetch,sql.c_str(),con);
				otl_column_desc* desc;
				desc=rs.describe_select(this->ColCount);
				this->Columns[this->ColCount-1]=ColumnInfo();
				
				for(int n=0;n<this->ColCount;n++)
				{
					this->Columns[n].name=desc[n].name;
					this->Columns[n].otl_var_dbtype=desc[n].otl_var_dbtype;
					this->Columns[n].dbtype=desc[n].dbtype;
					this->Columns[n].dbsize=desc[n].dbsize;
					this->Columns[n].scale=desc[n].scale;
					this->Columns[n].prec=desc[n].prec;
					this->Columns[n].nullok=desc[n].nullok;
	#if defined(OTL_ORA7) ||  defined(OTL_ORA8)
					if(this->Columns[n].dbtype==inNumber)
					{
						if(this->Columns[n].prec>0 && this->Columns[n].scale<=0)
						{
							if(this->Columns[n].prec<10)
							{
								this->Columns[n].otl_var_dbtype=otl_var_int;
								this->Columns[n].dbsize=sizeof(int);
							}
							else
							{
								this->Columns[n].otl_var_dbtype=otl_var_bigint;
								this->Columns[n].dbsize=sizeof(long long);
							}
						}
						else
						{
							this->Columns[n].otl_var_dbtype=otl_var_double;
							this->Columns[n].dbsize=sizeof(double);
						}
					}
	#endif
					switch(this->Columns[n].otl_var_dbtype)
					{
						case 21:
						case otl_var_varchar_long: 
						case otl_var_raw_long:
						case otl_var_raw:
						case otl_var_clob:
						case 22:
						case otl_var_blob:
							this->Columns[n].otl_var_dbtype=otl_var_char;
							this->Columns[n].dbsize=blog_buffer_size;
							break;
						case otl_var_db2time:
						case otl_var_db2date:
						case otl_var_tz_timestamp:
						case otl_var_ltz_timestamp:
						case otl_var_timestamp:
							this->Columns[n].otl_var_dbtype=otl_var_timestamp;
							this->Columns[n].dbsize=sizeof(DateTime);
							break;
					}
					this->Columns[n].typeName=otl_var_type_name(this->Columns[n].otl_var_dbtype);
					if(this->Columns[n].otl_var_dbtype==otl_var_char)
					{
						this->Columns[n].dbsize+=1;
					}
					if(KeysStr.size()>0)//string	key
					{
						for(int j=0;j<KeysStr.size();j++)
						{
							if(this->Columns[n].name==KeysStr[j])
							{
								KeysIndex[j]=n;
								break;
							}
						}
					}
				}
				if(KeysStr.size()==0 && KeysIndex.size()>0)		//int
				{
					for(int j=0;j<KeysIndex.size();j++)
					{
						KeysStr[j]=this->Columns[KeysIndex[j]].name;
						break;
					}
				}
				if(this->RowCount==-1)
				{
					String temp="select count(1) rc from ("+sql+") a ";
					cout<<"获取记录数: "<<temp<<endl;
					ResultSet is;
					is.open(1,temp.c_str(),con); // 先查询记录数
					if(!is.eof())is>>this->RowCount;
					this->allRowCount=this->RowCount;
					is.close();
				}
				if(this->RowCount==0 || this->RowCount==0)
				{
					rs.close();
					con.logoff();
					return true;
				}

				this->Data.resize(this->ColCount);
				for(int i=0;i<this->ColCount;i++)
				{
					switch(this->Columns[i].otl_var_dbtype)
					{
					case otl_var_char:
						{
							if(stringObject)
								Data[i]=(unsigned char *)(new string[this->allRowCount]);      //对象存储
							else 
							{
	#if defined(USE_SEPARATE_STORAGE_POINT)
								Data[i]=new unsigned char[this->allRowCount*(this->Columns[i].dbsize)];     //按字节存储
	#else
								char * * tcp=(new char *[this->allRowCount]);     //按字节存储
								Data[i]=(unsigned char *)tcp;
								for(int index=0;index<this->allRowCount;index++)
									tcp[index]=NULL;

	#endif
							}
							break;
						}
					case 21://otl_var_nchar
					case otl_var_varchar_long: 
					case otl_var_raw_long:
					case otl_var_clob:
					case 22://otl_var_nclob
					case otl_var_blob:
					case otl_var_raw:
						{
							this->Columns[i].otl_var_dbtype=otl_var_raw;
							Data[i]=(unsigned char *)(new string[this->allRowCount]);
							break;
						}
					case otl_var_int:
						{
							Data[i]=(unsigned char *)(new int[this->allRowCount]);
							break;
						}
					case otl_var_unsigned_int:
						{
							Data[i]=(unsigned char *)(new unsigned int[this->allRowCount]);
							break;
						}
					case otl_var_long_int:
						{
							Data[i]=(unsigned char *)(new long int[this->allRowCount]);
							break;
						}
					case otl_var_short:
						{
							Data[i]=(unsigned char *)(new short int[this->allRowCount]);
							break;
						}
					case otl_var_float:
						{
							Data[i]=(unsigned char *)(new float [this->allRowCount]);
							break;
						}
					case otl_var_double:
						{
							Data[i]=(unsigned char *)(new double [this->allRowCount]);
							break;
						}
					case otl_var_db2time:
					case otl_var_db2date:
					case otl_var_tz_timestamp:
					case otl_var_ltz_timestamp:
					case otl_var_timestamp:
						{
							this->Columns[i].otl_var_dbtype=otl_var_timestamp;
							Data[i]=(unsigned char *)(new DateTime[this->allRowCount]);
							break;
						}
					case otl_var_bigint:
						{
							Data[i]=(unsigned char *)(new long long[this->allRowCount]);
							break;
						}
					}
					if(!Data[i])EXP("内存空间申请失败!")
				}
				int rowIndex=0;
				string key;
				if(log)
					log->writeLog(DateTime::Now().ToString()+"    "+String(rowIndex)+"  rows processed",log->AppCategory,1);
				else
					cout<< DateTime::Now().ToString() <<"    "<< rowIndex <<"  rows processed"<< endl ;
				 otl_select_stream *ss=*(rs.ss);
				while(rs.next())
				{
					if(rowIndex>=this->allRowCount)
					{
						EXP(String("当前设置的最大数据存储长度不够:")+this->allRowCount);
					}
					if(KeysIndex.size()>0)
					{
						for(int n=0;n<KeysIndex.size();n++)
						{
							if(n==0)
							{
								rs.get(key,KeysIndex[0]);
							}
							else
							{
								key+=keySplit+rs.getStr(KeysIndex[n]);
							}
						}
						valueIndexMap[key]=rowIndex;
					}
					for(int col=0;col<this->ColCount;col++)
					{
						switch(this->Columns[col].otl_var_dbtype)
						{
						case otl_var_char:			//分类处理
							{
								if(stringObject) 
									((string *) Data[col])[rowIndex]=rs.getChars(col); //对象存储                                    
								else 
								{
#if defined(USE_SEPARATE_STORAGE_POINT)
									strcpy((((char * )Data[col])+rowIndex*(this->Columns[col].dbsize)),rs.getChars(col));//按字节存储                                    
#else
									if(useMaxLen)
										((char **)Data[col])[rowIndex]=new char[this->Columns[col].dbsize];
									else
										((char **)Data[col])[rowIndex]=new char[rs.getLen(col)+1];
									strcpy(((char **)Data[col])[rowIndex],rs.getChars(col));//按字节存储                                    
#endif
								}
								break;
							}
						case 21:
						case otl_var_varchar_long: 
						case otl_var_raw_long:
						case otl_var_raw:
						case otl_var_clob:
						case 22:
						case otl_var_blob:
							{
								((string *) Data[col])[rowIndex]=rs.getChars(col);
								break;
							}
						case otl_var_int:
							{
								((int *) Data[col])[rowIndex]=rs.getInt(col);
								break;
							}
						case otl_var_unsigned_int:
							{
								((unsigned *) Data[col])[rowIndex]=rs.getUnsigned(col);
								break;
							}
						case otl_var_long_int:
							{
								((long *) Data[col])[rowIndex]=rs.getLong(col);
								break;
							}
						case otl_var_short:
							{
								((short *) Data[col])[rowIndex]=rs.getShort(col);
								break;
							}
						case otl_var_float:
							{
								((float *) Data[col])[rowIndex]=rs.getFloat(col);
								break;
							}
						case otl_var_double:
							{
								((double *) Data[col])[rowIndex]=rs.getDouble(col);
								break;
							}
						case otl_var_db2time:
						case otl_var_db2date:
						case otl_var_tz_timestamp:
						case otl_var_ltz_timestamp:
						case otl_var_timestamp:
							{
								rs.get(((DateTime *) Data[col])[rowIndex],col);
								break;
							}
						case otl_var_bigint:
							{
								((long long *) Data[col])[rowIndex]=rs.getLLong(col);
								break;
							}
						}
					}
					rowIndex++;
					if(rowIndex % printUnit==0)
						if(log)
							log->writeLog(DateTime::Now().ToString()+"    "+String(rowIndex)+"  rows processed",log->AppCategory,1);
						else
							cout<< DateTime::Now().ToString() <<"    "<< rowIndex <<"  rows processed"<< endl ;
				}
				if(log)
					log->writeLog(DateTime::Now().ToString()+"    "+String(rowIndex)+"  rows processed\tEnd load",log->AppCategory,1);
				else
					cout<< DateTime::Now().ToString() <<"    "<< rowIndex <<"  rows processed\tEnd load"<< endl ;
				rs.close();
				con.logoff();
				this->RowCount=rowIndex;
				result= true;
			}
			catch( otl_exception& p)
			{
				rs.close();
				con.logoff();
				EXP(String("查询数据填充TableMap: ")+String(p.stm_text)+string("\t\t")+(char *)p.msg+"\tvar_info:"+(char *)p.var_info);
			}
			catch(Exception &ex)
			{
				rs.close();
				con.logoff();
				throw ex;
			}
			return result;
		}
        //
		//摘要：
        //  获取列名称		
		const string & getColName(int index)
		{
			return this->Columns[index].name;
		}
		string &getColTypeName(int index)
		{
			return this->Columns[index].typeName;
		}
        //
		//摘要：
        //  获取列数组数据
		void getColAsDbl(Array<double> &result,int col)
		{
			result[this->RowCount-1]=0;
			for(int i=0;i<this->RowCount;i++)
			{
				result[i]=getDouble(i,col);
			}
		}
		void getColAsInt(Array<int>  &result,int col)
		{
			result[this->RowCount-1]=0;
			for(int i=0;i<this->RowCount;i++)
			{
				result[i]=getInt(i,col);
			}
		}
		void getColAsString(Array<string> &result,int col)
		{
			result[this->RowCount-1]="";
			for(int i=0;i<this->RowCount;i++)
			{
				result[i]=getStr(i,col);
			}
		}

		int getRowIndexByKey(string key)
		{
			if(KeysIndex.size()==0)
				EXP("未设定关键字列,不能使用MAP查询.");
			if(valueIndexMap.find(key)!=valueIndexMap.end())
				return valueIndexMap[key];
			else 
				return -1;
		};
		int getRowIndexByKey(Array<string> &keys)
		{
			if(KeysIndex.size()==0)
				EXP("未设定关键字列,不能使用MAP查询.");
			string key=String::Join(keys,keySplit);
			map<string,int>::iterator pos=valueIndexMap.find(key);
			if(pos!=valueIndexMap.end())
				return pos->second;
			else 
				return -1;
		}; 
//for get for num
#ifndef TABLE_GETSNUM
#define TABLE_GETSNUM(T,T_type)																		\
  		void get(T& n,int i,int j)                                                                  \
		{																							\
			GET_NUM_DATA(T,T_type)																	\
		}
#endif
//for string DateTime  等对象型
#ifndef TABLE_GETSOBJ
#define TABLE_GETSOBJ(T,T_type)                                                                     \
  		void	 get(T& n,int i,int j)                                                              \
		{                                                                                           \
			GET_OBJ_DADA(T,T_type)                                                                  \
		}
#endif

	TABLE_GETSNUM(int,otl_var_int)
	TABLE_GETSNUM(unsigned,otl_var_unsigned_int)
	TABLE_GETSNUM(long,otl_var_long_int)
	TABLE_GETSNUM(short,otl_var_short)
	TABLE_GETSNUM(float,otl_var_float)
	TABLE_GETSNUM(double,otl_var_double)
	TABLE_GETSNUM(long long,otl_var_bigint)
	TABLE_GETSOBJ(DateTime,otl_var_timestamp)
	//TABLE_GETSELF(string,otl_var_raw)			//已经单独写  getStr

   		inline string getStr(int i ,int j)
		{
			return getChars(i,j);
		}
		//
		//摘要：
		//  获取数据
		inline int getInt(int i,int j)
		{
			int result=0;
			this->get(result,i,j);
			return result;
		}
		inline short getShort(int i,int j)
		{
			short result=0;
			this->get(result,i,j);
			return result;
		}
		inline unsigned getUnsigned(int i,int j)
		{
			unsigned result=0;
			this->get(result,i,j);
			return result;
		}
		inline long getLong(int i,int j)
		{
			long result=0;
			this->get(result,i,j);
			return result;
		}
		inline double getDouble(int i,int j)
		{
			double result=0;
			this->get(result,i,j);
			return result;
		}
		inline float  getFloat(int i,int j)
		{
			float result=0;
			this->get(result,i,j);
			return result;
		}
		inline long long  getBigInt(int i,int j)
		{
			long long result=0;
			this->get(result,i,j);
			return result;
		}
		inline long long  getLLong(int i,int j)
		{
			long long result=0;
			this->get(result,i,j);
			return result;
		}

		const char * getChars(int i,int j) 
		{
			switch(this->Columns[j].otl_var_dbtype)
			{
				case otl_var_char:
				{
					if(stringObject) 
						return (((string *) Data[j])[i]).c_str();
					else 
#if defined(USE_SEPARATE_STORAGE_POINT)
						return (char *)( Data[j]+i*(this->Columns[j].dbsize));
#else
						return (char *)(((char **)Data[j])[i]);
#endif
				}
				case otl_var_raw:
				{
					return (((string *) Data[j])[i]).c_str();
				}
				case otl_var_int:
				{
					sprintf(p,"%d",((int *) Data[j])[i]);
					return p;
				}
				case otl_var_unsigned_int:
				{
					sprintf(p,"%d",((unsigned *) Data[j])[i]);
					return p;
				}
				case otl_var_long_int:
				{
					sprintf(p,"%ld",((long int *) Data[j])[i]);
					return p;
				}
				case otl_var_short:
				{
					sprintf(p,"%d",((short int *) Data[j])[i]);
					return p;
				}
				case otl_var_float:
				{
					if(this->Columns[j].prec>0)
					{
						char f[10];
						sprintf(f,"%%.%df",this->Columns[j].scale);
						sprintf(p,f,((float*) Data[j])[i]);
					}
					else
					{
						sprintf(p,"%f",((float*) Data[j])[i]);
					}
					return p;
				}
				case otl_var_double:
				{
					if(this->Columns[j].prec>0)
					{
						char f[10];
						sprintf(f,"%%.%df",this->Columns[j].scale);
						sprintf(p,f,((double*) Data[j])[i]);
					}
					else
					{
						sprintf(p,"%f",((double*) Data[j])[i]);
					}
					return p;
				}
				case otl_var_timestamp:
				{
					DateTime dt=((DateTime *) Data[j])[i];
					if(dt.GetTicks()==0)
					{
						return nullDate.c_str();
					}
					else
					{
						int year,month,day,hour,minute,second,millis;
						dt.GetDateParts(&year,&month,&day,NULL,&hour,&minute,&second,&millis);
						sprintf(p,"%04d-%02d-%02d %0d:%02d:%02d",year,month,day,hour,minute,second);
						return p;
					}
				}
				case otl_var_bigint:
				{
					sprintf(p,"%lld",((long long *) Data[j])[i]);
					return p;
				}
			}
			return "";
		}
		inline DateTime getDate(int i,int j)
		{
			DateTime result;
			this->get(result,i,j);
			return result;
		}

//设置值
#ifndef TABLE_SETSNUM
#define TABLE_SETSNUM(T,T_type)																\
  		inline void set(int i,int j,T n)													\
		{                                                                                   \
			if(T_type==this->Columns[j].otl_var_dbtype)                                     \
			{                                                                               \
				((T *) Data[j])[i]=n;return;												\
			}                                                                               \
			int colType=this->Columns[j].otl_var_dbtype;                                    \
			if(colType==otl_var_int)                                                        \
			{                                                                               \
				((int *) Data[j])[i]=(int)n;                                                \
			}                                                                               \
			else if(colType==otl_var_unsigned_int)                                          \
			{                                                                               \
				((unsigned *) Data[j])[i]=(unsigned)n;                                      \
			}                                                                               \
			else if(colType==otl_var_long_int)                                              \
			{                                                                               \
				((long *) Data[j])[i]=(long)n;                                              \
			}                                                                               \
			else if(colType==otl_var_short)                                                 \
			{                                                                               \
				((short *) Data[j])[i]=(short)n;                                            \
			}                                                                               \
			else if(colType==otl_var_float)                                                 \
			{                                                                               \
				((float *) Data[j])[i]=(float)n;                                            \
			}                                                                               \
			else if(colType==otl_var_double)                                                \
			{                                                                               \
				((double *) Data[j])[i]=(double)n;                                          \
			}                                                                               \
			else if(colType==otl_var_bigint)                                                \
			{                                                                               \
				((long long *) Data[j])[i]=(long long)n;                                    \
			}                                                                               \
			else                                                                            \
			{                                                                               \
				EXP("字段:"+this->Columns[j].name+"类型为"+this->Columns[j].typeName+       \
					",不是"+otl_var_type_name(T_type));                                     \
			}                                                                               \
		}

#endif
		TABLE_SETSNUM(int,otl_var_int)
		TABLE_SETSNUM(unsigned,otl_var_unsigned_int)
		TABLE_SETSNUM(long,otl_var_long_int)
		TABLE_SETSNUM(short,otl_var_short)
		TABLE_SETSNUM(float,otl_var_float)
		TABLE_SETSNUM(double,otl_var_double)
		TABLE_SETSNUM(long long,otl_var_bigint)

  		inline void set(int i,int j,const DateTime & n)
		{
			if(otl_var_timestamp==this->Columns[j].otl_var_dbtype)
			{
				((DateTime *) Data[j])[i]=n;
			}
			else
			{
				EXP("字段:"+this->Columns[j].name+"类型为"+this->Columns[j].typeName+
					",不是"+otl_var_type_name(otl_var_timestamp));
			}
		}
		inline void set(int i,int j,const string &n)
		{
			int colType=this->Columns[j].otl_var_dbtype;
			if(colType==otl_var_char)
			{
				if(stringObject)
					((string *) Data[j])[i]=n;
				else
				{
#if defined(USE_SEPARATE_STORAGE_POINT)
					char * temp=(char *)(this->Data[j]+i*(this->Columns[j].dbsize));
					if(n.size()>=this->Columns[j].dbsize)EXP("设置数据大小比存在数据空间大");
					strcpy(temp,n.c_str());
#else
					if(useMaxLen==false)EXP("没有设置存在最大字符数据指针长度");
					if(n.size()>=this->Columns[j].dbsize)EXP("设置数据大小比存在数据空间大");
					char * temp=((char **)Data[j])[i];
					if(temp==NULL)((char **)Data[j])[i]=new char[this->Columns[j].dbsize];
					strcpy(temp,n.c_str());
#endif
				}
			}
			else if(colType==otl_var_raw)
			{
				((string *) Data[j])[i]=n;
			}
			else if(colType==otl_var_timestamp)
			{
				DateTime dt=DateTime::Parse2(n.c_str());
				set(i,j,dt);
			}
			else
			{
				double d=atof(n.c_str());
				set(i,j,d);
			}
		}
		inline void set(int i,int j,const char * n)
		{
			int colType=this->Columns[j].otl_var_dbtype;
			if(colType==otl_var_char)
			{
				if(stringObject)
					((string *) Data[j])[i]=n;
				else
				{
#if defined(USE_SEPARATE_STORAGE_POINT)
					char * temp=(char *)(this->Data[j]+i*(this->Columns[j].dbsize));
					if(strlen(n)>=this->Columns[j].dbsize)EXP("设置数据大小比存在数据空间大");
					strcpy(temp,n);
#else
					if(useMaxLen==false)EXP("没有设置存在最大字符数据指针长度");
					if(strlen(n)>=this->Columns[j].dbsize)EXP("设置数据大小比存在数据空间大");
					char * temp=((char **)Data[j])[i];
					if(temp==NULL)((char **)Data[j])[i]=new char[this->Columns[j].dbsize];
					strcpy(temp,n);
#endif
				}
			}
			else if(colType==otl_var_raw)
			{
				((string *) Data[j])[i]=n;
			}
			else if(colType==otl_var_timestamp)
			{
				DateTime dt=DateTime::Parse2(n);
				set(i,j,dt);
			}
			else
			{
				double d=atof(n);
				set(i,j,d);
			}
		}
		inline void setStr(int i,int j,const string & value)
		{
			this->set(i,j,value);
		}
		inline void setStr(int i,int j,const char * value)
		{
			this->set(i,j,value);
		} 

        //
		//摘要：
        //  设置数据
		inline void setInt(int i,int j,int value)
		{
			this->set(i,j,value);
		}
		inline void setShort(int i,int j,short value)
		{
			this->set(i,j,value);
		}
		inline void setUnsigned(int i,int j,unsigned value)
		{
			this->set(i,j,value);
		}
		inline void setLong(int i,int j,long value)
		{
			this->set(i,j,value);
		}
		inline void setDouble(int i,int j,double value)
		{
			this->set(i,j,value);
		}
		inline void  setFloat(int i,int j,float value)
		{
			this->set(i,j,value);
		}
		inline void  setBigInt(int i,int j,long long value)
		{
			this->set(i,j,value);
		}
		inline void  setLLong(int i,int j,long long value)
		{
			this->set(i,j,value);
		}
		inline void  setDate(int i,int j,DateTime value)
		{
			this->set(i,j,value);
		}
		//设置表格//
		inline void setInfo(Array<ColumnInfo> &_Columns,int _RowCount)
		{
			this->setIndexSeq=0;
			this->Columns=_Columns;
			this->RowCount=_RowCount;
			this->allRowCount=this->RowCount;
			this->ColCount=this->Columns.size();
#ifndef USE_SEPARATE_STORAGE_POINT
			this->useMaxLen=true;
#endif
			this->Data.resize(this->ColCount);
			for(int i=0;i<this->ColCount;i++)
			{
				switch(this->Columns[i].otl_var_dbtype)
				{
				case 21://otl_var_nchar
				case otl_var_varchar_long: 
				case otl_var_raw_long:
				case otl_var_clob:
				case 22://otl_var_nclob
				case otl_var_blob:
				case otl_var_raw:
					this->Columns[i].otl_var_dbtype=otl_var_char;
					//{
					//	this->Columns[i].otl_var_dbtype=otl_var_raw;
					//	Data[i]=(unsigned char *)(new string[this->allRowCount]);
					//	break;
					//}
				case otl_var_char:
					{
						if(stringObject)
							Data[i]=(unsigned char *)(new string[this->allRowCount]);      //对象存储
						else 
						{
#if defined(USE_SEPARATE_STORAGE_POINT)
							Data[i]=new unsigned char[this->allRowCount*(this->Columns[i].dbsize)];     //按字节存储
#else
							char * * tcp=(new char *[this->allRowCount]);     //按字节存储
							Data[i]=(unsigned char *)tcp;     //按字节存储
							for(int index=0;index<this->allRowCount;index++)
								tcp[index]=NULL;
#endif
						}
						break;
					}
				case otl_var_int:
					{
						Data[i]=(unsigned char *)(new int[this->allRowCount]);
						break;
					}
				case otl_var_unsigned_int:
					{
						Data[i]=(unsigned char *)(new unsigned int[this->allRowCount]);
						break;
					}
				case otl_var_long_int:
					{
						Data[i]=(unsigned char *)(new long int[this->allRowCount]);
						break;
					}
				case otl_var_short:
					{
						Data[i]=(unsigned char *)(new short int[this->allRowCount]);
						break;
					}
				case otl_var_float:
					{
						Data[i]=(unsigned char *)(new float [this->allRowCount]);
						break;
					}
				case otl_var_double:
					{
						Data[i]=(unsigned char *)(new double [this->allRowCount]);
						break;
					}
				case otl_var_db2time:
				case otl_var_db2date:
				case otl_var_tz_timestamp:
				case otl_var_ltz_timestamp:
				case otl_var_timestamp:
					{
						this->Columns[i].otl_var_dbtype=otl_var_timestamp;
						Data[i]=(unsigned char *)(new DateTime[this->allRowCount]);
						break;
					}
				case otl_var_bigint:
					{
						Data[i]=(unsigned char *)(new long long[this->allRowCount]);
						break;
					}
				default :
					EXP("存在不支持的数据类型。列["+String(i)+"]");
				}
				if(!Data[i])
				{
					cout<<i<<endl;
					EXP("内存空间申请失败!")
				}
			}
		};
		inline void addRow(void * * dataPoint)
		{
			int rowIndex=this->setIndexSeq;
			for(int col=0;col<this->ColCount;col++)
			{
				switch(this->Columns[col].otl_var_dbtype)
				{
				case otl_var_char:			//分类处理
					{
						char * dcp=(char *)(dataPoint[col]);
						if(stringObject) 
							((string *) Data[col])[rowIndex]=dcp; //对象存储                                    
						else 
						{
#if defined(USE_SEPARATE_STORAGE_POINT)
							strcpy((((char * )Data[col])+rowIndex*(this->Columns[col].dbsize)),dcp);//按字节存储                                    
#else
							((char **)Data[col])[rowIndex]=new char[this->Columns[col].dbsize];
							strcpy(((char **)Data[col])[rowIndex],dcp);//按字节存储                                    
#endif
						}
						break;
					}
				case 21:
				case otl_var_varchar_long: 
				case otl_var_raw_long:
				case otl_var_raw:
				case otl_var_clob:
				case 22:
				case otl_var_blob:
					{
						((string *) Data[col])[rowIndex]=(char *)(dataPoint[col]);
						break;
					}
				case otl_var_int:
					{
						((int *) Data[col])[rowIndex]=*((int *)(dataPoint[col]));
						break;
					}
				case otl_var_unsigned_int:
					{
						((unsigned *) Data[col])[rowIndex]=*((unsigned char *)(dataPoint[col]));
						break;
					}
				case otl_var_long_int:
					{
						((long *) Data[col])[rowIndex]=*((long *)(dataPoint[col]));
						break;
					}
				case otl_var_short:
					{
						((short *) Data[col])[rowIndex]=*((short *)(dataPoint[col]));
						break;
					}
				case otl_var_float:
					{
						((float *) Data[col])[rowIndex]=*((float *)(dataPoint[col]));
						break;
					}
				case otl_var_double:
					{
						((double *) Data[col])[rowIndex]=*((double *)(dataPoint[col]));
						break;
					}
				case otl_var_db2time:
				case otl_var_db2date:
				case otl_var_tz_timestamp:
				case otl_var_ltz_timestamp:
				case otl_var_timestamp:
					{
						((DateTime *) Data[col])[rowIndex]=*((DateTime *)(dataPoint[col]));
						break;
					}
				case otl_var_bigint:
					{
						((long long *) Data[col])[rowIndex]=*((long long *)(dataPoint[col]));
						break;
					}
				}
			}
			this->setIndexSeq++;
		};

		inline void setRow(int rowIndex,void * * dataPoint)
		{
			for(int col=0;col<this->ColCount;col++)
			{
				switch(this->Columns[col].otl_var_dbtype)
				{
				case otl_var_char:			//分类处理
					{
						char * dcp=(char *)(dataPoint[col]);
						if(stringObject) 
							((string *) Data[col])[rowIndex]=dcp; //对象存储                                    
						else 
						{
#if defined(USE_SEPARATE_STORAGE_POINT)
							strcpy((((char * )Data[col])+rowIndex*(this->Columns[col].dbsize)),dcp);//按字节存储                                    
#else
							if(((char **)Data[col])[rowIndex])
							{
								strcpy(((char **)Data[col])[rowIndex],dcp);//按字节存储                                    
							}
							else
							{
								((char **)Data[col])[rowIndex]=new char[this->Columns[col].dbsize];
								strcpy(((char **)Data[col])[rowIndex],dcp);//按字节存储                                    
							}
#endif
						}
						break;
					}
				case 21:
				case otl_var_varchar_long: 
				case otl_var_raw_long:
				case otl_var_raw:
				case otl_var_clob:
				case 22:
				case otl_var_blob:
					{
						((string *) Data[col])[rowIndex]=(char *)(dataPoint[col]);
						break;
					}
				case otl_var_int:
					{
						((int *) Data[col])[rowIndex]=*((int *)(dataPoint[col]));
						break;
					}
				case otl_var_unsigned_int:
					{
						((unsigned *) Data[col])[rowIndex]=*((unsigned char *)(dataPoint[col]));
						break;
					}
				case otl_var_long_int:
					{
						((long *) Data[col])[rowIndex]=*((long *)(dataPoint[col]));
						break;
					}
				case otl_var_short:
					{
						((short *) Data[col])[rowIndex]=*((short *)(dataPoint[col]));
						break;
					}
				case otl_var_float:
					{
						((float *) Data[col])[rowIndex]=*((float *)(dataPoint[col]));
						break;
					}
				case otl_var_double:
					{
						((double *) Data[col])[rowIndex]=*((double *)(dataPoint[col]));
						break;
					}
				case otl_var_db2time:
				case otl_var_db2date:
				case otl_var_tz_timestamp:
				case otl_var_ltz_timestamp:
				case otl_var_timestamp:
					{
						((DateTime *) Data[col])[rowIndex]=*((DateTime *)(dataPoint[col]));
						break;
					}
				case otl_var_bigint:
					{
						((long long *) Data[col])[rowIndex]=*((long long *)(dataPoint[col]));
						break;
					}
				}
			}
			if(this->setIndexSeq==rowIndex)
			{
				this->setIndexSeq++;
			}
		}
		//排序
		inline void sort(DataTable & table,int  indexs[])
		{
		}
		//计算值方法,1:sum,2:avg,3:max,4:min,5:count,6:last
		inline void groupBy(DataTable & table,Array<ColumnInfo> &_Columns,
			Array<int>& _indexRel,	//新表字段对应源表字段映射关系
			Array<int>& _groupMethod		//新表字段分组计算方法 0:group by 字段，其它为计算字段 1:sum,2:avg,3:max,4:min,5:count,6:last
			)
		{
			//计算检查有效性, 检查是否存在5计算,如果存在2计算则强制添加5计算
			if(_indexRel.size()!=_Columns.size())EXP("传入参数不对称_Columns大小与_indexRel大小");
			if(_groupMethod.size()!=_Columns.size())EXP("传入参数不对称_Columns大小与_groupMethod大小");
			bool havFiveCalc=false;
			bool havTwoCalc=false;
			int countCalcIndex=-1;
			int * groupMethod=NULL;
			int * indexRel=NULL;
			for(int i=0;i<_groupMethod.size();i++)
			{
				if(_groupMethod[i]==5)
				{
					havFiveCalc=true;
					countCalcIndex=i;
					_Columns[i].dbsize=sizeof(int);
					_Columns[i].dbtype=inNumber;
					_Columns[i].otl_var_dbtype=otl_var_int;
					_Columns[i].scale=0;
					_Columns[i].prec=9;
					_Columns[i].nullok=1;
					_Columns[i].typeName=otl_var_type_name(otl_var_int);
				}
				if(_groupMethod[i]==2)
				{
					havTwoCalc=true;
					_Columns[i].dbsize=sizeof(double);
					_Columns[i].otl_var_dbtype=otl_var_double;
					_Columns[i].scale=4;
					_Columns[i].prec=40;
					_Columns[i].nullok=1;
					_Columns[i].typeName=otl_var_type_name(otl_var_double);
				}
			}
			if(havTwoCalc==true && havFiveCalc==false)		//存在2不存在5
			{
				int colLen=_Columns.size();
				countCalcIndex=colLen;
				_Columns[colLen].name="count";
				_Columns[colLen].dbsize=sizeof(int);
				_Columns[colLen].dbtype=inNumber;
				_Columns[colLen].otl_var_dbtype=otl_var_int;
				_Columns[colLen].scale=0;
				_Columns[colLen].prec=9;
				_Columns[colLen].nullok=1;
				_Columns[colLen].typeName=otl_var_type_name(otl_var_int);
				
				_groupMethod[colLen]=5;
				_indexRel[colLen]=0;
				colLen+=1;
				groupMethod=new int[colLen];
				for(int i=0;i<colLen;i++)groupMethod[i]=_groupMethod[i];
				indexRel=new int[colLen];
				for(int i=0;i<colLen;i++)indexRel[i]=_indexRel[i];
			}
			else
			{
				int colLen=_groupMethod.size();
				groupMethod=new int[colLen];
				for(int i=0;i<colLen;i++)groupMethod[i]=_groupMethod[i];
				indexRel=new int[colLen];
				for(int i=0;i<colLen;i++)indexRel[i]=_indexRel[i];
			}
			setInfo(_Columns,table.RowCount);
			for(int i=0;i<this->ColCount;i++)
			{
				if(groupMethod[i]>0)
				{
					if((this->Columns[i].otl_var_dbtype==otl_var_char ||
						this->Columns[i].otl_var_dbtype==otl_var_timestamp
						)&& (groupMethod[i]==1 || groupMethod[i]==2 ))
						EXP("字符串和时间不支持分组函数：sum 和 avg ");
				}
			}
			char groupKey[4096];				//	存储分组值
			hashTable<char *,int> contains(table.RowCount);	//	存储分组KEY索引
			int rowIndex=0;
			for(int i=0;i<table.RowCount;i++)
			{
				int pos=0;
				for(int j=0;j<this->ColCount;j++)
				{
					if(groupMethod[j]==0)			//	分组字段
					{
						pos+=sprintf(groupKey+pos,"%s\1",table.getChars(i,indexRel[j]));		//	存储分组KEY
					}
				}
				int index=rowIndex;
				bool res=contains.find(groupKey,index);
				if(res==false)
				{
					contains.addNode(groupKey,rowIndex++);
					for(int j=0;j<this->ColCount;j++)
					{
						if(groupMethod[j]!=5)			//	分组字段 groupMethod[j]==0 ||  和部分计算字段
						{
							switch(this->Columns[j].otl_var_dbtype)
							{
							case otl_var_char:
								this->set(index,j,table.getChars(i,indexRel[j]));break;
							case otl_var_int:
								this->set(index,j,table.getInt(i,indexRel[j]));break;
							case otl_var_unsigned_int:
								this->set(index,j,table.getUnsigned(i,indexRel[j]));break;
							case otl_var_long_int:
								this->set(index,j,table.getLong(i,indexRel[j]));break;
							case otl_var_short:
								this->set(index,j,table.getShort(i,indexRel[j]));break;
							case otl_var_float:
								this->set(index,j,table.getFloat(i,indexRel[j]));break;
							case otl_var_double:
								this->set(index,j,table.getDouble(i,indexRel[j]));break;
							case otl_var_timestamp:
							case otl_var_db2time:
							case otl_var_db2date:
							case otl_var_tz_timestamp:
							case otl_var_ltz_timestamp:
								this->set(index,j,table.getDate(i,indexRel[j]));break;
							case otl_var_bigint:
								this->set(index,j,table.getLLong(i,indexRel[j]));break;
							}
						}
						else
						{
							this->set(index,j,1);
						}
					}
				}
				else
				{
					for(int j=0;j<this->ColCount;j++)
					{
						switch(groupMethod[j])			//	计算字段
						{
						case 0:continue;
						case 1:		//sum
						case 2:		//avg
							this->set(index,j,this->getDouble(index,j)+table.getDouble(i,indexRel[j]));break;
						case 3:		//max
						{
							switch(this->Columns[j].otl_var_dbtype)
							{
							case otl_var_char:
								{
								const char * tempcp1=table.getChars(i,indexRel[j]);
								if(strcmp(tempcp1,this->getChars(index,j))>0)
									this->set(index,j,tempcp1);
								}
								break;
							case otl_var_int:
								{
									int d1=table.getInt(i,indexRel[j]);
									if(d1>this->getInt(index,j))
									this->set(index,j,d1);
								}
								break;
							case otl_var_unsigned_int:
								{
									unsigned d1=table.getUnsigned(i,indexRel[j]);
									if(d1>this->getUnsigned(index,j))
									this->set(index,j,d1);
								}
								break;
							case otl_var_long_int:
								{
									long d1=table.getLong(i,indexRel[j]);
									if(d1>this->getLong(index,j))
									this->set(index,j,d1);
								}
								break;
							case otl_var_short:
								{
									short d1=table.getShort(i,indexRel[j]);
									if(d1>this->getShort(index,j))
									this->set(index,j,d1);
								}
								break;
							case otl_var_float:
								{
									float d1=table.getFloat(i,indexRel[j]);
									if(d1>this->getFloat(index,j))
									this->set(index,j,d1);
								}
								break;
							case otl_var_double:
								{
									double d1=table.getDouble(i,indexRel[j]);
									if(d1>this->getDouble(index,j))
									this->set(index,j,d1);
								}
								break;
							case otl_var_timestamp:
							case otl_var_db2time:
							case otl_var_db2date:
							case otl_var_tz_timestamp:
							case otl_var_ltz_timestamp:
								{
									DateTime d1=table.getDate(i,indexRel[j]);
									if(d1>this->getDate(index,j))
									this->set(index,j,d1);
								}
								break;
							case otl_var_bigint:
								{
									long long d1=table.getLLong(i,indexRel[j]);
									if(d1>this->getLLong(index,j))
									this->set(index,j,d1);
								}
								break;
							}
						}
							break;
						case 4:		//min
						{
							switch(this->Columns[j].otl_var_dbtype)
							{
							case otl_var_char:
								{
								const char * tempcp1=table.getChars(i,indexRel[j]);
								if(strcmp(tempcp1,this->getChars(index,j))<0)
									this->set(index,j,tempcp1);
								}
								break;
							case otl_var_int:
								{
									int d1=table.getInt(i,indexRel[j]);
									if(d1<this->getInt(index,j))
									this->set(index,j,d1);
								}
								break;
							case otl_var_unsigned_int:
								{
									unsigned d1=table.getUnsigned(i,indexRel[j]);
									if(d1<this->getUnsigned(index,j))
									this->set(index,j,d1);
								}
								break;
							case otl_var_long_int:
								{
									long d1=table.getLong(i,indexRel[j]);
									if(d1<this->getLong(index,j))
									this->set(index,j,d1);
								}
								break;
							case otl_var_short:
								{
									short d1=table.getShort(i,indexRel[j]);
									if(d1<this->getShort(index,j))
									this->set(index,j,d1);
								}
								break;
							case otl_var_float:
								{
									float d1=table.getFloat(i,indexRel[j]);
									if(d1<this->getFloat(index,j))
									this->set(index,j,d1);
								}
								break;
							case otl_var_double:
								{
									double d1=table.getDouble(i,indexRel[j]);
									if(d1<this->getDouble(index,j))
									this->set(index,j,d1);
								}
								break;
							case otl_var_timestamp:
							case otl_var_db2time:
							case otl_var_db2date:
							case otl_var_tz_timestamp:
							case otl_var_ltz_timestamp:
								{
									DateTime d1=table.getDate(i,indexRel[j]);
									if(d1<this->getDate(index,j))
									this->set(index,j,d1);
								}
								break;
							case otl_var_bigint:
								{
									long long d1=table.getLLong(i,indexRel[j]);
									if(d1<this->getLLong(index,j))
									this->set(index,j,d1);
								}
								break;
							}
						}
							break;
						case 5:		//count
							{
								int d1=this->getInt(index,j)+1;
								this->set(index,j,d1);
							}
							break;
						case 6:		//last
							{
								switch(this->Columns[j].otl_var_dbtype)
								{
								case otl_var_char:
									this->set(index,j,table.getChars(i,indexRel[j]));break;
								case otl_var_int:
									this->set(index,j,table.getInt(i,indexRel[j]));break;
								case otl_var_unsigned_int:
									this->set(index,j,table.getUnsigned(i,indexRel[j]));break;
								case otl_var_long_int:
									this->set(index,j,table.getLong(i,indexRel[j]));break;
								case otl_var_short:
									this->set(index,j,table.getShort(i,indexRel[j]));break;
								case otl_var_float:
									this->set(index,j,table.getFloat(i,indexRel[j]));break;
								case otl_var_double:
									this->set(index,j,table.getDouble(i,indexRel[j]));break;
								case otl_var_timestamp:
								case otl_var_db2time:
								case otl_var_db2date:
								case otl_var_tz_timestamp:
								case otl_var_ltz_timestamp:
									this->set(index,j,table.getDate(i,indexRel[j]));break;
								case otl_var_bigint:
									this->set(index,j,table.getLLong(i,indexRel[j]));break;
								}
							}
							break;
						default:
							EXP("存在不能解析的分组方法.");
						}
					}
				}
			}
			this->RowCount=rowIndex;
			contains.clear();
			delete[] indexRel;
			//最后计算平均值
			if(havTwoCalc)
			{
				for(int i=0;i<table.RowCount;i++)
				{
					for(int j=0;j<this->ColCount;j++)
					{
						if(groupMethod[j]==2)			//	分组字段
						{
							double sum=this->getDouble(i,j);
							int count=this->getInt(i,countCalcIndex);
							this->set(i,j,sum/count);
						}
					}
				}
			}
			delete[] groupMethod;
		}
		inline static void addCountCol(Array<ColumnInfo> &_Columns,String name="",int index=-1)
		{
			int len=_Columns.size();
			if(index!=-1)
			{
				_Columns.insert(_Columns.begin()+index,ColumnInfo());
				len=index;
			}
			if(name=="")_Columns[len].name="count";
			else _Columns[len].name=name;
			_Columns[len].dbsize=sizeof(int);
			_Columns[len].dbtype=inNumber;
			_Columns[len].otl_var_dbtype=otl_var_int;
			_Columns[len].scale=0;
			_Columns[len].prec=9;
			_Columns[len].nullok=1;
			_Columns[len].typeName=otl_var_type_name(otl_var_int);
		}
#endif
	};
}
#endif
