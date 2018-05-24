// ==============================================================
//progame      Common::ResultSet base otl_stream (otl4)
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

#ifndef __Common_Connection__
#define __Common_Connection__
#include "Common.h"
#if defined(__OTL_H__)

namespace Common
{
	//class Connect
 //   {
	//public:
	//	virtual inline void close();
	//	virtual inline void rlogon(const string& connect_str,const int auto_commit=0);
	//	virtual inline void open(const string& connect_str,const int auto_commit=0);
	//	virtual inline int execUpdate(const string &sql,const int exception_enabled=1);
	//	virtual inline int truncate(const string & table, int partition=0, const int exception_enabled=1);
	//	virtual inline int truncate(const string & table, string partition, const int exception_enabled=1);
 //   };
 //   class Square : ShapesClass
 //   {
 //       int x, y;
 //       // Not providing an Area method results
 //       // in a compile-time error.
	//public :
	//	inline int Area()
 //       {
 //           return x * y;
 //       }
 //   };
	//class DBConnection
	//{
	//	public:
	//	virtual inline void close()=0;
	//	virtual inline int init(const int threaded_mode=0)=0;
	//	virtual inline void rlogon(const string& connect_str,const int auto_commit=0)=0;
	//	virtual inline void open(const string& connect_str,const int auto_commit=0)=0;
	//	virtual inline int execUpdate(const string &sql,const int exception_enabled=1)=0;
	//	virtual inline int truncate(const string & table, int partition=0, const int exception_enabled=1)=0;
	//	virtual inline int truncate(const string & table, string partition, const int exception_enabled=1)=0;
	//	virtual void auto_commit_on();
	//	virtual void commit();
 //   };


	template <class T> class ConnectionT:public T
	{
	public:
		ConnectionT(){};
		ConnectionT(const string &connect_str,const int auto_commit=0):T(connect_str.c_str(),auto_commit){};
#ifdef OTL_ODBC
		ConnectionT(OTL_HENV ahenv,OTL_HDBC ahdbc,const int auto_commit=0):T(ahenv,ahdbc,auto_commit){};
#endif
		inline static int init(const int threaded_mode=0){return T::otl_initialize(threaded_mode);};
		inline void close(){T::logoff();};
		inline void rlogon(const string& connect_str,const int auto_commit=0){T::rlogon(connect_str.c_str(),auto_commit);};
		inline void open(const string& connect_str,const int auto_commit=0){T::rlogon(connect_str.c_str(),auto_commit);};
		inline int execUpdate(const string &sql,const int exception_enabled=1)
		{
			return this->direct_exec(sql.c_str(),exception_enabled);
		};
		inline static int execUpdate(const string & sql,T& _con,const int exception_enabled=1)
		{
			return _con.direct_exec(sql.c_str(),exception_enabled);
		};
		inline int truncate(const string & table, int partition=0, const int exception_enabled=1)
		{
			string sql="";
			if(partition==0)
			{
				sql="truncate table "+table;
			}
			else
			{
				sql="alter table "+table+" truncate partition P"+partition;
			}
			return execUpdate(sql,exception_enabled);
		};
		inline static int truncate(const string & table, ConnectionT& _con, int partition=0,const int exception_enabled=1)
		{
			string sql="";
			if(partition==0)
			{
				sql="truncate table "+table;
			}
			else
			{
				sql="alter table "+table+" truncate partition P"+partition;
			}
			return execUpdate(sql,_con,exception_enabled);
		};
		inline int truncate(const string & table, string partition, const int exception_enabled=1)
		{
			string sql="";
			if(partition=="")
			{
				sql="truncate table "+table;
			}
			else
			{
				sql="alter table "+table+" truncate partition P"+partition;
			}
			return execUpdate(sql,exception_enabled);
		};
		inline static int truncate(const string & table,ConnectionT& _con, string partition,const int exception_enabled=1)
		{
			string sql="";
			if(partition=="")
			{
				sql="truncate table "+table;
			}
			else
			{
				sql="alter table "+table+" truncate partition P"+partition;
			}
			return execUpdate(sql,_con,exception_enabled);
		};
	};
}

// ------------------- Namespace generation ------------------------
#if defined(OTL_EXPLICIT_NAMESPACES)

OTL_ODBC_NAMESPACE_BEGIN 
	typedef ConnectionT< OTL_ODBC_NAMESPACE_PREFIX otl_connect> Connection;
OTL_ODBC_NAMESPACE_END

OTL_ORA7_NAMESPACE_BEGIN 
	typedef ConnectionT< OTL_ORA7_NAMESPACE_PREFIX otl_connect> Connection;
OTL_ORA7_NAMESPACE_END

OTL_ORA8_NAMESPACE_BEGIN 
	typedef ConnectionT< OTL_ORA8_NAMESPACE_PREFIX otl_connect> Connection;
OTL_ORA8_NAMESPACE_END
#if MAIN_DATABASE_TYPE==0
#error "定义多种数据库接口时必需指定主数据库类型,MAIN_DATABASE_TYPE 只能为 1 或者 2  "
#endif

#else

// ================ Combinations of two OTLs =========================
#if defined(OTL_ORA7) && !defined(OTL_ORA8) && \
	((defined(OTL_ODBC) && !defined(OTL_DB2_CLI)) || (!defined(OTL_ODBC) && defined(OTL_DB2_CLI))) 
	 
OTL_ORA7_NAMESPACE_BEGIN 
	typedef Common::ConnectionT<OTL_ORA7_NAMESPACE_PREFIX otl_connect> Connection;
OTL_ORA7_NAMESPACE_END
OTL_ODBC_NAMESPACE_BEGIN 
	typedef Common::ConnectionT<OTL_ODBC_NAMESPACE_PREFIX otl_connect> Connection;
OTL_ODBC_NAMESPACE_END
#if MAIN_DATABASE_TYPE==0
#error "定义二种数据库接口时必需指定主数据库类型,MAIN_DATABASE_TYPE 只能为 1 或者 2  "
#endif
#endif

#if !defined(OTL_ORA7) && defined(OTL_ORA8) &&\
	((defined(OTL_ODBC) && !defined(OTL_DB2_CLI)) || (!defined(OTL_ODBC) && defined(OTL_DB2_CLI)))

OTL_ORA8_NAMESPACE_BEGIN 
	typedef Common::ConnectionT<OTL_ORA8_NAMESPACE_PREFIX otl_connect> Connection;
OTL_ORA8_NAMESPACE_END
OTL_ODBC_NAMESPACE_BEGIN 
	typedef Common::ConnectionT<OTL_ODBC_NAMESPACE_PREFIX otl_connect> Connection;
OTL_ODBC_NAMESPACE_END

#if MAIN_DATABASE_TYPE==0
#error "定义二种数据库接口时必需指定主数据库类型,MAIN_DATABASE_TYPE 只能为 1 或者 2  "
#endif

#endif

#endif	
namespace Common
{
#if defined(OTL_ODBC)&&!defined(OTL_ORA8)&& \
    !defined(OTL_ORA7)&&!defined(OTL_DB2_CLI) \
 || !defined(OTL_ODBC)&&defined(OTL_ORA8)&& \
    !defined(OTL_ORA7)&&!defined(OTL_DB2_CLI) \
 || !defined(OTL_ODBC)&&!defined(OTL_ORA8)&& \
    defined(OTL_ORA7)&&!defined(OTL_DB2_CLI) \
 || !defined(OTL_ODBC)&&!defined(OTL_ORA8)&& \
    !defined(OTL_ORA7)&&defined(OTL_DB2_CLI)
typedef ConnectionT<otl_connect>  Connection;
#endif
}

#endif //#if defined(__OTL_H__)
#endif //#ifndef __Common_Connection__
