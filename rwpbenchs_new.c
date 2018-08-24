
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[17];
};
static struct sqlcxp sqlfpn =
{
    16,
    "rwpbenchs_new.pc"
};


static unsigned int sqlctx = 5333411;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned int   sqlpfmem;
   unsigned char  *sqhstv[44];
   unsigned long  sqhstl[44];
            int   sqhsts[44];
            short *sqindv[44];
            int   sqinds[44];
   unsigned long  sqharm[44];
   unsigned long  *sqharc[44];
   unsigned short  sqadto[44];
   unsigned short  sqtdso[44];
} sqlstm = {13,44};

/* SQLLIB Prototypes */
extern sqlcxt (/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlcx2t(/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlbuft(/*_ void **, char * _*/);
extern sqlgs2t(/*_ void **, char * _*/);
extern sqlorat(/*_ void **, unsigned int *, void * _*/);

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem(/*_ unsigned char *, signed int * _*/);

 static char *sq0016 = 
"select * from table ( dbms_xplan . display_cursor ( :b0 , :b1 ) )           \
 ";

 static char *sq0028 = 
"select name , value from v$mystat m , v$statname n where n . statistic# = m \
. statistic# and value > 0            ";

 static char *sq0058 = 
"select substr ( r . query_name , 1 , 40 ) query_name , sum ( trunc ( elapsed\
_t / 1000 ) ) wall_time , sum ( trunc ( nvl ( elapsed_time , 0 ) / 1000 ) ) el\
apsed_sql , sum ( executions ) execs from response_times r , ( select query_na\
me , max ( executions ) m_execs from response_times where trial_nbr = :b1 grou\
p by query_name ) m where trial_nbr = :b1 and executions = m_execs and r . que\
ry_name = m . query_name group by r . query_name order by r . query_name      \
      ";

 static char *sq0060 = 
"select substr ( r . query_name , 1 , 40 ) query_name , elapsed_t wall_time ,\
 nvl ( elapsed_time , 0 ) , nvl ( px_servers_requested , 0 ) , nvl ( px_server\
s_allocated , 0 ) , executions execs , nvl ( QUEUING_TIME , 0 ) , nvl ( CPU_TI\
ME , 0 ) , nvl ( BUFFER_GETS , 0 ) , nvl ( IO_INTERCONNECT_BYTES , 0 ) , nvl (\
 PHYSICAL_READ_REQUESTS , 0 ) , nvl ( PHYSICAL_READ_BYTES , 0 ) , nvl ( PHYSIC\
AL_WRITE_REQUESTS , 0 ) , nvl ( PHYSICAL_WRITE_BYTES , 0 ) , nvl ( APPLICATION\
_WAIT_TIME , 0 ) , nvl ( CONCURRENCY_WAIT_TIME , 0 ) , nvl ( CLUSTER_WAIT_TIME\
 , 0 ) , nvl ( USER_IO_WAIT_TIME , 0 ) , nvl ( im_scans , 0 ) , nvl ( im_scan_\
bytes_uncompressed , 0 ) , nvl ( IM_SCAN_BYTES_INMEMORY , 0 ) from response_ti\
mes r , ( select query_name , max ( executions ) m_execs from response_times w\
here trial_nbr = :b1 group by query_name ) m where trial_nbr = :b1 and executi\
ons = m_execs and r . query_name = m . query_name order by r . query_name     \
       ";

 static char *sq0062 = 
"select substr ( a . query_name , 1 , 40 ) , round ( a . elapsed_time / 1000 \
/ a . executions ) Elapsed1 , round ( b . elapsed_time / 1000 / b . executions\
 ) , case when b . elapsed_time = 0 or a . elapsed_time = 0 then 'NA' when a .\
 elapsed_time / a . executions > b . elapsed_time / b . executions then 'S' ||\
 to_char ( a . elapsed_time * b . executions / b . elapsed_time / a . executio\
ns , '9999.99' ) else 'F' || to_char ( b . elapsed_time / a . elapsed_time , '\
9999.99' ) end from response_times a , response_times b where a . trial_nbr = \
:b1 and b . trial_nbr = :b2 and a . query_name = b . query_name order by a . q\
uery_name            ";

 static char *sq0067 = 
"select output from table ( dbms_workload_repository . awr_global_report_html\
 ( :b0 , '' , :b1 , :b2 ) )            ";

 static char *sq0068 = 
"select output from table ( dbms_workload_repository . awr_report_html ( :b0 \
, :b1 , :b2 , :b3 ) )            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{13,4130,1,8,0,
5,0,0,1,355,0,1027,737,0,0,8,8,0,0,128,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,3,0,0,1,4,0,0,1,3,0,0,1,97,0,0,
56,0,0,2,0,0,1053,760,0,0,0,0,0,0,128,1,97,0,0,
75,0,0,3,340,0,1027,768,0,0,8,8,0,0,128,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,3,0,0,1,4,0,0,1,3,0,0,1,97,0,0,
126,0,0,4,0,0,1053,796,0,0,0,0,0,0,128,1,97,0,0,
145,0,0,0,0,0,69,888,0,0,1,1,0,2,7,77,65,73,78,95,68,66,3,112,0,0,
171,0,0,0,0,0,100,890,0,0,1,1,0,2,7,77,65,73,78,95,68,66,3,112,0,0,
197,0,0,0,0,0,112,891,0,0,5,3,0,2,7,77,65,73,78,95,68,66,3,3,0,0,1,94,0,0,0,10,
0,0,3,112,0,0,0,10,0,0,
239,0,0,0,0,0,114,893,0,0,2,1,0,2,7,77,65,73,78,95,68,66,1,112,0,0,2,3,0,7,
269,0,0,5,0,0,17,897,0,0,1,1,0,2,7,77,65,73,78,95,68,66,1,5,0,0,
295,0,0,5,0,0,21,898,0,0,2,2,0,2,7,77,65,73,78,95,68,66,1,5,0,0,1,112,0,0,
325,0,0,0,0,0,101,903,0,0,1,1,0,1,0,3,112,0,0,
344,0,0,0,0,0,90,938,0,0,1,1,0,1,0,13,5,0,0,
363,0,0,0,0,0,91,951,0,0,1,1,0,1,0,13,5,0,0,
382,0,0,6,0,0,17,954,0,0,1,1,0,2,7,77,65,73,78,95,68,66,1,5,0,0,
408,0,0,0,0,0,91,957,0,0,1,1,0,1,0,13,5,0,0,
427,0,0,7,0,0,24,965,0,0,1,1,0,2,7,77,65,73,78,95,68,66,1,5,0,0,
453,0,0,6,0,0,20,970,0,0,1,1,0,2,7,77,65,73,78,95,68,66,13,5,0,0,
479,0,0,0,0,0,91,972,0,0,1,1,0,1,0,13,5,0,0,
498,0,0,0,0,0,92,978,0,0,2,1,0,1,0,13,5,0,0,2,3,0,0,
521,0,0,0,0,0,91,982,0,0,1,1,0,1,0,13,5,0,0,
540,0,0,0,0,0,92,991,0,0,6,2,0,1,0,13,5,0,0,257,3,0,0,514,3,0,0,3842,5,0,0,
1026,3,0,0,2050,3,0,0,
579,0,0,0,0,0,93,1023,0,0,4,4,0,1,0,13,5,0,0,257,3,0,0,513,3,0,0,769,3,0,0,
610,0,0,0,0,0,93,1024,0,0,5,5,0,1,0,13,5,0,0,257,3,0,0,3585,5,0,0,4353,3,0,0,
4097,3,0,0,
645,0,0,8,0,0,17,1053,0,0,1,1,0,2,7,77,65,73,78,95,68,66,1,5,0,0,
671,0,0,8,0,0,45,1055,0,0,3,3,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,
698,0,0,0,0,0,90,1058,0,0,1,1,0,1,0,13,5,0,0,
717,0,0,6,0,0,19,1061,0,0,1,1,0,2,7,77,65,73,78,95,68,66,13,5,0,0,
743,0,0,0,0,0,92,1065,0,0,2,1,0,1,0,13,5,0,0,2,3,0,0,
766,0,0,0,0,0,92,1070,0,0,3,2,0,1,0,13,5,0,0,257,3,0,0,3842,5,0,0,
793,0,0,8,0,0,13,1080,0,0,1,0,0,1,0,2,5,0,0,
812,0,0,0,0,0,93,1098,0,0,5,5,0,1,0,13,5,0,0,257,3,0,0,513,3,0,0,769,3,0,0,
3329,4,0,0,
847,0,0,0,0,0,93,1103,0,0,5,5,0,1,0,13,5,0,0,257,3,0,0,513,3,0,0,769,3,0,0,
3329,5,0,0,
882,0,0,6,0,0,11,1107,0,0,1,1,0,2,7,77,65,73,78,95,68,66,13,5,0,0,
908,0,0,6,0,0,15,1111,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
930,0,0,8,0,0,15,1148,0,0,0,0,0,1,0,
945,0,0,0,0,0,91,1154,0,0,1,1,0,1,0,13,5,0,0,
964,0,0,0,0,0,91,1155,0,0,1,1,0,1,0,13,5,0,0,
983,0,0,0,0,0,90,1180,0,0,1,1,0,1,0,13,5,0,0,
1002,0,0,6,0,0,19,1183,0,0,1,1,0,2,7,77,65,73,78,95,68,66,13,5,0,0,
1028,0,0,0,0,0,92,1187,0,0,2,1,0,1,0,13,5,0,0,2,3,0,0,
1051,0,0,0,0,0,92,1192,0,0,3,2,0,1,0,13,5,0,0,257,3,0,0,3842,5,0,0,
1078,0,0,0,0,0,93,1222,0,0,5,5,0,1,0,13,5,0,0,257,3,0,0,513,3,0,0,769,3,0,0,
3329,4,0,0,
1113,0,0,0,0,0,93,1228,0,0,5,5,0,1,0,13,5,0,0,257,3,0,0,513,3,0,0,769,3,0,0,
3329,3,0,0,
1148,0,0,0,0,0,93,1233,0,0,5,5,0,1,0,13,5,0,0,257,3,0,0,513,3,0,0,769,3,0,0,
3329,5,0,0,
1183,0,0,6,0,0,11,1239,0,0,1,1,0,2,7,77,65,73,78,95,68,66,13,5,0,0,
1209,0,0,6,0,0,15,1243,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
1231,0,0,0,0,0,91,1286,0,0,1,1,0,1,0,13,5,0,0,
1250,0,0,0,0,0,91,1287,0,0,1,1,0,1,0,13,5,0,0,
1269,0,0,6,0,0,45,1291,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
1291,0,0,6,0,0,15,1303,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
1313,0,0,0,0,0,91,1308,0,0,1,1,0,1,0,13,5,0,0,
1332,0,0,6,0,0,14,1370,0,0,1,0,0,2,7,77,65,73,78,95,68,66,14,5,0,0,
1358,0,0,9,548,0,4,1418,0,0,4,2,0,2,7,77,65,73,78,95,68,66,1,3,0,0,2,3,0,0,2,5,
0,0,1,5,0,0,
1396,0,0,10,0,0,17,1469,0,0,1,1,0,2,7,77,65,73,78,95,68,66,1,5,0,0,
1422,0,0,0,0,0,90,1498,0,0,1,1,0,1,0,13,5,0,0,
1441,0,0,10,0,0,19,1501,0,0,1,1,0,2,7,77,65,73,78,95,68,66,13,5,0,0,
1467,0,0,0,0,0,92,1505,0,0,2,1,0,1,0,13,5,0,0,2,3,0,0,
1490,0,0,0,0,0,92,1510,0,0,3,2,0,1,0,13,5,0,0,257,3,0,0,3842,5,0,0,
1517,0,0,0,0,0,93,1544,0,0,5,5,0,1,0,13,5,0,0,257,3,0,0,513,3,0,0,769,3,0,0,
3329,4,0,0,
1552,0,0,0,0,0,93,1550,0,0,5,5,0,1,0,13,5,0,0,257,3,0,0,513,3,0,0,769,3,0,0,
3329,3,0,0,
1587,0,0,0,0,0,93,1555,0,0,5,5,0,1,0,13,5,0,0,257,3,0,0,513,3,0,0,769,3,0,0,
3329,5,0,0,
1622,0,0,10,0,0,23,1561,0,0,1,1,0,2,7,77,65,73,78,95,68,66,13,5,0,0,
1648,0,0,0,0,0,91,1601,0,0,1,1,0,1,0,13,5,0,0,
1667,0,0,11,0,0,29,1602,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
1689,0,0,12,69,0,4,1816,0,0,1,0,0,2,7,77,65,73,78,95,68,66,2,3,0,0,
1715,0,0,13,69,0,4,1888,0,0,1,0,0,2,7,77,65,73,78,95,68,66,2,3,0,0,
1741,0,0,0,0,0,69,2056,0,0,1,1,0,2,7,77,65,73,78,95,68,66,3,112,0,0,
1767,0,0,14,163,0,4,2084,0,0,4,3,0,2,7,77,65,73,78,95,68,66,1,5,0,0,1,3,0,0,1,
5,0,0,2,112,0,0,
1805,0,0,0,0,0,114,2096,0,0,2,1,0,2,7,77,65,73,78,95,68,66,1,112,0,0,2,3,0,7,
1835,0,0,0,0,0,110,2105,0,0,5,4,0,2,7,77,65,73,78,95,68,66,3,3,0,0,1,112,0,0,1,
3,0,0,3,9,0,0,0,10,0,0,
1877,0,0,0,0,0,110,2115,0,0,5,3,0,2,7,77,65,73,78,95,68,66,3,3,0,0,1,112,0,0,0,
10,0,0,3,9,0,0,0,10,0,0,
1919,0,0,15,356,0,4,2141,0,0,4,3,0,2,7,77,65,73,78,95,68,66,2,3,0,0,1,5,0,0,1,
3,0,0,1,0,0,0,
1957,0,0,16,77,0,9,2157,0,0,2,2,0,2,7,77,65,73,78,95,68,66,1,5,0,0,1,3,0,0,
1987,0,0,16,0,0,13,2161,0,0,1,0,0,2,7,77,65,73,78,95,68,66,2,5,0,0,
2013,0,0,16,0,0,15,2167,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
2035,0,0,17,0,0,24,2192,0,0,1,1,0,2,7,77,65,73,78,95,68,66,1,5,0,0,
2061,0,0,18,415,0,4,2280,0,0,6,3,0,2,7,77,65,73,78,95,68,66,2,3,0,0,2,3,0,0,2,
5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,
2107,0,0,19,4519,0,4,2297,0,0,39,6,0,2,7,77,65,73,78,95,68,66,2,3,0,0,2,5,0,0,
2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,4,0,0,2,5,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,3,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,0,0,0,1,0,0,0,1,3,0,0,
2285,0,0,20,4252,0,4,2397,0,0,39,6,0,2,7,77,65,73,78,95,68,66,2,3,0,0,2,5,0,0,
2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,4,0,0,2,5,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,3,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,0,0,0,1,0,0,0,1,3,0,0,
2463,0,0,21,1147,0,1027,2498,0,0,43,43,0,0,128,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,4,0,0,1,5,0,
0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,
0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,
4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,
2654,0,0,22,268,0,1027,2625,0,0,10,10,0,0,128,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
2713,0,0,23,0,0,1053,2651,0,0,0,0,0,0,128,1,5,0,0,
2732,0,0,24,101,0,4,2675,0,0,3,1,0,2,7,77,65,73,78,95,68,66,2,3,0,0,2,4,0,0,1,
3,0,0,
2766,0,0,25,113,0,4,2693,0,0,4,1,0,2,7,77,65,73,78,95,68,66,2,3,0,0,2,4,0,0,2,
3,0,0,1,3,0,0,
2804,0,0,26,126,0,1027,2717,0,0,6,6,0,0,128,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
4,0,0,1,5,0,0,1,5,0,0,
2847,0,0,27,0,0,1053,2720,0,0,0,0,0,0,128,1,5,0,0,
2866,0,0,28,114,0,9,2737,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
2888,0,0,28,0,0,13,2746,0,0,2,0,0,2,7,77,65,73,78,95,68,66,2,5,0,0,2,4,0,0,
2918,0,0,29,255,0,4,2760,0,0,5,0,0,2,7,77,65,73,78,95,68,66,2,3,0,0,2,3,0,0,2,
3,0,0,2,3,0,0,2,5,0,0,
2960,0,0,0,0,0,27,2965,0,0,4,4,0,2,7,77,65,73,78,95,68,66,1,5,0,0,1,10,0,0,1,
10,0,0,1,10,0,0,
2998,0,0,31,0,0,24,2971,0,0,1,1,0,2,7,77,65,73,78,95,68,66,1,5,0,0,
3024,0,0,32,219,0,4,2975,0,0,3,0,0,2,7,77,65,73,78,95,68,66,2,3,0,0,2,3,0,0,2,
3,0,0,
3058,0,0,0,0,0,27,2989,0,0,4,4,0,3,7,80,69,82,70,95,68,66,1,5,0,0,1,10,0,0,1,
10,0,0,1,10,0,0,
3096,0,0,34,0,0,24,3020,0,0,1,1,0,2,7,77,65,73,78,95,68,66,1,5,0,0,
3122,0,0,35,255,0,1027,3028,0,0,5,4,0,0,128,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,2,
5,0,0,1,5,0,0,
3161,0,0,36,148,0,1028,3041,0,0,1,0,0,0,128,2,3,0,0,1,5,0,0,
3184,0,0,37,0,0,1053,3044,0,0,0,0,0,0,128,1,5,0,0,
3203,0,0,38,0,0,24,3119,0,0,1,1,0,2,7,77,65,73,78,95,68,66,1,5,0,0,
3229,0,0,0,0,0,69,3248,0,0,1,1,0,2,7,77,65,73,78,95,68,66,3,112,0,0,
3255,0,0,39,0,0,17,3253,0,0,1,1,0,2,7,77,65,73,78,95,68,66,1,5,0,0,
3281,0,0,39,0,0,45,3257,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
3303,0,0,39,0,0,13,3259,0,0,2,0,0,2,7,77,65,73,78,95,68,66,2,112,0,0,2,5,0,0,
3333,0,0,0,0,0,114,3272,0,0,2,1,0,2,7,77,65,73,78,95,68,66,1,112,0,0,2,3,0,7,
3363,0,0,0,0,0,110,3278,0,0,5,4,0,2,7,77,65,73,78,95,68,66,3,3,0,0,1,112,0,0,1,
3,0,0,3,9,0,0,0,10,0,0,
3405,0,0,0,0,0,110,3284,0,0,5,3,0,2,7,77,65,73,78,95,68,66,3,3,0,0,1,112,0,0,0,
10,0,0,3,9,0,0,0,10,0,0,
3447,0,0,40,0,0,24,3308,0,0,1,1,0,2,7,77,65,73,78,95,68,66,1,5,0,0,
3473,0,0,39,0,0,15,3420,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
3495,0,0,0,0,0,77,3421,0,0,1,1,0,2,7,77,65,73,78,95,68,66,3,112,0,0,
3521,0,0,41,0,0,24,3444,0,0,1,1,0,2,7,77,65,73,78,95,68,66,1,5,0,0,
3547,0,0,42,89,0,1029,3545,0,0,2,2,0,0,128,1,5,0,0,1,5,0,0,1,5,0,0,
3574,0,0,43,0,0,1053,3554,0,0,0,0,0,0,128,1,5,0,0,
3593,0,0,0,0,0,1051,3677,0,0,4,4,0,0,128,1,5,0,0,1,10,0,0,1,10,0,0,1,10,0,0,1,
5,0,0,
3628,0,0,45,86,0,1028,3685,0,0,1,0,0,0,128,2,3,0,0,1,5,0,0,
3651,0,0,46,0,0,1048,3693,0,0,1,1,0,0,128,1,5,0,0,1,5,0,0,
3674,0,0,47,213,0,1048,3694,0,0,0,0,0,0,128,1,5,0,0,
3693,0,0,48,121,0,1048,3696,0,0,0,0,0,0,128,1,5,0,0,
3712,0,0,49,37,0,1048,3698,0,0,0,0,0,0,128,1,5,0,0,
3731,0,0,50,55,0,1048,3699,0,0,0,0,0,0,128,1,5,0,0,
3750,0,0,51,32,0,1048,3700,0,0,0,0,0,0,128,1,5,0,0,
3769,0,0,52,45,0,1048,3701,0,0,0,0,0,0,128,1,5,0,0,
3788,0,0,53,31,0,1048,3702,0,0,0,0,0,0,128,1,5,0,0,
3807,0,0,54,43,0,1048,3703,0,0,0,0,0,0,128,1,5,0,0,
3826,0,0,55,0,0,1048,3717,0,0,1,1,0,0,128,1,5,0,0,1,5,0,0,
3849,0,0,56,0,0,1054,3721,0,0,0,0,0,0,128,1,5,0,0,
3868,0,0,0,0,0,1051,3746,0,0,4,4,0,0,128,1,5,0,0,1,10,0,0,1,10,0,0,1,10,0,0,1,
5,0,0,
3903,0,0,58,472,0,1033,3758,0,0,2,2,0,0,128,1,3,0,0,1,0,0,0,1,5,0,0,
3930,0,0,59,109,0,1028,3761,0,0,2,1,0,0,128,2,3,0,0,1,3,0,0,1,5,0,0,
3957,0,0,58,0,0,1037,3774,0,0,4,0,0,0,128,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,1,5,
0,0,
3992,0,0,58,0,0,1039,3782,0,0,0,0,0,0,128,1,5,0,0,
4011,0,0,60,941,0,1033,3811,0,0,2,2,0,0,128,1,3,0,0,1,0,0,0,1,5,0,0,
4038,0,0,60,0,0,1037,3814,0,0,21,0,0,0,128,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,3,0,0,2,4,0,0,2,3,0,0,2,4,0,0,2,
3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,1,5,0,0,
4141,0,0,60,0,0,1039,3826,0,0,0,0,0,0,128,1,5,0,0,
4160,0,0,61,83,0,1028,3830,0,0,2,1,0,0,128,2,3,0,0,1,3,0,0,1,5,0,0,
4187,0,0,63,110,0,1028,3848,0,0,2,1,0,0,128,2,5,0,0,1,3,0,0,1,5,0,0,
4214,0,0,62,643,0,1033,3853,0,0,2,2,0,0,128,1,3,0,0,1,3,0,0,1,5,0,0,
4241,0,0,62,0,0,1037,3860,0,0,4,0,0,0,128,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,1,5,
0,0,
4276,0,0,64,0,0,1054,3867,0,0,0,0,0,0,128,1,5,0,0,
4295,0,0,65,88,0,4,3887,0,0,2,0,0,2,7,77,65,73,78,95,68,66,2,3,0,0,2,3,0,0,
4325,0,0,66,41,0,4,3899,0,0,1,0,0,2,7,77,65,73,78,95,68,66,2,3,0,0,
4351,0,0,67,115,0,9,3927,0,0,3,3,0,2,7,77,65,73,78,95,68,66,1,3,0,0,1,3,0,0,1,
3,0,0,
4385,0,0,67,0,0,13,3939,0,0,1,0,0,2,7,77,65,73,78,95,68,66,2,5,0,0,
4411,0,0,67,0,0,15,3950,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
4433,0,0,68,109,0,9,3961,0,0,4,4,0,2,7,77,65,73,78,95,68,66,1,3,0,0,1,3,0,0,1,
3,0,0,1,3,0,0,
4471,0,0,68,0,0,13,3974,0,0,1,0,0,2,7,77,65,73,78,95,68,66,2,5,0,0,
4497,0,0,67,0,0,15,3985,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
4519,0,0,69,0,0,30,4035,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
4541,0,0,70,0,0,1054,4036,0,0,0,0,0,0,128,1,5,0,0,
4560,0,0,71,0,0,30,4042,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
4582,0,0,72,0,0,1054,4043,0,0,0,0,0,0,128,1,5,0,0,
4601,0,0,0,0,0,27,4128,0,0,4,4,0,2,7,77,65,73,78,95,68,66,1,5,0,0,1,10,0,0,1,
10,0,0,1,10,0,0,
4639,0,0,74,129,0,4,4202,0,0,3,2,0,2,7,77,65,73,78,95,68,66,2,5,0,0,1,3,0,0,1,
3,0,0,
4673,0,0,75,0,0,30,4223,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
4695,0,0,0,0,0,27,4665,0,0,4,4,0,2,7,77,65,73,78,95,68,66,1,5,0,0,1,10,0,0,1,
10,0,0,1,10,0,0,
4733,0,0,0,0,0,69,4801,0,0,1,1,0,2,7,77,65,73,78,95,68,66,3,112,0,0,
4759,0,0,77,0,0,17,4808,0,0,1,1,0,2,7,77,65,73,78,95,68,66,1,5,0,0,
4785,0,0,77,0,0,45,4813,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
4807,0,0,77,0,0,13,4818,0,0,2,0,0,2,7,77,65,73,78,95,68,66,2,112,0,0,2,5,0,0,
4837,0,0,0,0,0,114,4827,0,0,2,1,0,2,7,77,65,73,78,95,68,66,1,112,0,0,2,3,0,7,
4867,0,0,0,0,0,110,4832,0,0,5,4,0,2,7,77,65,73,78,95,68,66,3,3,0,0,1,112,0,0,1,
3,0,0,3,9,0,0,0,10,0,0,
4909,0,0,0,0,0,110,4838,0,0,5,3,0,2,7,77,65,73,78,95,68,66,3,3,0,0,1,112,0,0,0,
10,0,0,3,9,0,0,0,10,0,0,
4951,0,0,77,0,0,15,4862,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
4973,0,0,0,0,0,77,4864,0,0,1,1,0,2,7,77,65,73,78,95,68,66,3,112,0,0,
4999,0,0,78,0,0,29,4865,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
5021,0,0,79,69,0,4,5008,0,0,1,0,0,2,7,77,65,73,78,95,68,66,2,3,0,0,
5047,0,0,80,30,0,24,5023,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
5069,0,0,81,31,0,24,5034,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
5091,0,0,0,0,0,27,5049,0,0,4,4,0,3,7,80,69,82,70,95,68,66,1,5,0,0,1,10,0,0,1,
10,0,0,1,10,0,0,
5129,0,0,83,65,0,4,5051,0,0,1,0,0,3,7,80,69,82,70,95,68,66,2,3,0,0,
5155,0,0,84,0,0,30,5053,0,0,0,0,0,3,7,80,69,82,70,95,68,66,
5177,0,0,85,65,0,4,5057,0,0,1,0,0,2,7,77,65,73,78,95,68,66,2,3,0,0,
5203,0,0,86,69,0,4,5191,0,0,1,0,0,2,7,77,65,73,78,95,68,66,2,3,0,0,
5229,0,0,87,0,0,30,5230,0,0,0,0,0,2,7,77,65,73,78,95,68,66,
};


/*******************************************************************
	Program:	rwpbench_new.pc
	Author:		Ghassan Salem, Oracle Corp.
	Purpose:	Fixed/Variable Format Data unloader. Unloads data from
			a table into a file.
			supports only scalar types: no longs, no lobs
			Please look at the printf done for the help (in the oracle_connect function) for a full description
*******************************************************************/
/* description of debug mode
you set the debug env variable to get some messages about the processing
it is a 16-bitwise setting:
	bit 1  (%d) is just informational message about execution (e.g. what sql is being executed, .....)
	bit 2  (%d) debug machine-to-machine sockect operations
	bit 3  (%d) debug printing and inserting into the db of exec stats when using  bind values
	bit 4  (%d) is for debugging bind vars operations
	bit 5  (%d) is for debugging the send params operation
	bit 6  (%d) is for debugging get_idle_child
	bit 7  (%d) is for debugging get_ip_and_port
	bit 8  (%d) is for process_output_csv
	bit 9  (%d) is for get_master_message
	bit 10 (%d) is to debug get_next_sql
	bit 11 (%d) is to debug processing_thread
	bit 12 (%d) is to debug get_v_data
	bit 13 (%d) is for fork_proc
	bit 14 (%d) is for start_processes & setup_masterget_next_sql	
	bit 15 (%d) is for oracle_connect

create or replace type bind_values as table of varchar2(500);
/
	create or replace function get_sqlset_bindv (p_sqlset_name varchar2, p_sql_id varchar2, c_separator varchar2)
return bind_values pipelined
is
ret_str varchar2(500):=NULL;
typename    varchar2(128);
cv          varchar2(50);
nv          number;
rs          pls_integer;
begin
    for p in (with binds as (
              select d.con_dbid, p.bind_data, p.binds_captured as captured,
                     s.id as sql_seq, rownum as exec_number
              from   sys.WRI$_SQLSET_DEFINITIONS d, sys.WRI$_SQLSET_STATEMENTS s,
                     sys.WRI$_SQLSET_PLANS p
              where  d.owner||'.'||d.name=upper(p_sqlset_name)
              and d.id = s.sqlset_id AND s.id = p.stmt_id AND s.con_dbid = p.con_dbid
              and s.sql_id=p_sql_id),
              rwpbench_sqlset_binds as (select  v.con_dbid, v.exec_number, p.position, p.value_anydata
              from binds v, table(dbms_sqltune.extract_binds(v.bind_data)) p)
              select value_anydata,position
            from rwpbench_sqlset_binds
            order by exec_number, position ) loop
            if p.position=1 then
                if ret_str is not null 
                    then 
                    pipe row(ret_str);
                    ret_str:=null;
                end if;
            end if;
            if p.value_anydata is null then
                cv:='';
            else
                typename:=p.value_anydata.gettypename();
                if typename like '%CHAR%' then
                    rs:=p.value_anydata.getvarchar2(cv);
                else
                    rs:=p.value_anydata.getnumber(nv);
                    cv:=nv;
                end if;
            end if;
            if ret_str is null then
                ret_str:=cv;
            else
                ret_str:=ret_str||c_separator||cv;
            end if;
    end loop;
pipe row(ret_str);
end;

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>		//inet_addr
#include <netdb.h>		//hostent
#include <unistd.h>
#include <ifaddrs.h>
#include <net/if.h>

#include <sqlcpr.h>
#ifndef ORA_PROC
#include <oci.h>
#endif
#include <oratypes.h>


#define	BEFORE 1  /* used for mystats saving */
#define MAX_STATS 1000 /* max number of lines from v$mystat that are saved (as of 12.1, there are around 890 entries in this view) */
#define MAX_OCCURENCES	1000 /* Max nbr of columns returned by a SQL */
#define MAX_ARRSZ      500 /* Array size for fetching */
#define MAX_VAR_LEN    500 /* max size of output variable */
#define MAX_NAME_LEN	300 /* Max len of column/alias name in SQL statements */
#define MAX_FILENAME_LEN 512 /* max file name for data, log, ... files */
#define MAX_FILENAME_SIZE 513
#define MAX_DEGREE 5000 /* max nbr of threads executing SQL statements */
#define MAX_CLIENTS 100 /* max nbr of machines on which the threads run */
#define MAX_STMT_SIZE 257000 /* max size of a sql statement */
#define MAX_LINE_SIZE 1024
#ifndef NULL
#define NULL  0
#endif
#if defined(__STDC__)

void    sql_error(
	void);
#else
void    sql_error(
		/*_ void _*/ );
#endif

struct kggmd5
{
  ub4  total[2];
  ub1  buffer[64];
  ub4 *state;
  ub4  istate[4];
};
typedef struct kggmd5 kggmd5;

/* Init function for the kggmd5, it also takes in a digest pointer to
 * directly store hash values as ub4's. If your are going to pass in the
 * digest array into this, then don't pass the digest pointer into
 * kggmd5Finish() if you are owrried about performence.
 */
char	program_name[51];
#define kggmd5ini(ctx, digest)                              \
do{                                                         \
  (ctx)->total[0] = 0;                                      \
  (ctx)->total[1] = 0;                                      \
  (ctx)->state    = ((digest)) ? (digest) : (ctx)->istate;  \
  (ctx)->state[0] = 0x67452301;                             \
  (ctx)->state[1] = 0xEFCDAB89;                             \
  (ctx)->state[2] = 0x98BADCFE;                             \
  (ctx)->state[3] = 0x10325476;                             \
}while(FALSE)

/* Context based function to continously compute hash on given input stream. */
void kggmd5Update(kggmd5 *ctx, const ub1 *input, ub4 length);

/* Indicates the input stream is over to MD5 and returns the hash. If in the
 * kggmd5ini a digest array was given, pass NULL for the digest.
 */
void kggmd5Finish(kggmd5 *ctx, ub1 *digest);

/* Quick macro to compute MD5 hash and store in array of ub4's */
#define kggmd5Hash(message, length, digest)           \
do                                                    \
{                                                     \
  kggmd5 md5ctx;                                      \
  kggmd5ini(&md5ctx, (ub4*)digest);                   \
  kggmd5Update(&md5ctx, message, length);             \
  kggmd5Finish(&md5ctx, (ub1*)0);                     \
}while(FALSE)




/* global variables */
int     debug = 0, sqlid_port,sqlid_socket, separate_process_sqlid;
int      process_busy[MAX_DEGREE];
double adStat_value[MAX_STATS];

int     series_of_queries = 0;
int 	already_inserted=0; /* variable used to prevent multiple insertions into runs_desc by the same process*/
char runs_desc_rowid[20];
int	    binds_from_sqlset=0;
char    bind_sqlsetname[257];
char 	function_name[50]="process_sql";
char    indesc[] = "input_descriptor";	/* descriptor names       */
char    outdesc[] = "output_descriptor";
char    input[MAX_OCCURENCES][MAX_VAR_LEN + 1],	/* data areas */
        output[MAX_ARRSZ][MAX_OCCURENCES][MAX_VAR_LEN+1];
short   outindi[MAX_OCCURENCES];	/* output indicators      */
int retleni[MAX_OCCURENCES];
short  *iptr, lend, lent;
int     in_array_size;		/* size of input batch, i.e., number of rows */
int     out_array_size;		/* size of input batch, i.e., number of rows */
int     max_array_size = MAX_OCCURENCES;	/* maximum arrays size used for allocates */
int     cursor_open = 0;
char	v_host_name[257];
char v_sql_id[30];
int	v_sql_exec_id;
long    real_time,first_time,real_time_get_sqlid;
/* A global flag for the error routine. */
int     parse_flag = 0;
/* Arrays used to store exec times and returned rows when using bind variables */
#define MAX_EXEC_BINDS 100000 /* max nbr of execution using bind vars to keep before updating the response_times table */
int     aret_rows[MAX_EXEC_BINDS];
int     abind_file_line[MAX_EXEC_BINDS];
int     exec_binds_counter = 0;
int sessiontimezone_seconds=0;
double  aexec_timest[MAX_EXEC_BINDS];
long    aexec_times[MAX_EXEC_BINDS];
long    aexec_first_fetch[MAX_EXEC_BINDS];
int     socket_id;
int     socket_is_opened = -1;
struct timeval awr_time;
int awr_period=0;
int	global_socket=0;
int 	connect_perf=0;
int	mypid,  VVChild_n;
int sqlid_proc=-1;
int	seq_nbr=0;
int mysid, myinstance;
char admin_user[256];
char	sp_sql_id[20];
struct timeval time_first_fetch;
char logfile_dir[MAX_FILENAME_SIZE];
char 	db_name[20]="main_db"; // this is to be used when we have to send the response_times data to a different database
char    run_desc[101];
int	v_db_version;
// by default we'll be using main_db, if the parfile has a different spec, db_name will be changed from main_db to perf_db

/* Following is the list of global vars that are read from the parfile, and are also send via
send_params, and so received with get_master_message*/
FILE *debug_file, *out_csv;
int	use_dbms_sqltune0=0;
char    stop_file_name[MAX_FILENAME_SIZE] = "/tmp/oraunloader.stop";
int     socket_port_nbr;
int     bind_results_to_db = 0;
char    send_results_host[256];
char    socket_host_ip[50],c_bind_file_separator;
int     flush_results_every = 999999999;
char 	bind_file_name[MAX_FILENAME_SIZE];
char    log_file_name[MAX_FILENAME_SIZE];
char    debug_file_name[MAX_FILENAME_SIZE];
int     silent = 0;
int	release_px_slaves=0;
char    comma[2]= ",", exec_stats_file_name[MAX_FILENAME_SIZE];
int     comma_len = 1;
int	save_mystats=0;
int	rows_to_spool=2<<29;
int     save_sqlmon = 0;
char    file_name[MAX_FILENAME_SIZE];
int     think_time_min = 0;	/* think time min at the start of every query */
int     think_time_max = 0;	/* think time max at the start of every query */
int     exec_count = 1;
long 	max_time=0;
char    query_name[200], sqlset_name[31],sqlmon_type[21],
	saved_username[256],perf_db_uname[256],username[256],username1[256];
char    setup_script[MAX_STMT_SIZE];	/* statement variable     */
char    dyn_statement[MAX_STMT_SIZE];	/* statement variable     */
/* EXEC SQL VAR dyn_statement IS STRING(MAX_STMT_SIZE); */ 

/* EXEC SQL VAR setup_script IS STRING(MAX_STMT_SIZE); */ 

int	check_for_quit_every=10000000;
int     trial_nbr, cumulative_rows, sqlset_save,print_my_stats,print_pga_stats;
int     max_rows=0;
int	degree=0;
int	print_plan,save_sqlmon;


/* end var section*/
int	sockets_list[MAX_CLIENTS], *sockets_listf, comp_trial_nbr,nbr_clients=0;
int is_numeric(const char *p) {
     if (*p) {
          char c;
          while ((c=*p++)) {
                if (!isdigit(c)) return 0;
          }
          return 1;
      }
      return 0;
}

void my_print(char *fmt, ...)
{
        time_t now;
        char str[3001];
        char time_s[100],deb_fname[MAX_FILENAME_SIZE];
        time(&now);
        va_list args;
        va_start(args, fmt);
        vsnprintf(str,3000, fmt, args);
        va_end(args);
        if (debug_file_name[0]!='\0' && debug_file==NULL){
        	snprintf(deb_fname,MAX_FILENAME_LEN,"%s_%d",debug_file_name,mypid);
        	debug_file=fopen(deb_fname,"a");
        }
        sprintf(time_s,"pid=%d, in function %s %s",mypid,function_name,ctime(&now));
        time_s[strlen(time_s)-1]='\0';
        printf ("%s : %s\n",time_s,str);
        if (debug_file!=NULL) fprintf(debug_file,"%s : %s\n",time_s,str);
}

int main(
	int argc,
	char *argv[])
{

	/* Connect to the database. */
	saved_username[0] = '\0';
	printf("Starting rwpbench. Version dated:%s %s\n",__DATE__,__TIME__);
	/* EXEC SQL DECLARE main_db DATABASE; */ 

	/* EXEC SQL DECLARE perf_db DATABASE; */ 

	time_first_fetch.tv_sec=0;
	debug_file_name[0]='\0';
	debug_file=NULL;
	if (oracle_connect(argc, argv) != 0)
		exit(1);
	exit(0);
}


void sql2id(char *txt, ub1 *sql_id)
{
  ub4 d[4] = {0,0,0,0};
  ub1 *xx ;
  ub8 *zz;
  volatile int i;
  ub4 ddd;
  
  
  kggmd5Hash(txt, strlen(txt)+1, d);


  xx = (ub1 *) &d[2];

  // reverse last two ub4's 
  ddd = d[3];
  d[3] = d[2];
  d[2] = ddd;

  zz = (ub8 *)xx;

  // and take 5 bits times 13 

  sql_id[13]=0;
  for (i=0; i<=12; i++)
  {
    sql_id[12-i] = "0123456789abcdfghjkmnpqrstuvwxyz" [ (*zz) & 0x1f ];
    *zz >>=5;
  }
}

int sendall(int s, char *buf, int len)
{
        int total = 0;        /* how many bytes we've sent */
        int bytesleft = len; /* how many we have left to send */                                                  
        int n=0;
        int retries=0;
        struct timespec tp={0,500};

        while(total < len)
        {
                n = send(s, buf+total, bytesleft, 0);
                //my_print("sent %s\n",buf+total);
                if (n == -1)
                {
                   /* handle errors here,
                      plus check for EWOULDBLOCK
                      and then nanosleep()
                   */
                   return n;
                }
                total += n;
                bytesleft -= n;
        }
		return n;
}
void send_msg_to_master(int master_socket, char *msg)
{
	int msg_len=strlen(msg);
	sendall(master_socket,msg,msg_len);
}
int get_ip_and_port( char *master_ip,
	int *master_port, int *sqlid_port)
{
	struct sockaddr_in *s4, name,name1;
	struct sockaddr_in6 *s6;
	int	debug_level=1<<7;
	/* ipv6 addresses have to fit in this buffer */
	char buf[64], saved_function_name[50];
	int sock, len_inet, ret_code,sock1;
	unsigned	m_port;

	struct ifaddrs *myaddrs, *ifa;
	int status;
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"get_ip_and_port");
	if (debug&debug_level) my_print("no remote machines, so get ip and port\n");

	status = getifaddrs(&myaddrs);
	if (status != 0){
		perror("getifaddrs failed!");
		exit(1);
	}

	for (ifa = myaddrs; ifa != NULL; ifa = ifa->ifa_next){
		if (NULL == ifa->ifa_addr){
			continue;
		}
		if ((ifa->ifa_flags & IFF_UP) == 0) {
			continue;
		}
		if (AF_INET == ifa->ifa_addr->sa_family){
			s4 = (struct sockaddr_in *)(ifa->ifa_addr);
			if (NULL != inet_ntop(ifa->ifa_addr->sa_family, (void *)&(s4->sin_addr), buf, sizeof(buf))){
				strncpy(master_ip, buf,49);
			}
		}/*
		else if (AF_INET6 == ifa->ifa_addr->sa_family) {
			s6 = (struct sockaddr_in6 *)(ifa->ifa_addr);
			if (NULL != inet_ntop(ifa->ifa_addr->sa_family, (void *)&(s6->sin6_addr), buf, sizeof(buf))) {
				strncpy(master_ip, buf,49);
			}
		}*/
	}
	freeifaddrs(myaddrs);
	sock = socket (PF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
		printf ("socket error\n");
		exit (EXIT_FAILURE);
	}

	/* Give the socket a name. */
	memset(&name,0,sizeof(name));
	name.sin_family = AF_INET;
	name.sin_port = htons (0);
	inet_aton (master_ip,&name.sin_addr);
	if (bind (sock, (struct sockaddr *) &name, sizeof (name)) < 0)
	{
		printf ("bind error\n");
		exit (EXIT_FAILURE);
	}
	len_inet=sizeof(name);
	ret_code=getsockname(sock, (struct sockaddr *) &name, &len_inet);
	*master_port=(int)ntohs(name.sin_port);
	m_port=(int)ntohs(name.sin_port);
// getting port for sqlid queries
	*sqlid_port=*master_port+1;
	if(debug&debug_level) my_print("got master_ip=%s, port=%d sqlid_port=%d, and ret_code=%d\n",master_ip, *master_port, *sqlid_port,ret_code);
/*	sock1 = socket (PF_INET, SOCK_STREAM, 0);
	if (sock1 < 0)
	{
		printf ("sqlid socket error\n");
		exit (EXIT_FAILURE);
	}

	memset(&name1,0,sizeof(name1));
	name1.sin_family = AF_INET;
	name1.sin_port = htons (*sqlid_port);
	inet_aton (master_ip,&name1.sin_addr);
	if (bind (sock1, (struct sockaddr *) &name1, sizeof (name1)) < 0)
	{
		printf ("bind error for sqlid socket\n");
		exit (EXIT_FAILURE);
	}
	len_inet=sizeof(name1);
	ret_code=getsockname(sock1, (struct sockaddr *) &name1, &len_inet);
	*sqlid_port=(int)ntohs(name1.sin_port);
	if(debug&debug_level) my_print("got master_ip=%s, port=%d sqlid_port=%d, and ret_code=%d\n",master_ip, *master_port, *sqlid_port,ret_code);
	close(sock1);
*/    close(sock);
	strcpy(function_name,saved_function_name);
	return 0;

}
int check_if_master( char *master_ip ){
	struct sockaddr_in *s4;
	struct sockaddr_in6 *s6;
	/* ipv6 addresses have to fit in this buffer */
	char buf[64];

	struct ifaddrs *myaddrs, *ifa;
	int status;

	status = getifaddrs(&myaddrs);
	if (status != 0){
		perror("getifaddrs failed!");
		exit(1);
	}

	for (ifa = myaddrs; ifa != NULL; ifa = ifa->ifa_next){
		if (NULL == ifa->ifa_addr){
			continue;
		}
		if ((ifa->ifa_flags & IFF_UP) == 0) {
			continue;
		}
		if (AF_INET == ifa->ifa_addr->sa_family){
			s4 = (struct sockaddr_in *)(ifa->ifa_addr);
			if (NULL != inet_ntop(ifa->ifa_addr->sa_family, (void *)&(s4->sin_addr), buf, sizeof(buf))){
				if (!strcmp(master_ip, buf)) return 1;
			}
		}
		else if (AF_INET6 == ifa->ifa_addr->sa_family) {
			s6 = (struct sockaddr_in6 *)(ifa->ifa_addr);
			if (NULL != inet_ntop(ifa->ifa_addr->sa_family, (void *)&(s6->sin6_addr), buf, sizeof(buf))) {
				if (!strcmp(master_ip, buf)) return 1;
			}
		}
	}
	freeifaddrs(myaddrs);
	return 0;

}


int asked_to_quit(
	)
{
	int ret_c;
	fd_set inc_set, save_set;
	struct timeval tv;
	char check_message[5]="NULL", cmd[10];
	if (global_socket!=0) {
		FD_ZERO(&save_set);
		FD_SET(global_socket,&save_set);
		tv.tv_sec = 0;
		tv.tv_usec = 5;
		ret_c = select(FD_SETSIZE, &save_set, NULL, NULL, &tv);
		if (ret_c>0) { // there's a msg in the socket
			ret_c=recv(global_socket,check_message,4,MSG_PEEK);
			if (ret_c>0 && !strncasecmp(cmd, "exit", 4)) return 1;
		}
		return 0;
	}
	if (access(stop_file_name, R_OK) == 0)
	{
		return 1;
	}
	return 0;
}
int ask_for_sqlid(char * true_sql_id, int *true_child_nbr
	)
{
	int ret_c, debug_level=1<<6;
	fd_set inc_set, save_set;
	struct timeval tv;
	char check_message[50]="NULL", cmd[10], *p,msg_get_sqlid[50];
	sprintf(msg_get_sqlid,"sqlid=%d;%d\n",mysid,myinstance);
	send_msg_to_master(sqlid_socket,msg_get_sqlid);
	FD_ZERO(&save_set);
	FD_SET(sqlid_socket,&save_set);
	tv.tv_sec = 1;
	tv.tv_usec = 0;
	*true_child_nbr=-1;
	while(1){
		if (debug&debug_level) my_print("waiting for message from parent proc on socket %d",sqlid_socket);
		ret_c = select(FD_SETSIZE, &save_set, NULL, NULL, &tv);
		if (ret_c>0) { // there's a msg in the socket
			ret_c=recv(sqlid_socket,check_message,49,0);//MSG_PEEK);
			if (ret_c>0) {
				p=strchr(check_message,';');
				*p='\0';
				p++;
				strcpy(true_sql_id,check_message);
				*true_child_nbr=(int)atol(p);
				return;
			} else return ;
		}
	}
}

int get_host_ip(
	)
{
	struct hostent *he;
	struct in_addr **addr_list;
	int     i;
	struct sockaddr_in sa;
	int     result =
		inet_pton(AF_INET, send_results_host, &(sa.sin_addr));
	if (result)
		strncpy(socket_host_ip, send_results_host,49);
	else {
		if ((he = gethostbyname(send_results_host)) == NULL) {
			return 0;
		}
		//Cast the h_addr_list to in_addr , since h_addr_list also has the ip address in long format only
		addr_list = (struct in_addr **) he->h_addr_list;

		for (i = 0; addr_list[i] != NULL; i++) {
			//Return the first one;
			strncpy(socket_host_ip, inet_ntoa(*addr_list[i]),49);
		}
	}
	return 1;
}
int open_socket_to_master(char *master_ip, int master_port){
	// this will open a socket to the master
	// if it could not connect immediately, it will wait for 10 seconds and retry
	// it will wait at most 5 minutes before quitting
	struct sockaddr_in serv_addr;
	char  saved_function_name[50];
	int wait_max=300, wait_time=10, socket_id,debug_level=1<<2;
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"open_socket_to_master");
	if (debug&debug_level) my_print("opening socket to %s, port %d\n",master_ip, master_port);
	while (wait_max>0){
		if ((socket_id = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
			my_print("Setting up connection: Could not create socket will not send results\n");
			return -1;
		}

		memset(&serv_addr, '0', sizeof(serv_addr));

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(master_port);

		if (inet_pton(AF_INET, master_ip, &serv_addr.sin_addr) <= 0) {
			my_print("Setting up connection: problem talking to host ip %s errno=%d\n", socket_host_ip, errno);
			strcpy(function_name,saved_function_name);
			return -1;
		}
		if (debug&debug_level) my_print("converted ip, will connect\n");
		if (connect (socket_id, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
			wait_max-=wait_time;
			my_print("Got an error errno=%d\n",errno);
			sleep(wait_time);
		} else 	{
			strcpy(function_name,saved_function_name);
			return(socket_id);
			}
	}
	strcpy(function_name,saved_function_name);
	return -1;
}
int get_lf(int socket, char *buffer, int maxlen)
{
	char c, *buf=buffer;
	int mx=0,br;
	while(mx<maxlen){
		br=read(socket,&c,1);
		//my_print("got %c\n",c);
		if (br==1 && c!='\n') buffer[mx++]=c;
		else break;
	}
	buffer[mx]='\0';
	return mx-1;
}

void send_socket(int trial_nbr,
	double exec_ts,
	long exec_time,
	long first_fetch,
	int num_rows,
	int bind_file_line)
{
	struct sockaddr_in serv_addr;
	char  saved_function_name[50];
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"send_socket");
	int	ret_c,debug_level=1<<2;
	if (debug&debug_level)
		my_print("sockect_host_ip=%s, in send socket_is_opened=%d \n", socket_host_ip, socket_is_opened);
	if (socket_host_ip[0] == '\0')
		socket_is_opened = 0;
	if (socket_is_opened == -1) {
		/* open socket */
		if (debug&debug_level) my_print("opening socket to %s\n",socket_host_ip);
		socket_is_opened = 0;
		if ((socket_id = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
			my_print("Setting up connection: Could not create socket will not send results\n");
			strcpy(function_name,saved_function_name);
			return;
		}

		memset(&serv_addr, '0', sizeof(serv_addr));

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(socket_port_nbr);

		if (inet_pton(AF_INET, socket_host_ip, &serv_addr.sin_addr) <= 0) {
			my_print("Setting up connection: problem talking to host ip %s errno=%d\n", socket_host_ip, errno);
			strcpy(function_name,saved_function_name);
			return;
		}

		if (connect (socket_id, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
			my_print("Setting up connection: problem connecting to host ip %s errno=%d\n", socket_host_ip, errno);
			strcpy(function_name,saved_function_name);
			return;
		}
		/* if we're here then we opened the socket */
		socket_is_opened = 1;
	}
	if (socket_is_opened == 1) {
		char    message[500];
		if (debug&debug_level) my_print("sending data for query=%s, socket_id=%d from pid=%d\n",query_name,socket_id,mypid);
		sprintf(message, "|%d;%s;%d;%lf;%ld;%ld;%d;%d", trial_nbr,
			query_name, mypid, exec_ts, exec_time,first_fetch,
			num_rows,bind_file_line);
		ret_c=write(socket_id, message, strlen(message));
	}
	strcpy(function_name,saved_function_name);

}
#define RES_ARRAY_SIZE 1000
void insert_exec_data(
	int trial_nbr,
	char *query_name,
	int mypid)
{
	int     i, len, clen, bind_file_lines[RES_ARRAY_SIZE],trial_nbrs[RES_ARRAY_SIZE], ret_rows[RES_ARRAY_SIZE], pids[RES_ARRAY_SIZE];
	long    exec_t[RES_ARRAY_SIZE],exec_ff[RES_ARRAY_SIZE];
	int debug_level=1<<4;
	double  time_st[RES_ARRAY_SIZE];
	char    qnames[RES_ARRAY_SIZE][100], saved_function_name[50];
	clen = 0;
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"insert_exec_data");
	if (debug&debug_level)
		my_print("writing results to db, exec_bind_counter=%d, db_name=%s sessiontimezone_seconds=%d\n",exec_binds_counter, db_name,sessiontimezone_seconds);
	for (clen = 0; clen < RES_ARRAY_SIZE; clen++) {
		trial_nbrs[clen] = trial_nbr;
		pids[clen] = mypid;
		strncpy(qnames[clen], query_name, 100);
	}
	clen = 0;
	for (i = 0; i < exec_binds_counter; i++) {
		ret_rows[clen] = aret_rows[i];
		exec_t[clen] = aexec_times[i];
		time_st[clen]=aexec_timest[i]+sessiontimezone_seconds;
		bind_file_lines[clen]=abind_file_line[i];
		exec_ff[clen]=aexec_first_fetch[i];
		if (clen == RES_ARRAY_SIZE-1) {
			/* exec sql at :db_name insert /o+ append o/into response_times(
				query_name,
				process_id,
				inst_id,
				trial_nbr,
				rows_p,
				elapsed_t,
				elapsed_first_fetch,
				executions,
				time_st,
				bind_file_line_nbr) values(
				:qnames,
				:pids,
				sys_context('USERENV',
					    'INSTANCE'),
				:trial_nbrs,
				:ret_rows,
				:exec_t,
				:exec_ff,
				1,
				to_timestamp('01011970','ddmmyyyy')+numtodsinterval(:time_st,'second'),
				:bind_file_lines
				); */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "insert /*+ append +*/ into response_times ( query_name , p\
rocess_id , inst_id , trial_nbr , rows_p , elapsed_t , elapsed_first_fetch , e\
xecutions , time_st , bind_file_line_nbr ) values ( :b1 , :b2 , sys_context ( \
'USERENV' , 'INSTANCE' ) , :b3 , :b4 , :b5 , :b6 , 1 , to_timestamp ( '0101197\
0' , 'ddmmyyyy' ) + numtodsinterval ( :b7 , 'second' ) , :b8 ) ";
   sqlstm.iters = (unsigned int  )1000;
   sqlstm.offset = (unsigned int  )5;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)qnames;
   sqlstm.sqhstl[0] = (unsigned long )100;
   sqlstm.sqhsts[0] = (         int  )100;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqharc[0] = (unsigned long  *)0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)pids;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )sizeof(int);
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqharc[1] = (unsigned long  *)0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)trial_nbrs;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[2] = (         int  )sizeof(int);
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqharc[2] = (unsigned long  *)0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)ret_rows;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )sizeof(int);
   sqlstm.sqindv[3] = (         short *)0;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqharc[3] = (unsigned long  *)0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)exec_t;
   sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
   sqlstm.sqhsts[4] = (         int  )sizeof(long);
   sqlstm.sqindv[4] = (         short *)0;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqharc[4] = (unsigned long  *)0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)exec_ff;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
   sqlstm.sqhsts[5] = (         int  )sizeof(long);
   sqlstm.sqindv[5] = (         short *)0;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqharc[5] = (unsigned long  *)0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)time_st;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[6] = (         int  )sizeof(double);
   sqlstm.sqindv[6] = (         short *)0;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqharc[6] = (unsigned long  *)0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)bind_file_lines;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[7] = (         int  )sizeof(int);
   sqlstm.sqindv[7] = (         short *)0;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqharc[7] = (unsigned long  *)0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)db_name;
   sqlstm.sqhstl[8] = (unsigned long )20;
   sqlstm.sqhsts[8] = (         int  )20;
   sqlstm.sqindv[8] = (         short *)0;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			/* exec sql at :db_name commit; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )56;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)db_name;
   sqlstm.sqhstl[0] = (unsigned long )20;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			if (debug&debug_level)
				my_print("insert %d rows, sqlca.sqlcode=%d\n", sqlca.sqlerrd[2], sqlca.sqlcode);
			clen = 0;
		} else
			clen++;
	}
	if (clen) {
		/* exec sql at :db_name for :clen insert into response_times(
				query_name,
				process_id,
				inst_id,
				trial_nbr,
				rows_p,
				elapsed_t,
				elapsed_first_fetch,
				executions,
				time_st,
				bind_file_line_nbr) values(
				:qnames,
				:pids,
				sys_context('USERENV',
					    'INSTANCE'),
				:trial_nbrs,
				:ret_rows,
				:exec_t,
				:exec_ff,
				1,
				to_timestamp('01011970','ddmmyyyy')+numtodsinterval(:time_st,'second'),
				:bind_file_lines
				); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into response_times ( query_name , process_id , inst\
_id , trial_nbr , rows_p , elapsed_t , elapsed_first_fetch , executions , time\
_st , bind_file_line_nbr ) values ( :b2 , :b3 , sys_context ( 'USERENV' , 'INS\
TANCE' ) , :b4 , :b5 , :b6 , :b7 , 1 , to_timestamp ( '01011970' , 'ddmmyyyy' \
) + numtodsinterval ( :b8 , 'second' ) , :b9 ) ";
  sqlstm.iters = (unsigned int  )clen;
  sqlstm.offset = (unsigned int  )75;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)qnames;
  sqlstm.sqhstl[0] = (unsigned long )100;
  sqlstm.sqhsts[0] = (         int  )100;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)pids;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)trial_nbrs;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)ret_rows;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)exec_t;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[4] = (         int  )sizeof(long);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)exec_ff;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[5] = (         int  )sizeof(long);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)time_st;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )sizeof(double);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)bind_file_lines;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)db_name;
  sqlstm.sqhstl[8] = (unsigned long )20;
  sqlstm.sqhsts[8] = (         int  )20;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if (debug&debug_level)
			my_print("insert %d rows, sqlca.sqlcode=%d\n",
			       sqlca.sqlerrd[2], sqlca.sqlcode);
		clen = 0;
	}
	/* exec sql at :db_name commit; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )126;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)db_name;
 sqlstm.sqhstl[0] = (unsigned long )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	strcpy(function_name,saved_function_name);
}

void print_exec_data(
	int trial_nbr,
	char *query_name,
	int mypid)
{
	FILE   *exec_stats;
	int     i, len, clen,debug_level=1<<4;
	char    exec_stats_file[MAX_FILENAME_SIZE], output[250],
		write_buffer[1000000], *ptr, saved_function_name[50];
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"print_exec_data");
	if (debug&debug_level) my_print ("file=%s, bind_results_to_db=%d\n",exec_stats_file_name,bind_results_to_db);
	if (exec_stats_file_name[0]=='\0'){
		if (bind_results_to_db)
			insert_exec_data(trial_nbr, query_name, mypid);
		return;
	}
	sprintf(exec_stats_file, "%s.%d", exec_stats_file_name, mypid);
	if ((exec_stats = fopen(exec_stats_file, "a")) == NULL) {
		my_print("Cannot open exec stats file %s\n",
		       exec_stats_file);
		if (bind_results_to_db)
			insert_exec_data(trial_nbr, query_name, mypid);
		strcpy(function_name,saved_function_name);
		return;
	}
	ptr = write_buffer;
	clen = 0;
	for (i = 0; i < exec_binds_counter; i++) {
		snprintf(output, 250, "%d;%s;%d;%lf;%ld;%ld,%d;%d\n", trial_nbr,
			 query_name, mypid, aexec_timest[i], aexec_times[i],aexec_first_fetch[i],
			 aret_rows[i],abind_file_line[i]);
		len = strlen(output);
		memcpy(ptr, output, len);
		ptr += len;
		clen += len;
		if (clen >= 1000000 - 250) {
			fwrite(write_buffer, clen, 1, exec_stats);
			ptr = write_buffer;
			clen = 0;
		}
	}
	if (clen > 0)
		fwrite(write_buffer, clen, 1, exec_stats);
	fclose(exec_stats);
	if (bind_results_to_db)
		insert_exec_data(trial_nbr, query_name, mypid);
	strcpy(function_name,saved_function_name);
}
void get_sql_id()
{
	/* varchar *dyn_statement_id; */ 
varchar *dyn_statement_id;

	char v_set_app_info[100],saved_function_name[50];
	int debug_level=1<<8,loblen,sql_len;
	/* EXEC SQL VAR dyn_statement_id IS LONG VARCHAR(MAX_STMT_SIZE); */ 

	strcpy(saved_function_name,function_name);
	strcpy(function_name,"get_sql_id");
	/* EXEC ORACLE OPTION(char_map = STRING); */ 

	/* EXEC SQL WHENEVER SQLERROR continue; */ 

	sql_len=strlen(dyn_statement);
	if (!strncasecmp(query_name,"qb_name",7)) {
		char *pch, qname[200];
		if (debug&debug_level) my_print("query_name is like qb_name\n");
		pch=strcasestr(dyn_statement,"qb_name");
		if (debug&debug_level) my_print("pch =%s\n",pch);
		if (pch) { /* found qb_name */
			pch+=7;
			while(*pch==' '||*pch=='(')pch++;
			int i=0;
			while(*pch!=')'&&*pch!=' '&&i<198) {
				qname[i]=*pch;
				i++;
				pch++;
			}
			qname[i]='\0';
			strcpy(query_name,qname);
		}
	}
	if (sql_len>5) {
		if(use_dbms_sqltune0==1) {
			OCIClobLocator	*SQL_For_sql_id;
			dyn_statement_id=(varchar *) malloc(5+sql_len);
			memset(dyn_statement_id->arr,'\0',sql_len);
			dyn_statement_id->arr[0]='\n';
			dyn_statement_id->arr[1]='\n';
			dyn_statement_id->arr[2]='\0';
			strcat(dyn_statement_id->arr,dyn_statement);
			dyn_statement_id->len=sql_len;
			/* exec sql  at main_db allocate :SQL_For_sql_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )145;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&SQL_For_sql_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			if (debug&debug_level) my_print("after alloc, sql_len=%d, \n",sql_len);
			/* exec sql at main_db lob create temporary  :SQL_For_sql_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )171;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&SQL_For_sql_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			/* exec sql at main_db lob write one :sql_len from :dyn_statement_id into :SQL_For_sql_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )197;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&sql_len;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)dyn_statement_id;
   sqlstm.sqhstl[1] = (unsigned long )257004;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&SQL_For_sql_id;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(void *);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)0;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			if (debug&debug_level) {
				  /* exec sql at main_db lob describe :SQL_For_sql_id get length into :loblen; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 13;
      sqlstm.arrsiz = 9;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )239;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&SQL_For_sql_id;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&loblen;
      sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				  my_print("length of lob is %d\n",loblen);
			}
			strcpy(v_set_app_info,"begin :a:=sys.dbms_sqltune_util0.sqltext_to_sqlid(:clob||chr(0));end;"); 
			/* exec sql at main_db prepare get_sql_id from :v_set_app_info; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )269;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)v_set_app_info;
   sqlstm.sqhstl[0] = (unsigned long )100;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			/* exec sql at main_db execute get_sql_id using :sp_sql_id,:SQL_For_sql_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )295;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)sp_sql_id;
   sqlstm.sqhstl[0] = (unsigned long )20;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&SQL_For_sql_id;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(void *);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			if (sqlca.sqlcode!=0) sp_sql_id[0]='\0';
			if (debug&debug_level||sqlca.sqlcode!=0)
				my_print("tried to get sql_id from dbms_sqltune got %s sqlca.sqlcode=%d\n",
				       sp_sql_id,sqlca.sqlcode);
			/* EXEC SQL lob FREE temporary :SQL_For_sql_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )325;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&SQL_For_sql_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			free(dyn_statement_id);
		} else
			sql2id(dyn_statement,sp_sql_id);
		if (sp_sql_id[0]!='\0') strcpy(v_sql_id,sp_sql_id);
	}
	strcpy(function_name,saved_function_name);
}
int process_sql(
	FILE * out_fp,
	char *bind_file_name,
	int think_time_min,
	int think_time_max,
	long max_time_rem/*,
	long *executions*/)
{
	int     ticks, tt, input_count, occurs, vAnsi_Type, vInput_len, i,buffer_size,output_count,type,length,
		vIvalue, j, bind_names_len[20], sql_bind_names_len[21];
	long    clk_ticks,execution_time;
	double  dValue;
	FILE *bind_file;
	int debug_level=1<<8;
	char   name[MAX_OCCURENCES][MAX_NAME_LEN],saved_function_name[50],*tn, bind_types[100][100],c_separator[2], line[1000], *str, *cptr,name_i[100],
		bind_names[100][100],sql_bind_names[101][100], v_set_app_info[500];
	int type_a[MAX_OCCURENCES], len[MAX_OCCURENCES],prec[MAX_OCCURENCES];
	int *ipRetLen,first_call=1;
	struct timeval B_time, E_time;
	/* EXEC SQL WHENEVER SQLERROR DO sql_error(); */ 

	exec_binds_counter=0;
	c_separator[0]=c_bind_file_separator;
	c_separator[1]='\0';
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"process_sql");
	execution_time=0;
	/* Allocate the input and output descriptors. */
	/* EXEC SQL FOR :max_array_size
		ALLOCATE DESCRIPTOR GLOBAL :outdesc with max 1000; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )max_array_size;
 sqlstm.offset = (unsigned int  )344;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )1000;
 sqlstm.sqhstv[0] = (unsigned char  *)outdesc;
 sqlstm.sqhstl[0] = (unsigned long )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error();
}



	/* Process SQL statements. */

	/* Get the statement.  Break on "exit". */

	/* Prepare the statement and declare a cursor. */
	parse_flag = 1;		/* Set a flag for sql_error(). */
	/* EXEC SQL at main_db declare  S statement; */ 

	if (debug&debug_level)
		my_print("Executing statement %s\n", dyn_statement);
	if (sqlca.sqlcode<0) {
		/* EXEC SQL DEALLOCATE DESCRIPTOR GLOBAL :outdesc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )363;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)outdesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		return(sqlca.sqlcode);
	}
	/* EXEC SQL at main_db PREPARE S FROM :dyn_statement; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )382;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)dyn_statement;
 sqlstm.sqhstl[0] = (unsigned long )257000;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error();
}


	if (sqlca.sqlcode<0) {
		int sc=sqlca.sqlcode;
		/* EXEC SQL DEALLOCATE DESCRIPTOR GLOBAL :outdesc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )408;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)outdesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		return(sc);
	}
	parse_flag = 0;		/* Unset the flag. */
	seq_nbr++;
	snprintf(v_set_app_info,499,"begin  "
		"\ndbms_application_info.set_module('%s','%d');"
		"\nend;",query_name,seq_nbr);
	/* exec sql at main_db execute immediate  :v_set_app_info; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )427;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)v_set_app_info;
 sqlstm.sqhstl[0] = (unsigned long )500;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error();
}


	if (sqlca.sqlcode!=0) 
		my_print("could not set app info with statement=%s\n",v_set_app_info);
	/* EXEC SQL at main_db DECLARE C CURSOR FOR S; */ 

	if (sqlca.sqlcode<0) return(sqlca.sqlcode);
	/* EXEC SQL DESCRIBE OUTPUT S USING DESCRIPTOR GLOBAL :outdesc; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )453;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)outdesc;
 sqlstm.sqhstl[0] = (unsigned long )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error();
}


	if (sqlca.sqlcode<0) {
		/* EXEC SQL DEALLOCATE DESCRIPTOR GLOBAL :outdesc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )479;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)outdesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		return(sqlca.sqlcode);
	}
	if (debug&debug_level)
		my_print("After DESC OUTPUT\n");

	/* EXEC SQL GET DESCRIPTOR GLOBAL :outdesc :output_count = COUNT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )498;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)outdesc;
 sqlstm.sqhstl[0] = (unsigned long )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&output_count;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error();
}


	if (debug&debug_level)
		my_print("After Get Desc\n");
	if (sqlca.sqlcode<0) {
		/* EXEC SQL DEALLOCATE DESCRIPTOR GLOBAL :outdesc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )521;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)outdesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		return(sqlca.sqlcode);
	}
	if (out_array_size < 1)	/* must have at least one */
		out_array_size = MAX_ARRSZ;
	out_array_size=1;
	buffer_size = 0;
	for (i = 0; i < output_count; i++) {
		occurs = i + 1;
	      /* EXEC SQL GET DESCRIPTOR GLOBAL :outdesc VALUE :occurs :type_a[i] = TYPE,: name[i] = NAME,:len[i] = OCTET_LENGTH,
	      :prec[i] =SCALE; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 13;
       sqlstm.arrsiz = 9;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )540;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)outdesc;
       sqlstm.sqhstl[0] = (unsigned long )0;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)&occurs;
       sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&type_a[i];
       sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[2] = (         int  )0;
       sqlstm.sqindv[2] = (         short *)0;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)name[i];
       sqlstm.sqhstl[3] = (unsigned long )300;
       sqlstm.sqhsts[3] = (         int  )0;
       sqlstm.sqindv[3] = (         short *)0;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)&len[i];
       sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[4] = (         int  )0;
       sqlstm.sqindv[4] = (         short *)0;
       sqlstm.sqinds[4] = (         int  )0;
       sqlstm.sqharm[4] = (unsigned long )0;
       sqlstm.sqadto[4] = (unsigned short )0;
       sqlstm.sqtdso[4] = (unsigned short )0;
       sqlstm.sqhstv[5] = (unsigned char  *)&prec[i];
       sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[5] = (         int  )0;
       sqlstm.sqindv[5] = (         short *)0;
       sqlstm.sqinds[5] = (         int  )0;
       sqlstm.sqharm[5] = (unsigned long )0;
       sqlstm.sqadto[5] = (unsigned short )0;
       sqlstm.sqtdso[5] = (unsigned short )0;
       sqlstm.sqphsv = sqlstm.sqhstv;
       sqlstm.sqphsl = sqlstm.sqhstl;
       sqlstm.sqphss = sqlstm.sqhsts;
       sqlstm.sqpind = sqlstm.sqindv;
       sqlstm.sqpins = sqlstm.sqinds;
       sqlstm.sqparm = sqlstm.sqharm;
       sqlstm.sqparc = sqlstm.sqharc;
       sqlstm.sqpadto = sqlstm.sqadto;
       sqlstm.sqptdso = sqlstm.sqtdso;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) sql_error();
}


	      if (sqlca.sqlcode<0) return(sqlca.sqlcode);
		if (debug&debug_level)
			my_print("name= %s, len %d, precision %d type %d\n",
			       name[i], len[i], prec[i], type_a[i]);
		if (len[i] == 0)
			len[i] = MAX_VAR_LEN;
		if (len[i] > buffer_size)
			buffer_size = len[i] + 1;
		type = type_a[i];
		iptr = (short *) &outindi[i];
		ipRetLen = (int *) &retleni[i];
		switch (type) {
		case 1:
		case 96:
		case 97:
		case 12:
		case 187:
		case 180:
		case 181:
		case 231:
		case 2:
		case 21:
		case 22:
			type_a[i] = 2;
			break;
		default:
			break;
		}
		type = 5;
		length = MAX_VAR_LEN ;/*-1;*/
	      /* EXEC SQL SET DESCRIPTOR GLOBAL :outdesc VALUE :occurs TYPE =:type, LENGTH =:length; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 13;
       sqlstm.arrsiz = 9;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )579;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)outdesc;
       sqlstm.sqhstl[0] = (unsigned long )0;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)&occurs;
       sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&type;
       sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[2] = (         int  )0;
       sqlstm.sqindv[2] = (         short *)0;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)&length;
       sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[3] = (         int  )0;
       sqlstm.sqindv[3] = (         short *)0;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqphsv = sqlstm.sqhstv;
       sqlstm.sqphsl = sqlstm.sqhstl;
       sqlstm.sqphss = sqlstm.sqhsts;
       sqlstm.sqpind = sqlstm.sqindv;
       sqlstm.sqpins = sqlstm.sqinds;
       sqlstm.sqparm = sqlstm.sqharm;
       sqlstm.sqparc = sqlstm.sqharc;
       sqlstm.sqpadto = sqlstm.sqadto;
       sqlstm.sqptdso = sqlstm.sqtdso;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) sql_error();
}


	      /* EXEC SQL FOR :out_array_size
	      SET DESCRIPTOR GLOBAL :outdesc VALUE :occurs REF DATA =:output[i], REF INDICATOR =:iptr,
	      REF RETURNED_LENGTH =:ipRetLen; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 13;
       sqlstm.arrsiz = 9;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "";
       sqlstm.iters = (unsigned int  )out_array_size;
       sqlstm.offset = (unsigned int  )610;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)outdesc;
       sqlstm.sqhstl[0] = (unsigned long )0;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)&occurs;
       sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[1] = (         int  )sizeof(int);
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)output[i];
       sqlstm.sqhstl[2] = (unsigned long )501;
       sqlstm.sqhsts[2] = (         int  )501;
       sqlstm.sqindv[2] = (         short *)0;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)iptr;
       sqlstm.sqhstl[3] = (unsigned long )sizeof(short);
       sqlstm.sqhsts[3] = (         int  )sizeof(short);
       sqlstm.sqindv[3] = (         short *)0;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)ipRetLen;
       sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[4] = (         int  )sizeof(int);
       sqlstm.sqindv[4] = (         short *)0;
       sqlstm.sqinds[4] = (         int  )0;
       sqlstm.sqharm[4] = (unsigned long )0;
       sqlstm.sqadto[4] = (unsigned short )0;
       sqlstm.sqtdso[4] = (unsigned short )0;
       sqlstm.sqphsv = sqlstm.sqhstv;
       sqlstm.sqphsl = sqlstm.sqhstl;
       sqlstm.sqphss = sqlstm.sqhsts;
       sqlstm.sqpind = sqlstm.sqindv;
       sqlstm.sqpins = sqlstm.sqinds;
       sqlstm.sqparm = sqlstm.sqharm;
       sqlstm.sqparc = sqlstm.sqharc;
       sqlstm.sqpadto = sqlstm.sqadto;
       sqlstm.sqptdso = sqlstm.sqtdso;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) sql_error();
}


	      /*EXEC SQL 
	      SET DESCRIPTOR GLOBAL :outdesc VALUE :occurs REF DATA =:output[i], REF INDICATOR =:iptr,
	      REF RETURNED_LENGTH =:ipRetLen;*/
	}
	
	buffer_size=(MAX_VAR_LEN * output_count) * out_array_size;
	/* checking if there's a bind file */
	if (debug&debug_level&&bind_file_name[0] != '\0')
		my_print("Got bind file %s\n", bind_file_name);
	if (bind_file_name[0]!='\0'){
		if ((bind_file = fopen(bind_file_name, "r")) == NULL) {
			my_print("Bind file %s does not exist\n",
			       bind_file_name);
			strcpy(function_name,saved_function_name);
			return 0;
		}
	}
	if (binds_from_sqlset==1){
		/* We will be getting the bind vars from sqlset data, so we'll be using the get_sqlset_bindv function
		mentioned above, and get the data. An SQL statement in a sqlset can have several executions, each with it's set of bind 
		values. The function will return a row for each exe ution, with the set of binds concatenated in a string, separated by
		the c_separator var specified in the parfile. The types of the different vars is taken from the descriptor above. The
		sqlset bind data is positional, NOT related to the var names, i.e. if a var is used twice in an SQL, it's bind value
		will appear twice in the returned row. This bind data does NOT have the bind var names, like we'll be doing for
		user-specified bind values*/
		char get_bind_vssqlset[120]="select column_value from get_sqlset_bindv(:bind_sqlsetname, :v_sql_id, :c_separator);";
		/* exec sql at main_db prepare stmt_gs from :get_bind_vssqlset; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )645;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)get_bind_vssqlset;
  sqlstm.sqhstl[0] = (unsigned long )120;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		/* exec sql declare  get_bindvs cursor for stmt_gs; */ 

		/* exec sql open get_bindvs using :bind_sqlsetname, :v_sql_id, :c_separator; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )671;
  sqlstm.selerr = (unsigned short)100;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)bind_sqlsetname;
  sqlstm.sqhstl[0] = (unsigned long )257;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)v_sql_id;
  sqlstm.sqhstl[1] = (unsigned long )30;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)c_separator;
  sqlstm.sqhstl[2] = (unsigned long )2;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		if (debug&8)
			my_print("before allocating input desc\n");
		/* EXEC SQL ALLOCATE DESCRIPTOR GLOBAL :indesc with max 20; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )698;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )20;
  sqlstm.sqhstv[0] = (unsigned char  *)indesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		if (debug&debug_level)
			my_print("before describing input desc\n");
		/* EXEC SQL DESCRIBE INPUT S USING DESCRIPTOR GLOBAL :indesc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )717;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)indesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		if (debug&debug_level)
			my_print("before get descriptor\n");

		/* EXEC SQL GET DESCRIPTOR GLOBAL :indesc :input_count = COUNT; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )743;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)indesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&input_count;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		if (debug&debug_level)
			my_print("input_count for input desc=%d\n",input_count);
		for (i=0;i<input_count;i++){ /* getting all bind variables names */
			occurs=i+1;
			/* EXEC SQL GET DESCRIPTOR GLOBAL :indesc VALUE :occurs :name_i=NAME; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )766;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)indesc;
   sqlstm.sqhstl[0] = (unsigned long )0;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&occurs;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)name_i;
   sqlstm.sqhstl[2] = (unsigned long )100;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error();
}


			strcpy(sql_bind_names[i],name_i);
			sql_bind_names_len[i]=strlen(name_i);
		}

		if (debug&debug_level)
			my_print("After Get Desc input bind count=%d, max_time=%d min_think_time=%d max_think_time=%d\n",
			       input_count,max_time_rem,think_time_min,think_time_max);
		int line_nbr=2;
		while (execution_time<max_time_rem || max_time_rem==0) {
			/* exec sql fetch get_bindvs into :line; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )793;
   sqlstm.selerr = (unsigned short)100;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)line;
   sqlstm.sqhstl[0] = (unsigned long )1000;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error();
}


			if (sqlca.sqlcode!=0)
				break;
			if (debug&debug_level) my_print("got sqlcode=%d and line=%s\n",sqlca.sqlcode,line);
			for (i = 0, str = line;; str = NULL, i++) {
				tn = strtok(str, c_separator);
				if (tn == NULL)
					break;
				// As the bind values are positional, we just assign the value we got to the i'th positional bind
					occurs = i+1;
				if (debug&debug_level)
					my_print("binding var number=%d, type=%s, value=%s\n", occurs, bind_types[i], tn);
					if (strncasecmp(bind_types[i], "number", 6)== 0) {
						/* got a number argument, so translate and assign, all numbers are taken to be doubles */
						dValue = strtod(tn, NULL);
						vAnsi_Type = 22;
						vInput_len =
							(int) sizeof((double) 2.0);
							/* EXEC SQL SET DESCRIPTOR GLOBAL :indesc VALUE :occurs TYPE =:vAnsi_Type, LENGTH =:vInput_len, DATA =:dValue; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 13;
       sqlstm.arrsiz = 9;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )812;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)indesc;
       sqlstm.sqhstl[0] = (unsigned long )0;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)&occurs;
       sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&vAnsi_Type;
       sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[2] = (         int  )0;
       sqlstm.sqindv[2] = (         short *)0;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)&vInput_len;
       sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[3] = (         int  )0;
       sqlstm.sqindv[3] = (         short *)0;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)&dValue;
       sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
       sqlstm.sqhsts[4] = (         int  )0;
       sqlstm.sqindv[4] = (         short *)0;
       sqlstm.sqinds[4] = (         int  )0;
       sqlstm.sqharm[4] = (unsigned long )0;
       sqlstm.sqadto[4] = (unsigned short )0;
       sqlstm.sqtdso[4] = (unsigned short )0;
       sqlstm.sqphsv = sqlstm.sqhstv;
       sqlstm.sqphsl = sqlstm.sqhstl;
       sqlstm.sqphss = sqlstm.sqhsts;
       sqlstm.sqpind = sqlstm.sqindv;
       sqlstm.sqpins = sqlstm.sqinds;
       sqlstm.sqparm = sqlstm.sqharm;
       sqlstm.sqparc = sqlstm.sqharc;
       sqlstm.sqpadto = sqlstm.sqadto;
       sqlstm.sqptdso = sqlstm.sqtdso;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) sql_error();
}


					} else {
						/* got a char argument, so just copy and assign */
						vAnsi_Type = 1;
						vInput_len = strlen(tn);
							/* EXEC SQL SET DESCRIPTOR GLOBAL :indesc VALUE :occurs TYPE =:vAnsi_Type, LENGTH =:vInput_len, DATA =:tn; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 13;
       sqlstm.arrsiz = 9;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )847;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)indesc;
       sqlstm.sqhstl[0] = (unsigned long )0;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)&occurs;
       sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&vAnsi_Type;
       sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[2] = (         int  )0;
       sqlstm.sqindv[2] = (         short *)0;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)&vInput_len;
       sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[3] = (         int  )0;
       sqlstm.sqindv[3] = (         short *)0;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)tn;
       sqlstm.sqhstl[4] = (unsigned long )0;
       sqlstm.sqhsts[4] = (         int  )0;
       sqlstm.sqindv[4] = (         short *)0;
       sqlstm.sqinds[4] = (         int  )0;
       sqlstm.sqharm[4] = (unsigned long )0;
       sqlstm.sqadto[4] = (unsigned short )0;
       sqlstm.sqtdso[4] = (unsigned short )0;
       sqlstm.sqphsv = sqlstm.sqhstv;
       sqlstm.sqphsl = sqlstm.sqhstl;
       sqlstm.sqphss = sqlstm.sqhsts;
       sqlstm.sqpind = sqlstm.sqindv;
       sqlstm.sqpins = sqlstm.sqinds;
       sqlstm.sqparm = sqlstm.sqharm;
       sqlstm.sqparc = sqlstm.sqharc;
       sqlstm.sqpadto = sqlstm.sqadto;
       sqlstm.sqptdso = sqlstm.sqtdso;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) sql_error();
}


					}
			}
			ticks = gettimeofday(&B_time, NULL);
			/* EXEC SQL FOR :in_array_size OPEN C USING DESCRIPTOR
				GLOBAL :indesc; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )in_array_size;
   sqlstm.offset = (unsigned int  )882;
   sqlstm.selerr = (unsigned short)100;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqcmod = (unsigned int )0;
   sqlstm.sqhstv[0] = (unsigned char  *)indesc;
   sqlstm.sqhstl[0] = (unsigned long )0;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error();
}


			if (sqlca.sqlcode<0) return(sqlca.sqlcode);
			process_output_csv(out_fp, buffer_size,output_count,first_call);
			/* EXEC SQL CLOSE C; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )908;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error();
}


			first_call=0;
			//*executions++;
			if (sqlca.sqlcode<0) return(sqlca.sqlcode);
			ticks = gettimeofday(&E_time, NULL);
			real_time =	/* in micro seconds */
				(E_time.tv_sec - B_time.tv_sec) * 1000000 +
				(E_time.tv_usec - B_time.tv_usec)-real_time_get_sqlid;
			execution_time+=real_time;
			if (debug&debug_level) my_print("execution_time=%d max_time=%d\n",execution_time, max_time_rem);
			aexec_times[exec_binds_counter] = real_time;
			aexec_timest[exec_binds_counter] =B_time.tv_sec;//+B_time.tv_usec/1000000;
			aexec_first_fetch[exec_binds_counter]=(time_first_fetch.tv_sec - B_time.tv_sec) * 1000000 +
				(time_first_fetch.tv_usec - B_time.tv_usec)-real_time_get_sqlid;
			aret_rows[exec_binds_counter] = cumulative_rows;
			abind_file_line[exec_binds_counter++]=line_nbr++;
			if (asked_to_quit())
				{
				my_print("was asked to quit\n");
				break;
				}
			if (think_time_min == think_time_max)
				tt = think_time_min;
			else
				tt = rand() % (think_time_max -
					       think_time_min) +
					think_time_min;
			if (socket_is_opened != 0)
				send_socket(trial_nbr,(double)B_time.tv_sec+B_time.tv_usec/1000000,
					    real_time, aexec_first_fetch[exec_binds_counter-1],cumulative_rows,line_nbr-1);
			usleep(tt);
			if (exec_binds_counter >= flush_results_every) {
				print_exec_data(trial_nbr, query_name,
						mypid);
				exec_binds_counter = 0;
			}
		}
		/* exec sql close get_bindvs; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )930;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		if (debug&debug_level) my_print("finished from sqlset binds, exec_binds_counter=%d\n",exec_binds_counter);
		if (exec_binds_counter >0) {
			print_exec_data(trial_nbr, query_name, mypid);
			exec_binds_counter = 100;
		}
		/* EXEC SQL DEALLOCATE DESCRIPTOR GLOBAL :outdesc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )945;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)outdesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		/* EXEC SQL DEALLOCATE DESCRIPTOR GLOBAL :indesc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )964;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)indesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


	} else if (bind_file_name[0] != '\0') {
		if ((bind_file = fopen(bind_file_name, "r")) == NULL) {
			my_print("Bind file %s does not exist\n",
			       bind_file_name);
			strcpy(function_name,saved_function_name);
			return 0;
		}
		/* get first line: it contains, for each column, it's type: number or char */
		str = fgets(line, 1000, bind_file);
		/* use strtok to split it */
		for (i = 0, str = line;;str=NULL ) {
			tn = strtok(str, c_separator);
			if (tn == NULL)
				break;
			cptr=strchr(tn,':');
			*cptr='\0';
			cptr++;
			if (debug&debug_level) my_print ("bt=%s, bn=%s\n",cptr,tn);
			strcpy(bind_types[i], cptr);
			strcpy(bind_names[i], tn);
			bind_names_len[i++]=strlen(tn);
		}
		if (debug&8)
			my_print("before allocating input desc\n");
		/* EXEC SQL ALLOCATE DESCRIPTOR GLOBAL :indesc with max 20; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )983;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )20;
  sqlstm.sqhstv[0] = (unsigned char  *)indesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		if (debug&debug_level)
			my_print("before describing input desc\n");
		/* EXEC SQL DESCRIBE INPUT S USING DESCRIPTOR GLOBAL :indesc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1002;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)indesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		if (debug&debug_level)
			my_print("before get descriptor\n");

		/* EXEC SQL GET DESCRIPTOR GLOBAL :indesc :input_count = COUNT; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1028;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)indesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&input_count;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		if (debug&debug_level)
			my_print("input_count for input desc=%d\n",input_count);
		for (i=0;i<input_count;i++){ /* getting all bind variables names */
			occurs=i+1;
			/* EXEC SQL GET DESCRIPTOR GLOBAL :indesc VALUE :occurs :name_i=NAME; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1051;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)indesc;
   sqlstm.sqhstl[0] = (unsigned long )0;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&occurs;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)name_i;
   sqlstm.sqhstl[2] = (unsigned long )100;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error();
}


			strcpy(sql_bind_names[i],name_i);
			sql_bind_names_len[i]=strlen(name_i);
		}

		if (debug&debug_level)
			my_print("After Get Desc input bind count=%d, max_time=%d min_think_time=%d max_think_time=%d\n",
			       input_count,max_time_rem,think_time_min,think_time_max);
		int line_nbr=2;
		while (!feof(bind_file)&&(execution_time<max_time_rem || max_time_rem==0)) {
			str = fgets(line, 1000, bind_file);
			if (str == NULL)
				break;
			if (debug&debug_level) my_print("str=%s and line=%s\n",str,line);
			for (i = 0, str = line;; str = NULL, i++) {
				tn = strtok(str, c_separator);
				if (tn == NULL)
					break;
				// will have to loop over all the bind variables to assign this one
				for (j=0;j<input_count;j++){
					occurs = j+1;
					if (debug&debug_level)
						my_print("binding var number=%d, type=%s, value=%s\n", occurs, bind_types[i], tn);
					if (sql_bind_names_len[j]==bind_names_len[i]&&strcasecmp(sql_bind_names[j],bind_names[i])==0){
						if (strncasecmp(bind_types[i], "number", 6)== 0) {
							/* got a number argument, so translate and assign, all numbers are taken to be doubles */
							dValue = strtod(tn, NULL);
							vAnsi_Type = 22;
							vInput_len =
								(int) sizeof((double) 2.0);
						      /* EXEC SQL SET DESCRIPTOR GLOBAL :indesc VALUE :occurs TYPE =:vAnsi_Type, LENGTH =:vInput_len, DATA =:dValue; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 9;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1078;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)indesc;
            sqlstm.sqhstl[0] = (unsigned long )0;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&occurs;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&vAnsi_Type;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&vInput_len;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&dValue;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error();
}


						} else if (strncasecmp(bind_types[i], "integer",7) == 0) {
							/* got a number argument, so translate and assign, all numbers are taken to be doubles */
							vIvalue = atoi(tn);
							vAnsi_Type = 3;
							vInput_len = (int) sizeof((int) 2);
						      /* EXEC SQL SET DESCRIPTOR GLOBAL :indesc VALUE :occurs TYPE =:vAnsi_Type, LENGTH =:vInput_len, DATA =:vIvalue; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 9;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1113;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)indesc;
            sqlstm.sqhstl[0] = (unsigned long )0;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&occurs;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&vAnsi_Type;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&vInput_len;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&vIvalue;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error();
}


						} else {
							/* got a char argument, so just copy and assign */
							vAnsi_Type = 1;
							vInput_len = strlen(tn);
						      /* EXEC SQL SET DESCRIPTOR GLOBAL :indesc VALUE :occurs TYPE =:vAnsi_Type, LENGTH =:vInput_len, DATA =:tn; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 9;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1148;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)indesc;
            sqlstm.sqhstl[0] = (unsigned long )0;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&occurs;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&vAnsi_Type;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&vInput_len;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)tn;
            sqlstm.sqhstl[4] = (unsigned long )0;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error();
}


						}
					}
				}
			}
			ticks = gettimeofday(&B_time, NULL);
			/* EXEC SQL FOR :in_array_size OPEN C USING DESCRIPTOR
				GLOBAL :indesc; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )in_array_size;
   sqlstm.offset = (unsigned int  )1183;
   sqlstm.selerr = (unsigned short)100;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqcmod = (unsigned int )0;
   sqlstm.sqhstv[0] = (unsigned char  *)indesc;
   sqlstm.sqhstl[0] = (unsigned long )0;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error();
}


			if (sqlca.sqlcode<0) return(sqlca.sqlcode);
			process_output_csv(out_fp, buffer_size,output_count,first_call);
			/* EXEC SQL CLOSE C; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1209;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error();
}


			first_call=0;
			//*executions++;
			if (sqlca.sqlcode<0) return(sqlca.sqlcode);
			ticks = gettimeofday(&E_time, NULL);
			real_time =	/* in micro seconds */
				(E_time.tv_sec - B_time.tv_sec) * 1000000 +
				(E_time.tv_usec - B_time.tv_usec)-real_time_get_sqlid;
			execution_time+=real_time;
			if (debug&debug_level) my_print("execution_time=%d max_time=%d\n",execution_time, max_time_rem);
			aexec_times[exec_binds_counter] = real_time;
			aexec_timest[exec_binds_counter] =B_time.tv_sec;//+B_time.tv_usec/1000000;
			aexec_first_fetch[exec_binds_counter]=(time_first_fetch.tv_sec - B_time.tv_sec) * 1000000 +
				(time_first_fetch.tv_usec - B_time.tv_usec)-real_time_get_sqlid;
			aret_rows[exec_binds_counter] = cumulative_rows;
			abind_file_line[exec_binds_counter++]=line_nbr++;
			if (asked_to_quit())
				{
				my_print("was asked to quit\n");
				break;
				}
			if (think_time_min == think_time_max)
				tt = think_time_min;
			else
				tt = rand() % (think_time_max -
					       think_time_min) +
					think_time_min;
			if (socket_is_opened != 0)
				send_socket(trial_nbr,(double)B_time.tv_sec+B_time.tv_usec/1000000,
					    real_time, aexec_first_fetch[exec_binds_counter-1],cumulative_rows,line_nbr-1);
			usleep(tt);
			if (exec_binds_counter >= flush_results_every) {
				print_exec_data(trial_nbr, query_name,
						mypid);
				exec_binds_counter = 0;
			}
		}
		fclose(bind_file);
		if (debug&debug_level) my_print("finished bind file, exec_binds_counter=%d\n",exec_binds_counter);
		if (exec_binds_counter >0) {
			print_exec_data(trial_nbr, query_name, mypid);
			exec_binds_counter = 100;
		}
		/* EXEC SQL DEALLOCATE DESCRIPTOR GLOBAL :outdesc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1231;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)outdesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		/* EXEC SQL DEALLOCATE DESCRIPTOR GLOBAL :indesc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1250;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)indesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


	} else {
		/* Open the cursor and execute the statement. */
		ticks = gettimeofday(&B_time, NULL);
		/* EXEC SQL OPEN C; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1269;
  sqlstm.selerr = (unsigned short)100;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}

	/*USING DESCRIPTOR GLOBAL :indesc; */
		if (debug&debug_level)
			my_print("Opened cursor sqlcode=%d\n",sqlca.sqlcode);
		/*if (sqlca.sqlcode<0) return(sqlca.sqlcode);*/
		cursor_open = 1;
		if (debug&debug_level)
			my_print("Will start processing, cursor is opened, sqlcode=%d\n",sqlca.sqlcode);
		/* Call the function that processes the output. */
		if (sqlca.sqlcode==0) cursor_open=process_output_csv(out_fp, buffer_size,output_count,1);
		else 
		if (debug&debug_level)
			my_print("Not fetching the rows, as we gotan error sqlcode=%d\n",sqlca.sqlcode);
		/* EXEC SQL CLOSE C; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1291;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		if (debug&debug_level)
			my_print("cursor is closed, sqlcode=%d\n",sqlca.sqlcode);
			
		/* Deallocate the descriptors */
		/* EXEC SQL DEALLOCATE DESCRIPTOR GLOBAL :outdesc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1313;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)outdesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		if (debug&debug_level)
			my_print("descriptor deallocated, sqlcode=%d\n",sqlca.sqlcode);


		ticks = gettimeofday(&E_time, NULL);
		real_time =
			(E_time.tv_sec - B_time.tv_sec) * 1000000 +
			(E_time.tv_usec - B_time.tv_usec)-real_time_get_sqlid;
		if (first_time==0) first_time=(time_first_fetch.tv_sec - B_time.tv_sec) * 1000000 +
			(time_first_fetch.tv_usec - B_time.tv_usec)-real_time_get_sqlid ;

		if (socket_is_opened != 0)
			send_socket(trial_nbr,1, real_time,first_time,cumulative_rows,1);
	}


	strcpy(function_name,saved_function_name);
	return 0;
}

int process_output_csv(
	FILE * out_fp,
	int buffer_size_p,
	int output_count,
	int first_call)
{
	int     i, j,  times_checked, ticks;
	int     occurs,buffer_pos, true_child_nbr;
	long    secs_since_epoch;
	int     rows_this_fetch = 0;
	int		debug_level=1<<8;
	char    saved_function_name[50],v_txt[100],true_sql_id[15],ch='\0';
	char   *buf, *final_buffer, asql_ids[100][20],alat[100][15], asqltxt[100][70], sql_first_1000[1002], msg_get_sqlid[50];
	struct timeval B_time, E_time;
	cumulative_rows = 0;
	times_checked=1;
	memset(sql_first_1000,ch,1001);
	strncpy(sql_first_1000,dyn_statement,1000);
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"process_output_csv");
	if (first_call==1&&separate_process_sqlid>0){
		ticks=gettimeofday(&B_time, NULL);
		ask_for_sqlid(true_sql_id, &true_child_nbr);
		ticks=gettimeofday(&E_time, NULL);
		real_time_get_sqlid =
			(E_time.tv_sec - B_time.tv_sec) * 1000000 +
			(E_time.tv_usec - B_time.tv_usec);

		if (true_child_nbr>=0){
			strcpy(v_sql_id,true_sql_id);
			VVChild_n=true_child_nbr;
		}
	} else real_time_get_sqlid=0.;
	if (debug&debug_level) my_print("in output csv, true id=%s, true_child=%d, first_call=%d",true_sql_id,true_child_nbr,first_call);
	if (out_fp!=NULL) final_buffer = (char *)malloc(buffer_size_p);
	if (max_rows>0 && max_rows<out_array_size) out_array_size=max_rows;
	rows_this_fetch = out_array_size;
	/* FETCH each row selected and print the column values. */
	for (;
	     (cumulative_rows < max_rows || max_rows == 0) && times_checked>0 && sqlca.sqlcode==0;) {

		/* EXEC SQL FETCH C INTO DESCRIPTOR
			GLOBAL :outdesc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1332;
  sqlstm.selerr = (unsigned short)100;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)outdesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		if (debug&debug_level)
			my_print("fetched cumulative_rows=%d, sqlca.sqlcode=%d\n",cumulative_rows, sqlca.sqlcode);
		if (sqlca.sqlcode==0){
			if (cumulative_rows==0) {
				int ticks=gettimeofday(&time_first_fetch,NULL);
			}
			if (debug&debug_level)
				my_print("fetched rows_this_fetch=%d\n",sqlca.sqlerrd[2]);
			rows_this_fetch = 1;//sqlca.sqlerrd[2] - cumulative_rows;
			cumulative_rows ++;//= sqlca.sqlerrd[2];
			buf = final_buffer;
			buffer_pos = 0;
			if (out_fp!=NULL) {
					for (i = 0; i < output_count; i++) {
						if (debug&debug_level) my_print("column nbr=%d, got_len=%d, value=%s\n",i,retleni[i],output[i]);
						memcpy(buf, output[i],
						       retleni[i]);
						buf += retleni[i];
						buffer_pos += retleni[i];
						memcpy(buf, comma, comma_len);
						buf += comma_len;
						buffer_pos += comma_len;
					}
					memset(buf++, 10, 1);
					buffer_pos += 1;
				}
			if (out_fp != NULL&&cumulative_rows<=rows_to_spool)
				fwrite(final_buffer, buffer_pos, 1, out_fp);
			if (cumulative_rows>times_checked*check_for_quit_every){
				times_checked++;
				if (asked_to_quit()) times_checked=-1;
			}
		}
	}
	if (out_fp!=NULL) free(final_buffer);
	if (debug&debug_level)
		my_print("%d row%c processed.\n", cumulative_rows,
		       cumulative_rows == 1 ? ' ' : 's');
     sqlca.sqlcode=0;
	 /* get child number using v$active_session_history */
    if (true_child_nbr<0) { /* we're not using a sep process to get sql_id, child_nbr from v$session,
							so, let's try to use open_cursor to get child nbr for the just executed sql */
            char secsse[20];
            secs_since_epoch--;
			sprintf(secsse,"%ld",secs_since_epoch);
            /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

            /* exec sql at main_db
                select max(sq.child_number) keep (dense_rank last order by sq.last_active_time) ,to_char(to_date('19700101','yyyymmdd')+:secs_since_epoch/3600/24,'dd/mm/yyyy hh24:mi:ss')
                into :VVChild_n,:secsse
                from v$open_cursor c, v$sql sq, v$session s
                where c.sid=sys_context('userenv','SID')
                and s.sid=c.sid
				and s.sid=sys_context('userenv','sid')
                and cursor_type in ('OPEN','SESSION CURSOR CACHED')
                and c.sql_id=sq.sql_id
                and sq.sql_id=:v_sql_id
                and c.child_address=sq.child_address
                and sq.child_number is not null; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 9;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select max ( sq . child_number ) keep ( dense_ran\
k last order by sq . last_active_time ) , to_char ( to_date ( '19700101' , 'yy\
yymmdd' ) + :b0 / 3600 / 24 , 'dd/mm/yyyy hh24:mi:ss' ) into :b1 , :b2 from v$\
open_cursor c , v$sql sq , v$session s where c . sid = sys_context ( 'userenv'\
 , 'SID' ) and s . sid = c . sid and s . sid = sys_context ( 'userenv' , 'sid'\
 ) and cursor_type in ( 'OPEN' , 'SESSION CURSOR CACHED' ) and c . sql_id = sq\
 . sql_id and sq . sql_id = :b3 and c . child_address = sq . child_address and\
 sq . child_number is not null ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1358;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&secs_since_epoch;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&VVChild_n;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)secsse;
            sqlstm.sqhstl[2] = (unsigned long )20;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)v_sql_id;
            sqlstm.sqhstl[3] = (unsigned long )30;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


/*                and sq.last_active_time>=to_date('19700101','yyyymmdd')+:secs_since_epoch/3600/24;*/
            if (sqlca.sqlcode!=0&&debug&debug_level) {
                my_print("Error  %d from v$open_cursor for sql_id=%s secs_since_epoch=%s\n",sqlca.sqlcode, v_sql_id,secsse);
            }
            if (debug&debug_level)
                    my_print("got child nbr from open_cursor for sql_id=%s child=%d\n",v_sql_id, VVChild_n);
    }
    if (debug&debug_level)
            my_print("got child nbr from ash for sql_id=%s child=%d\n",v_sql_id, VVChild_n);
	strcpy(function_name,saved_function_name);
	return (0);
}
/* function to process non-select DML statements that use bind variables*/
int process_non_sel(
)
{
	int     ticks, tt, input_count, occurs, vAnsi_Type, vInput_len, i,
		vIvalue, execution_count,j, bind_names_len[20], sql_bind_names_len[21], execution_time;
	long    clk_ticks;
	double  dValue;
	char   saved_function_name[50],*tn, bind_types[100][100],c_separator[2], line[1000], *str, *cptr,name_i[100],
		bind_names[100][100],sql_bind_names[101][100];
	struct timeval B_time, E_time;
	ticks = gettimeofday(&B_time, NULL);
	FILE   *bind_file;
	int debug_level=1<<8;
	execution_count = 0;
	exec_binds_counter=0;
	c_separator[0]=c_bind_file_separator;
	c_separator[1]='\0';
	/* EXEC SQL WHENEVER SQLERROR DO sql_error(); */ 

	strcpy(saved_function_name,function_name);
	strcpy(function_name,"process_non_sell");
	execution_time=0;

	/* Prepare the statement and declare a cursor. */
	/* EXEC SQL at main_db declare  SU statement; */ 

	if (debug&debug_level)
		my_print("Executing statement %s\n", dyn_statement);
	/* EXEC SQL at main_db PREPARE SU FROM :dyn_statement; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1396;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)dyn_statement;
 sqlstm.sqhstl[0] = (unsigned long )257000;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error();
}


	if (debug&debug_level)
		my_print("Opening cursor \n");
	/* checking if there's a bind file */
	if (debug&debug_level)
		my_print("Got bind file %s\n", bind_file_name);
	if ((bind_file = fopen(bind_file_name, "r")) == NULL) {
		my_print("Bind file %s does not exist\n",
		       bind_file_name);
		strcpy(function_name,saved_function_name);
		return 0;
	}
	/* get first line: it contains, for each column, it's type: number or char */
	str = fgets(line, 1000, bind_file);
	/* use strtok to split it */
	for (i = 0, str = line;;str=NULL ) {
		tn = strtok(str, c_separator);
		if (tn == NULL)
			break;
		cptr=strchr(tn,':');
		*cptr='\0';
		cptr++;
		if (debug&debug_level) my_print ("bt=%s, bn=%s\n",cptr,tn);
		strcpy(bind_types[i], cptr);
		strcpy(bind_names[i], tn);
		bind_names_len[i++]=strlen(tn);
	}
	if (debug&debug_level)
		my_print("before allocating input desc\n");
	/* EXEC SQL ALLOCATE DESCRIPTOR GLOBAL :indesc with max 20; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1422;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )20;
 sqlstm.sqhstv[0] = (unsigned char  *)indesc;
 sqlstm.sqhstl[0] = (unsigned long )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error();
}


	if (debug&debug_level)
		my_print("before describing input desc\n");
	/* EXEC SQL DESCRIBE INPUT SU USING DESCRIPTOR GLOBAL :indesc; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1441;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)indesc;
 sqlstm.sqhstl[0] = (unsigned long )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error();
}


	if (debug&debug_level)
		my_print("before get descriptor\n");

	/* EXEC SQL GET DESCRIPTOR GLOBAL :indesc :input_count = COUNT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1467;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)indesc;
 sqlstm.sqhstl[0] = (unsigned long )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&input_count;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error();
}


	if (debug&debug_level)
		my_print("input_count for input desc=%d\n",input_count);
	for (i=0;i<input_count;i++){ /* getting all bind variables names */
		occurs=i+1;
		/* EXEC SQL GET DESCRIPTOR GLOBAL :indesc VALUE :occurs :name_i=NAME; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1490;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)indesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&occurs;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)name_i;
  sqlstm.sqhstl[2] = (unsigned long )100;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		strcpy(sql_bind_names[i],name_i);
		sql_bind_names_len[i]=strlen(name_i);
		if (debug&debug_level)
			my_print("var_name nbr %d = %s len=%d\n",i,sql_bind_names[i],strlen(name_i));
	}

	if (debug&debug_level)
		my_print("After Get Desc input bind count=%d, min_think_time=%d max_think_time=%d\n",
		       input_count,think_time_min,think_time_max);
	int line_nbr=2;
	while (!feof(bind_file)) {
		str = fgets(line, 1000, bind_file);
		if (str == NULL)
			break;
		if (debug&debug_level) my_print("str=%s and line=%s\n",str,line);
		for (i = 0, str = line;; str = NULL, i++) {
			tn = strtok(str, c_separator);
			if (tn == NULL)
				break;
			// will have to loop over all the bind variables to assign this one
			for (j=0;j<input_count;j++){
				occurs = j+1;
				if (debug&debug_level)
					my_print("Trying binding var number=%d, name =%s type=%s, value=%s sql_bind_name=%s\n", occurs, bind_names[i], bind_types[i], tn,sql_bind_names[j]);
				if (sql_bind_names_len[j]==bind_names_len[i]&&strcasecmp(sql_bind_names[j],bind_names[i])==0){
					if (debug&debug_level)
						my_print("binding var number=%d, type=%s, value=%s\n", occurs, bind_types[i], tn);
					if (strncasecmp(bind_types[i], "number", 6)== 0) {
						/* got a number argument, so translate and assign, all numbers are taken to be doubles */
						dValue = strtod(tn, NULL);
						vAnsi_Type = 22;
						vInput_len =
							(int) sizeof((double) 2.0);
					      /* EXEC SQL SET DESCRIPTOR GLOBAL :indesc VALUE :occurs TYPE =:vAnsi_Type, LENGTH =:vInput_len, DATA =:dValue; */ 

{
           struct sqlexd sqlstm;
           sqlstm.sqlvsn = 13;
           sqlstm.arrsiz = 9;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.stmt = "";
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )1517;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)4352;
           sqlstm.occurs = (unsigned int  )0;
           sqlstm.sqhstv[0] = (unsigned char  *)indesc;
           sqlstm.sqhstl[0] = (unsigned long )0;
           sqlstm.sqhsts[0] = (         int  )0;
           sqlstm.sqindv[0] = (         short *)0;
           sqlstm.sqinds[0] = (         int  )0;
           sqlstm.sqharm[0] = (unsigned long )0;
           sqlstm.sqadto[0] = (unsigned short )0;
           sqlstm.sqtdso[0] = (unsigned short )0;
           sqlstm.sqhstv[1] = (unsigned char  *)&occurs;
           sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
           sqlstm.sqhsts[1] = (         int  )0;
           sqlstm.sqindv[1] = (         short *)0;
           sqlstm.sqinds[1] = (         int  )0;
           sqlstm.sqharm[1] = (unsigned long )0;
           sqlstm.sqadto[1] = (unsigned short )0;
           sqlstm.sqtdso[1] = (unsigned short )0;
           sqlstm.sqhstv[2] = (unsigned char  *)&vAnsi_Type;
           sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
           sqlstm.sqhsts[2] = (         int  )0;
           sqlstm.sqindv[2] = (         short *)0;
           sqlstm.sqinds[2] = (         int  )0;
           sqlstm.sqharm[2] = (unsigned long )0;
           sqlstm.sqadto[2] = (unsigned short )0;
           sqlstm.sqtdso[2] = (unsigned short )0;
           sqlstm.sqhstv[3] = (unsigned char  *)&vInput_len;
           sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
           sqlstm.sqhsts[3] = (         int  )0;
           sqlstm.sqindv[3] = (         short *)0;
           sqlstm.sqinds[3] = (         int  )0;
           sqlstm.sqharm[3] = (unsigned long )0;
           sqlstm.sqadto[3] = (unsigned short )0;
           sqlstm.sqtdso[3] = (unsigned short )0;
           sqlstm.sqhstv[4] = (unsigned char  *)&dValue;
           sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
           sqlstm.sqhsts[4] = (         int  )0;
           sqlstm.sqindv[4] = (         short *)0;
           sqlstm.sqinds[4] = (         int  )0;
           sqlstm.sqharm[4] = (unsigned long )0;
           sqlstm.sqadto[4] = (unsigned short )0;
           sqlstm.sqtdso[4] = (unsigned short )0;
           sqlstm.sqphsv = sqlstm.sqhstv;
           sqlstm.sqphsl = sqlstm.sqhstl;
           sqlstm.sqphss = sqlstm.sqhsts;
           sqlstm.sqpind = sqlstm.sqindv;
           sqlstm.sqpins = sqlstm.sqinds;
           sqlstm.sqparm = sqlstm.sqharm;
           sqlstm.sqparc = sqlstm.sqharc;
           sqlstm.sqpadto = sqlstm.sqadto;
           sqlstm.sqptdso = sqlstm.sqtdso;
           sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
           if (sqlca.sqlcode < 0) sql_error();
}


					} else if (strncasecmp(bind_types[i], "integer",7) == 0) {
						/* got a number argument, so translate and assign, all numbers are taken to be doubles */
						vIvalue = atoi(tn);
						vAnsi_Type = 3;
						vInput_len = (int) sizeof((int) 2);
					      /* EXEC SQL SET DESCRIPTOR GLOBAL :indesc VALUE :occurs TYPE =:vAnsi_Type, LENGTH =:vInput_len, DATA =:vIvalue; */ 

{
           struct sqlexd sqlstm;
           sqlstm.sqlvsn = 13;
           sqlstm.arrsiz = 9;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.stmt = "";
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )1552;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)4352;
           sqlstm.occurs = (unsigned int  )0;
           sqlstm.sqhstv[0] = (unsigned char  *)indesc;
           sqlstm.sqhstl[0] = (unsigned long )0;
           sqlstm.sqhsts[0] = (         int  )0;
           sqlstm.sqindv[0] = (         short *)0;
           sqlstm.sqinds[0] = (         int  )0;
           sqlstm.sqharm[0] = (unsigned long )0;
           sqlstm.sqadto[0] = (unsigned short )0;
           sqlstm.sqtdso[0] = (unsigned short )0;
           sqlstm.sqhstv[1] = (unsigned char  *)&occurs;
           sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
           sqlstm.sqhsts[1] = (         int  )0;
           sqlstm.sqindv[1] = (         short *)0;
           sqlstm.sqinds[1] = (         int  )0;
           sqlstm.sqharm[1] = (unsigned long )0;
           sqlstm.sqadto[1] = (unsigned short )0;
           sqlstm.sqtdso[1] = (unsigned short )0;
           sqlstm.sqhstv[2] = (unsigned char  *)&vAnsi_Type;
           sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
           sqlstm.sqhsts[2] = (         int  )0;
           sqlstm.sqindv[2] = (         short *)0;
           sqlstm.sqinds[2] = (         int  )0;
           sqlstm.sqharm[2] = (unsigned long )0;
           sqlstm.sqadto[2] = (unsigned short )0;
           sqlstm.sqtdso[2] = (unsigned short )0;
           sqlstm.sqhstv[3] = (unsigned char  *)&vInput_len;
           sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
           sqlstm.sqhsts[3] = (         int  )0;
           sqlstm.sqindv[3] = (         short *)0;
           sqlstm.sqinds[3] = (         int  )0;
           sqlstm.sqharm[3] = (unsigned long )0;
           sqlstm.sqadto[3] = (unsigned short )0;
           sqlstm.sqtdso[3] = (unsigned short )0;
           sqlstm.sqhstv[4] = (unsigned char  *)&vIvalue;
           sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
           sqlstm.sqhsts[4] = (         int  )0;
           sqlstm.sqindv[4] = (         short *)0;
           sqlstm.sqinds[4] = (         int  )0;
           sqlstm.sqharm[4] = (unsigned long )0;
           sqlstm.sqadto[4] = (unsigned short )0;
           sqlstm.sqtdso[4] = (unsigned short )0;
           sqlstm.sqphsv = sqlstm.sqhstv;
           sqlstm.sqphsl = sqlstm.sqhstl;
           sqlstm.sqphss = sqlstm.sqhsts;
           sqlstm.sqpind = sqlstm.sqindv;
           sqlstm.sqpins = sqlstm.sqinds;
           sqlstm.sqparm = sqlstm.sqharm;
           sqlstm.sqparc = sqlstm.sqharc;
           sqlstm.sqpadto = sqlstm.sqadto;
           sqlstm.sqptdso = sqlstm.sqtdso;
           sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
           if (sqlca.sqlcode < 0) sql_error();
}


					} else {
						/* got a char argument, so just copy and assign */
						vAnsi_Type = 1;
						vInput_len = strlen(tn);
					      /* EXEC SQL SET DESCRIPTOR GLOBAL :indesc VALUE :occurs TYPE =:vAnsi_Type, LENGTH =:vInput_len, DATA =:tn; */ 

{
           struct sqlexd sqlstm;
           sqlstm.sqlvsn = 13;
           sqlstm.arrsiz = 9;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.stmt = "";
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )1587;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)4352;
           sqlstm.occurs = (unsigned int  )0;
           sqlstm.sqhstv[0] = (unsigned char  *)indesc;
           sqlstm.sqhstl[0] = (unsigned long )0;
           sqlstm.sqhsts[0] = (         int  )0;
           sqlstm.sqindv[0] = (         short *)0;
           sqlstm.sqinds[0] = (         int  )0;
           sqlstm.sqharm[0] = (unsigned long )0;
           sqlstm.sqadto[0] = (unsigned short )0;
           sqlstm.sqtdso[0] = (unsigned short )0;
           sqlstm.sqhstv[1] = (unsigned char  *)&occurs;
           sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
           sqlstm.sqhsts[1] = (         int  )0;
           sqlstm.sqindv[1] = (         short *)0;
           sqlstm.sqinds[1] = (         int  )0;
           sqlstm.sqharm[1] = (unsigned long )0;
           sqlstm.sqadto[1] = (unsigned short )0;
           sqlstm.sqtdso[1] = (unsigned short )0;
           sqlstm.sqhstv[2] = (unsigned char  *)&vAnsi_Type;
           sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
           sqlstm.sqhsts[2] = (         int  )0;
           sqlstm.sqindv[2] = (         short *)0;
           sqlstm.sqinds[2] = (         int  )0;
           sqlstm.sqharm[2] = (unsigned long )0;
           sqlstm.sqadto[2] = (unsigned short )0;
           sqlstm.sqtdso[2] = (unsigned short )0;
           sqlstm.sqhstv[3] = (unsigned char  *)&vInput_len;
           sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
           sqlstm.sqhsts[3] = (         int  )0;
           sqlstm.sqindv[3] = (         short *)0;
           sqlstm.sqinds[3] = (         int  )0;
           sqlstm.sqharm[3] = (unsigned long )0;
           sqlstm.sqadto[3] = (unsigned short )0;
           sqlstm.sqtdso[3] = (unsigned short )0;
           sqlstm.sqhstv[4] = (unsigned char  *)tn;
           sqlstm.sqhstl[4] = (unsigned long )0;
           sqlstm.sqhsts[4] = (         int  )0;
           sqlstm.sqindv[4] = (         short *)0;
           sqlstm.sqinds[4] = (         int  )0;
           sqlstm.sqharm[4] = (unsigned long )0;
           sqlstm.sqadto[4] = (unsigned short )0;
           sqlstm.sqtdso[4] = (unsigned short )0;
           sqlstm.sqphsv = sqlstm.sqhstv;
           sqlstm.sqphsl = sqlstm.sqhstl;
           sqlstm.sqphss = sqlstm.sqhsts;
           sqlstm.sqpind = sqlstm.sqindv;
           sqlstm.sqpins = sqlstm.sqinds;
           sqlstm.sqparm = sqlstm.sqharm;
           sqlstm.sqparc = sqlstm.sqharc;
           sqlstm.sqpadto = sqlstm.sqadto;
           sqlstm.sqptdso = sqlstm.sqtdso;
           sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
           if (sqlca.sqlcode < 0) sql_error();
}


					}
				}
			}
		}
		ticks = gettimeofday(&B_time, NULL);
		/* EXEC SQL EXECUTE SU USING DESCRIPTOR
			GLOBAL :indesc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1622;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)indesc;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error();
}


		ticks = gettimeofday(&E_time, NULL);
		cumulative_rows=sqlca.sqlerrd[2];
		real_time =	/* in micro seconds */
			(E_time.tv_sec - B_time.tv_sec) * 1000000 +
			(E_time.tv_usec - B_time.tv_usec);
		execution_time+=real_time;
		if (debug&debug_level) my_print("execution_time=%d \n",execution_time);
		aexec_times[exec_binds_counter] = real_time;
		aexec_timest[exec_binds_counter] =B_time.tv_sec+B_time.tv_usec/1000000;
		aret_rows[exec_binds_counter] = cumulative_rows;
		abind_file_line[exec_binds_counter++]=line_nbr++;
		if (asked_to_quit())
			{
			my_print("was asked to quit\n");
			break;
			}
		if (think_time_min == think_time_max)
			tt = think_time_min;
		else
			tt = rand() % (think_time_max -
				       think_time_min) +
				think_time_min;
		usleep(tt);
		if (exec_binds_counter >= flush_results_every) {
			print_exec_data(trial_nbr, query_name,
					mypid);
			exec_binds_counter = 0;
		}
		if (socket_is_opened != 0)
			send_socket(trial_nbr,(double)B_time.tv_sec+B_time.tv_usec/1000000,
				    real_time, 0,cumulative_rows,line_nbr-1);
	}
	fclose(bind_file);
	if (debug&debug_level) my_print("finished bind file, exec_binds_counter=%d\n",exec_binds_counter);
	if (exec_binds_counter >0) {
		print_exec_data(trial_nbr, query_name, mypid);
		exec_binds_counter = 100;
	}
	/* EXEC SQL DEALLOCATE DESCRIPTOR GLOBAL :indesc; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1648;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)indesc;
 sqlstm.sqhstl[0] = (unsigned long )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error();
}


	/* EXEC SQL AT main_db COMMIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1667;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error();
}


	strcpy(function_name,saved_function_name);
	return 0;
}

char   *replace_n_r(
	char *string_par,
	char o,
	char r)
{
	char   *ptr;
	ptr = string_par;
	while (*ptr != '\0') {
		if (*ptr == o)
			*ptr = r;
		ptr++;
	}
	return string_par;
}

void send_params(
	int stream_id)
{
	int sock_id,debug_level=1<<5;
	char buffer[MAX_LINE_SIZE], saved_function_name[50];
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"send_params");
	if (debug&debug_level)
		my_print("sending query_name=%s to %d\n", query_name,stream_id);
	process_busy[stream_id]=1;
	sock_id=sockets_listf[stream_id];
	if (debug&debug_level)
		my_print("sending username=%s to %d\n", username1,sock_id);
	sprintf(buffer, "query_name=%s\n", query_name);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "bind_file_separator=%c\n", c_bind_file_separator);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "silent=%d\n", silent);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "socket_port_nbr=%d\n", socket_port_nbr);
	sendall(sock_id,buffer,strlen(buffer));
	if (debug&debug_level)
		my_print("sending username=%s to %d\n", username1,stream_id);
	sprintf(buffer, "username=%s\n", username1);
	sendall(sock_id,buffer,strlen(buffer));
	if (debug&debug_level)
		my_print("sending file_name=%s to %d\n", file_name,stream_id);
	if (strlen(file_name) > 0){
		sprintf(buffer, "file_name=%s\n", file_name);
		sendall(sock_id,buffer,strlen(buffer));
	}
	if (strlen(bind_sqlsetname) > 0){
		sprintf(buffer, "bind_sqlsetname=%s\n", bind_sqlsetname);
		sendall(sock_id,buffer,strlen(buffer));
	}
	sprintf(buffer, "binds_from_sqlset=%d\n", binds_from_sqlset);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "print_plan=%d\n", print_plan);
	sendall(sock_id,buffer,strlen(buffer));
	snprintf(buffer,MAX_LINE_SIZE-1, "sql=%s\n", replace_n_r(dyn_statement, '\n', '\r'));
	sendall(sock_id,buffer,strlen(buffer));
	if (debug&debug_level)
		my_print("sending sql=%s to %d\n", dyn_statement,stream_id);
	if (strlen(dyn_statement)>MAX_LINE_SIZE-5) my_print("The sql statement in the parfile cannot be longer than %d, please put long statements in separate files\nor add 1: before the file name (e.g.sql=file=1:....)\n",MAX_LINE_SIZE-5);
	if (strlen(setup_script) > 0){
		snprintf(buffer, MAX_LINE_SIZE-1,"setup_sql=%s\n",
			replace_n_r(setup_script, '\n', '\r'));
		sendall(sock_id,buffer,strlen(buffer));
		if (strlen(setup_script)>MAX_LINE_SIZE-5) my_print("The setup script in the parfile cannot be longer than %d, you can use a stored procedure to do what you want to do in the setup script\n",MAX_LINE_SIZE-5);
	}
	if (strlen(exec_stats_file_name) > 0){
		sprintf(buffer, "exec_stats_file=%s\n", exec_stats_file_name);
		sendall(sock_id,buffer,strlen(buffer));
	}
	sprintf(buffer, "bind_results_to_db=%d\n", bind_results_to_db);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "check_for_quit_every=%d\n", check_for_quit_every);
	sendall(sock_id,buffer,strlen(buffer));
	if (perf_db_uname[0]!='\0'){
		sprintf(buffer, "uname_bind_results_to_db=%s\n", perf_db_uname);
		sendall(sock_id,buffer,strlen(buffer));
	}
	if (strlen(socket_host_ip) > 0){
		sprintf(buffer, "socket_host_ip=%s\n", socket_host_ip);
		sendall(sock_id,buffer,strlen(buffer));
	}
	sprintf(buffer, "flush_bind_results_every=%d\n", flush_results_every);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "max_time=%ld\n", max_time);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "think_time_min=%d\n", think_time_min);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "use_dbms_sqltune0=%d\n", use_dbms_sqltune0);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "think_time_max=%d\n", think_time_max);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "print_my_stats=%d\n", print_my_stats);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "rows_to_spool=%d\n", rows_to_spool);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "print_pga_stats=%d\n", print_pga_stats);
	sendall(sock_id,buffer,strlen(buffer));
	if (strlen(run_desc) > 0){
		sprintf(buffer, "run_description=%s\n", run_desc);
		sendall(sock_id,buffer,strlen(buffer));
	}
	if (strlen(bind_file_name) > 0){
		sprintf(buffer, "bind_file_name=%s\n", bind_file_name);
		sendall(sock_id,buffer,strlen(buffer));
	}
	if (strlen(debug_file_name) > 0){
		sprintf(buffer, "debug_file_name=%s\n", debug_file_name);
		sendall(sock_id,buffer,strlen(buffer));
	}
	if (strlen(log_file_name) > 0){
		sprintf(buffer, "log_file_name=%s\n", log_file_name);
		sendall(sock_id,buffer,strlen(buffer));
	}
	if (strlen(sqlset_name) > 0){
		sprintf(buffer, "save_sqlset=%s\n", sqlset_name);
		sendall(sock_id,buffer,strlen(buffer));
	}
	sprintf(buffer, "trial_nbr=%d\n", trial_nbr);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "release_px_slaves=%d\n", release_px_slaves);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "exec_count=%d\n", exec_count);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "save_sqlmon=%d\n", save_sqlmon);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "mon_type=%s\n", sqlmon_type);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "max_rows=%d\n", max_rows);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "save_mystats=%d\n", save_mystats);
	sendall(sock_id,buffer,strlen(buffer));
	sprintf(buffer, "series_of_queries=%d\n", series_of_queries);
	sendall(sock_id,buffer,strlen(buffer));
	if (strlen(stop_file_name) > 0){
		sprintf(buffer, "stop_file_name=%s\n", stop_file_name);
		sendall(sock_id,buffer,strlen(buffer));
	}
	if (debug&debug_level)
		my_print("sending done=%s\n", query_name);
	sprintf(buffer, "done=\n");
	sendall(sock_id,buffer,strlen(buffer));
	strcpy(function_name,saved_function_name);
}

int get_idle_child(
	int degree,
	int *finished,
	int *prc_id,
	char *username)
{
	int     i,end_snap_id, ret_code,ret_bytes,returned, set_it=0,debug_level=1<<6;
	char    buffer[10], saved_function_name[50];
	fd_set inc_set, act_set;
	struct timeval tv, ctime;
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"get_idle_child");

	// we first look to see if any local process is available
	// if so, we just return it's id
	if (debug&debug_level)
		my_print("looking for an available process among degree=%d finished=%d\n",degree,*finished);
	for (i = 0; i < degree; i++)
		if (!process_busy[i]) {
			process_busy[i] = 1;
			if (debug&debug_level)
				my_print("process %d is available\n", i);
			*prc_id=i;
			strcpy(function_name,saved_function_name);
			return (0);
		}
	// arriving here means that no processes are free
	// so we wait for a message, either on the local pipe, or on sockets
	// we'll use select for this
	returned=0;
	*prc_id=-1;
	set_it=1;
	while (returned==0) {
		FD_ZERO(&act_set);
		for (i=0;i<degree;i++) FD_SET(sockets_listf[i],&act_set);

		if (debug&debug_level)
			my_print("waiting for a process among %d to become available set_it=%d\n",degree,set_it);
		inc_set=act_set;
		tv.tv_sec=10;
		tv.tv_usec=0;
		returned=select(FD_SETSIZE,&inc_set,NULL,NULL,&tv);
		if (returned<0) return -1;
		if (returned) { // returned>0 means there's something to read
			if (debug&debug_level)
				my_print("got a message\n");
			for (i=0;i<degree;i++){
				if (FD_ISSET(sockets_listf[i],&inc_set)){
					ret_bytes = read(sockets_listf[i], (void*)&buffer, sizeof(buffer));
					if (debug&debug_level)
						my_print("got a message from socket %d\n",i);
					process_busy[i]=set_it;
					if (*prc_id==-1) *prc_id=i;
					set_it=0;
					strcpy(function_name,saved_function_name);
					returned=1;
				}
			}
		}
		if (asked_to_quit()) returned=-1;
			if (awr_period>0) { // check if we are awr_period seconds away from the last snapshot taken
				ret_code=gettimeofday(&ctime,NULL);
				if ((ctime.tv_sec-awr_time.tv_sec)> awr_period) { // we are more than the specified amount of seconds away, so we take a snapshot
					int sqlerr;
					/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

					/* exec sql at main_db select
						dbms_workload_repository.create_snapshot
						into :end_snap_id from
						dual; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 13;
     sqlstm.arrsiz = 9;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "select dbms_workload_repository . create_snapshot into :\
b0 from dual ";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )1689;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.sqlpfmem = (unsigned int  )0;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqhstv[0] = (unsigned char  *)&end_snap_id;
     sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqphss = sqlstm.sqhsts;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqpins = sqlstm.sqinds;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlstm.sqpadto = sqlstm.sqadto;
     sqlstm.sqptdso = sqlstm.sqtdso;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


					sqlerr=sqlca.sqlcode;
					printf("Just created snapshot id %d (sqlerr=%d)\n", end_snap_id,sqlerr);
					awr_time.tv_sec=ctime.tv_sec;
				}
			}

	}
	strcpy(function_name,saved_function_name);
	return (returned);
}
int wait_for_all_to_finish(
	int degree,
	char *username
)
{
	int     ret_code, i, begin_snap_id, ret_bytes,returned, set_it=0,debug_level=1<<6;
	char    buffer[30],saved_function_name[50], *p, *s,msg_to_send[50];
	fd_set inc_set, act_set;
	struct timeval tv, ctime;

	// we first look to see if any local process is available
	// if so, we just return it's id
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"wait_for_all_to_finish");
	if (debug&debug_level)
		my_print("waiting for %d to finish\n",degree);
	returned=0;
	while (returned==0) {
		set_it=0;
		FD_ZERO(&act_set);
		for (i=0;i<degree;i++)
			if (process_busy[i]==1){
				set_it++;
				FD_SET(sockets_listf[i],&act_set);
			} else if (process_busy[i]!=2) {
				send_msg_to_master(sockets_listf[i],"exit=\n");
				process_busy[i]=2;
				}
		if (set_it>0) {
			if (debug&debug_level)
				my_print("waiting for %d processes among %d to finish\n",set_it,degree);
			inc_set=act_set;
			tv.tv_sec=10;
			tv.tv_usec=0;
			returned=select(FD_SETSIZE,&inc_set,NULL,NULL,&tv);
			if (returned<0) return -1;
			if (returned) { // returned>0 means there's something to read
				if (debug&debug_level)
					my_print("someone finished\n");
				for (i=0;i<degree;i++){
					if (FD_ISSET(sockets_listf[i],&inc_set)){
						if (debug&debug_level)
							my_print("reading from socket\n");
						ret_bytes = read(sockets_listf[i], (void*)&buffer, sizeof(buffer));
						if (debug&debug_level)
							my_print("got a message from socket %d, message %s\n",i,buffer);
						if (ret_bytes<3) 
								process_busy[i]=0;
						returned=0;
					}
				}
			}
		} else returned=1;
		if (awr_period>0) { // check if we are awr_period seconds away from the last snapshot taken
			ret_code=gettimeofday(&ctime,NULL);
			if ((ctime.tv_sec-awr_time.tv_sec)> awr_period) { // we are more than the specified amount of seconds away, so we take a snapshot
				int sqlerr;
				/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

				/* exec sql at main_db select
					dbms_workload_repository.create_snapshot
					into :begin_snap_id from
					dual; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select dbms_workload_repository . create_snapshot into :b\
0 from dual ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1715;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&begin_snap_id;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				sqlerr=sqlca.sqlcode;
				printf("Just created snapshot id %d (sqlerr=%d)\n", begin_snap_id,sqlerr);
				awr_time.tv_sec=ctime.tv_sec;
			}
		}
//		if (asked_to_quit()) returned=-1;
	}
	strcpy(function_name,saved_function_name);
	return (returned);
}


int get_master_message(
	int socket_id,
	int wait_time_us)
{
	char    buffer[MAX_LINE_SIZE], *tn, *cmd, *chr, saved_function_name[50];
	int buflen=MAX_LINE_SIZE,debug_level=1<<9, ret_len;
	fd_set inc_set, save_set;
	struct timeval tv;
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"get_master_message");
	FD_ZERO(&save_set);
	FD_SET(socket_id,&save_set);
	if (wait_time_us>1000000) {
		tv.tv_sec=wait_time_us/1000000;
		tv.tv_usec=wait_time_us-tv.tv_sec*1000000;
	} else {
		tv.tv_sec = 0;
		tv.tv_usec = wait_time_us;
	}
	int returned = select(FD_SETSIZE, &save_set, NULL, NULL, &tv);
	file_name[0]='\0';
	log_file_name[0]='\0';
	bind_file_name[0]='\0';
	if (!returned) return 3; // socket timed out after a minute, return to see if anything local happened
	while (1){
              if(debug&debug_level) my_print ("len of buffer=%d\n",strlen(buffer));
		ret_len=get_lf(socket_id, buffer,MAX_LINE_SIZE);
              if (debug&debug_level) my_print("in %d buffer=%s\n",mypid,buffer);
		cmd = buffer;
		tn = strchr(buffer, '=');
		*tn = '\0';
		tn++;
		if (!strncasecmp(cmd, "exit", 4)) {
			if (debug&debug_level)
				my_print("got exit\n");
			strcpy(function_name,saved_function_name);
			return 0;
		}
		if (!strncasecmp(cmd, "abort", 5)) {
			if (debug&debug_level)
				my_print("got abort\n");
			strcpy(function_name,saved_function_name);
			return 4;
		}
		if (!strncasecmp(cmd, "done", 4)) {
                      if (debug&debug_level) my_print("got done\n");
			strcpy(function_name,saved_function_name);
			return 2;
		}
		if (!strncasecmp(cmd, "start", 5)) {
                      if (debug&debug_level) my_print("got order to start %s processes\n",tn);
			degree=atoi(tn);
			strcpy(function_name,saved_function_name);
			return 1;
		}
		if (*tn != '\0') {
                      if (debug&debug_level) my_print("tn=%s\n",replace_n_r(tn, '\r', '\n'));
			if (!strncasecmp(cmd, "bind_file_separator", 19))
				c_bind_file_separator=*tn;
			if (!strncasecmp(cmd, "uname_bind_results_to_db", 24))
				strncpy(perf_db_uname,tn,255);
			if (!strncasecmp(cmd, "username", 8))
				strncpy(username, tn,255);
			if (!strncasecmp(cmd, "query_name", 9))
				strncpy(query_name, tn,199);
			if (!strncasecmp(cmd, "file_name", 9))
				strncpy(file_name, tn,MAX_FILENAME_LEN);
			if (!strncasecmp(cmd, "print_plan", 10))
				print_plan = atoi(tn);
			if (!strncasecmp(cmd, "bind_results_to_db", 18))
				bind_results_to_db=atoi(tn);
			if (!strncasecmp(cmd, "sql", 3))
				strncpy(dyn_statement, replace_n_r(tn, '\r', '\n'),MAX_STMT_SIZE-1);
			if (!strncasecmp(cmd, "setup_sql", 9))
				strncpy(setup_script,
				       replace_n_r(tn, '\r', '\n'),MAX_STMT_SIZE-1);
			if (!strncasecmp(cmd, "max_time", 7))
				max_time = (long) strtod(tn, NULL);
			if (!strncasecmp(cmd, "print_my_stats", 14))
				print_my_stats = atoi(tn);
			if (!strncasecmp(cmd, "print_pga_stats", 15))
				print_pga_stats = atoi(tn);
			if (!strncasecmp(cmd, "rows_to_spool", 13))
				rows_to_spool = atoi(tn);
			if (!strncasecmp(cmd, "save_mystats", 12))
				save_mystats = atoi(tn);
			if (!strncasecmp(cmd, "bind_file_name", 14))
				strncpy(bind_file_name, tn,MAX_FILENAME_LEN);
			if (!strncasecmp(cmd, "debug_file_name", 15))
				strncpy(debug_file_name, tn,MAX_FILENAME_LEN);
			if (!strncasecmp(cmd, "run_description", 15))
				strncpy(run_desc, tn,100);
			if (!strncasecmp(cmd, "log_file_name", 13))
				strncpy(log_file_name, tn,MAX_FILENAME_LEN);
			if (!strncasecmp(cmd, "stop_file_name", 14))
				strncpy(stop_file_name, tn,MAX_FILENAME_LEN);
			if (!strncasecmp(cmd, "save_sqlset", 11))
				{
					strncpy(sqlset_name, tn,30);
					sqlset_save=1;
				}
			if (!strncasecmp(cmd, "socket_host_ip", 14))
				strncpy(socket_host_ip, tn,49);
			if (!strncasecmp(cmd, "exec_stats_file", 15))
				strncpy(exec_stats_file_name, tn,MAX_FILENAME_LEN);
			if (!strncasecmp(cmd, "bind_sqlsetname", 15))
				strncpy(bind_sqlsetname, tn,MAX_FILENAME_LEN);
			if (!strncasecmp(cmd, "series_of_queries", 17))
				series_of_queries = atoi(tn);
			if (!strncasecmp(cmd, "trial_nbr", 9))
				trial_nbr = atoi(tn);
			if (!strncasecmp(cmd, "use_dbms_sqltune0", 17))
				use_dbms_sqltune0 = atoi(tn);
			if (!strncasecmp(cmd, "exec_count", 10))
				exec_count = atoi(tn);
			if (!strncasecmp(cmd, "think_time_min", 14))
				think_time_min = atoi(tn);
			if (!strncasecmp(cmd, "think_time_max", 14))
				think_time_max = atoi(tn);
			if (!strncasecmp(cmd, "release_px_slaves", 17))
				release_px_slaves = atoi(tn);
			if (!strncasecmp(cmd, "check_for_quit_every", 20))
				check_for_quit_every = atoi(tn);
			if (!strncasecmp(cmd, "socket_port_nbr", 15))
				socket_port_nbr = atoi(tn);
			if (!strncasecmp(cmd, "max_rows", 8))
				max_rows = atoi(tn);
			if (!strncasecmp(cmd, "binds_from_sqlset", 17))
				binds_from_sqlset = atoi(tn);
			if (!strncasecmp(cmd, "flush_bind_results_every", 24))
				flush_results_every = atoi(tn);
			if (!strncasecmp(cmd, "save_sqlmon", 11))
				save_sqlmon = atoi(tn);
			if (!strncasecmp(cmd, "mon_type", 8))
				strncpy(sqlmon_type,tn,20);
		}
	}
	if (debug&debug_level)
		my_print("quitting after EOF or error %d\n", errno);
	strcpy(function_name,saved_function_name);
	return 0;
}

void get_sql_mon(
	char *d_file_name,
	char *Vchar_prev_sql_id,
	int VPrev_Exec_Id)
{
	int     Vlobsize,debug_level=1<<12;
	char    sqlm_file_name[MAX_FILENAME_SIZE],saved_function_name[50];
	FILE   *sqlm_fp;
	OCIClobLocator *SQLMon;
	/* EXEC SQL at main_db ALLOCATE :SQLMon; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1741;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&SQLMon;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	sprintf(sqlm_file_name, "%s%s_%d.html", logfile_dir,d_file_name,trial_nbr);
	sqlm_fp = fopen(sqlm_file_name, "w");
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"get_sql_mon");
	if (sqlm_fp != NULL) {
		/*exec sql at main_db select dbms_sqltune.report_sql_monitor(
			:Vchar_prev_sql_id,
			sys_context('USERENV',
				    'SID'),
			'',
			'',
			:VPrev_Exec_Id,
			'',
			'',
			'',
			'',
			'',
			'',
			'',
			'',
			'',
			'',
			'',
			'',
			:sqlmon_type,
			'')     into :SQLMon from dual;*/
	if (debug&debug_level) my_print("getting sqlmon for sql_id=%s and exec_id=%d, type=%s\n",Vchar_prev_sql_id,VPrev_Exec_Id,sqlmon_type);
	/* exec sql at main_db select dbms_sqltune.report_sql_monitor(
				sql_id=>:Vchar_prev_sql_id,
				session_id=>sys_context('USERENV',
					    'SID'),
				sql_exec_id=>:VPrev_Exec_Id,
				type=>:sqlmon_type)     into :SQLMon from dual; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select dbms_sqltune . report_sql_monitor ( sql_id => :b0 , s\
ession_id => sys_context ( 'USERENV' , 'SID' ) , sql_exec_id => :b1 , type => \
:b2 ) into :b3 from dual ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1767;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.sqlpfmem = (unsigned int  )0;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)Vchar_prev_sql_id;
 sqlstm.sqhstl[0] = (unsigned long )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&VPrev_Exec_Id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sqlmon_type;
 sqlstm.sqhstl[2] = (unsigned long )21;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&SQLMon;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(void *);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if (sqlca.sqlcode != 0||debug&debug_level)
			my_print("after select got sqlcode=%d\n", sqlca.sqlcode);
		if (sqlca.sqlcode!=0) {
			strcpy(function_name,saved_function_name);
			return;
		}
		/* EXEC SQL at main_db LOB DESCRIBE :SQLMon GET LENGTH INTO :Vlobsize; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1805;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&SQLMon;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&Vlobsize;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if (debug&debug_level||sqlca.sqlcode != 0)
			my_print("getting monitor for %s exec_id %d sqlca.sqlcode=%d, vlobsize=%d\n", Vchar_prev_sql_id, VPrev_Exec_Id, sqlca.sqlcode, Vlobsize);
		if (Vlobsize > 0) {
			int     VOffset = 1, vMaxSize = 40000;
			/* varchar *VSQLMonitor =
				(varchar *) malloc(vMaxSize + 4); */ 
varchar *VSQLMonitor
 = malloc((vMaxSize+4));

			VSQLMonitor->len = Vlobsize;
			/* exec sql var VSQLMonitor is varchar(40000); */ 

			/* EXEC SQL at main_db LOB READ :Vlobsize FROM :SQLMon at :VOffset
				INTO :VSQLMonitor; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1835;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&Vlobsize;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&SQLMon;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(void *);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&VOffset;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)VSQLMonitor;
   sqlstm.sqhstl[3] = (unsigned long )40002;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)0;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			fprintf(sqlm_fp, "%.*s", VSQLMonitor->len,
				VSQLMonitor->arr);
			if (debug&debug_level)
				my_print("Got a chunk of size d, sqlca.sqlcode=%d Vlobsize=%d VMaxSize=%d\n",
				       /*VSQLMonitor->len, */
				       sqlca.sqlcode, Vlobsize,
				       vMaxSize);
			while (sqlca.sqlcode == 0) {
				/* EXEC SQL at main_db LOB READ :vMaxSize FROM :SQLMon
					INTO :VSQLMonitor; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1877;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&vMaxSize;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&SQLMon;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(void *);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)VSQLMonitor;
    sqlstm.sqhstl[3] = (unsigned long )40002;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				fprintf(sqlm_fp, "%.*s", VSQLMonitor->len,
					VSQLMonitor->arr);
				if (debug&debug_level)
					my_print("in loop Got a chunk of size %d, sqlca.sqlcode=%d vMaxSize=%d	at offset=%d\n", VSQLMonitor->len, sqlca.sqlcode, vMaxSize, VOffset);
			}
			free(VSQLMonitor);
			fclose(sqlm_fp);
		}
	} else
		my_print("error opening sqlm file %s\n", sqlm_file_name);
	strcpy(function_name,saved_function_name);
}

void print_sql_plan(
	FILE * log_fp,
	char *Vchar_prev_sql_id,
	int Vchild_n,
	long real_time)
{
	char    Varr_plan[200];
	int     i, c_rows, rows_this_turn;
	fprintf(log_fp,
		"Execution Elapsed or query %s is %ld\n",
		query_name, real_time);
	/* exec sql at main_db select child_number
			into :Vchild_n
			from v$sql sq, (select sql_child_address
				from (select sql_exec_id,sql_plan_hash_value
				from v$sql_monitor 
				where sid=sys_context('userenv','sid')
				and :Vchar_prev_sql_id = sql_id
				and action=to_char(:seq_nbr)
				order by sql_exec_start desc)
				where rownum=1) cn
			where sq.sal_id=:Vchar_prev_sql_id
			and sq.child_address=cn.sql_child_address; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select child_number into :b0 from v$sql sq , ( select sql_ch\
ild_address from ( select sql_exec_id , sql_plan_hash_value from v$sql_monitor\
 where sid = sys_context ( 'userenv' , 'sid' ) and :b1 = sql_id and action = t\
o_char ( :b2 ) order by sql_exec_start desc ) where rownum = 1 ) cn where sq .\
 sal_id = :b1 and sq . child_address = cn . sql_child_address ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1919;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.sqlpfmem = (unsigned int  )0;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&Vchild_n;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)Vchar_prev_sql_id;
 sqlstm.sqhstl[1] = (unsigned long )0;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&seq_nbr;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)Vchar_prev_sql_id;
 sqlstm.sqhstl[3] = (unsigned long )0;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* exec sql at main_db declare c0 cursor for select * from table(
	dbms_xplan.display_cursor(:Vchar_prev_sql_id,
				  :Vchild_n
				  /o,'ALLSTATS,LAST' o/ )); */ 

	/* exec sql open c0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0016;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1957;
 sqlstm.selerr = (unsigned short)100;
 sqlstm.sqlpfmem = (unsigned int  )0;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)Vchar_prev_sql_id;
 sqlstm.sqhstl[0] = (unsigned long )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&Vchild_n;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	c_rows = 0;
	rows_this_turn = 50;
	for (; sqlca.sqlcode==0;) {
		/* exec sql fetch c0 into:Varr_plan; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1987;
  sqlstm.selerr = (unsigned short)100;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)Varr_plan;
  sqlstm.sqhstl[0] = (unsigned long )200;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		//rows_this_turn = sqlca.sqlerrd[2] - c_rows;
		//c_rows = sqlca.sqlerrd[2];
		if (sqlca.sqlcode==0)
			fprintf(log_fp, "%s\n", Varr_plan);
	}
	/* exec sql close c0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2013;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


}

void save_to_sqlset(
	char *Vchar_prev_sql_id,
	char *sqlset_name)
{
	char    v_ch_add_sqlset[400],saved_function_name[50];
	int     debug_level=1<<12;
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"save_sql_set");
	if (debug&debug_level) my_print("save_to_sqlset called sqlset=%s and sqlid=%s\n",sqlset_name,Vchar_prev_sql_id);
	sprintf(v_ch_add_sqlset, "declare\ncur DBMS_SQLTUNE.SQLSET_CURSOR;"
			"\nbegin"
				"\nOPEN cur FOR"
				"\nSELECT VALUE(P)"
				"\nFROM table("
				"\nDBMS_SQLTUNE.SELECT_CURSOR_CACHE("
				    "\n'sql_id=''%s''')) P;"
				"\nDBMS_SQLTUNE.LOAD_SQLSET("
				    "\nsqlset_name => '%s',"
				    "\npopulate_cursor => cur"
				"\n);"
			"\nend;", Vchar_prev_sql_id,
		sqlset_name);
	/* exec sql at main_db execute immediate :v_ch_add_sqlset; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2035;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)v_ch_add_sqlset;
 sqlstm.sqhstl[0] = (unsigned long )400;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (sqlca.sqlcode != 0)
		my_print("\nsqlset_name=%s\n%.70s\n", sqlset_name,
		       sqlca.sqlerrm.sqlerrmc);
	strcpy(function_name,saved_function_name);
}

void get_v_data(
	char *query_name,
	char *Vchar_prev_sql_id,
	int *Vchild_n,
	int *VPrev_Exec_Id,
	int trial_nbr,
	int executions,
	long rows_p,
	long real_time,
	long first_fetch,
	char *loc_time,
	int pid)
{
	char    Vqname[250], VVchar_prev_sql_id[30],saved_function_name[50],sql_exec_start[20],vcur_sql_id[30], v_SQL_PROFILE[65], 
		v_SQL_PATCH[129], v_SQL_PLAN_BASELINE[129];
	char  v_EXACT_MATCHING_SIGNATURE[41];
	char v_FORCE_MATCHING_SIGNATURE[41];
	int     VVPrev_Exec_Id,debug_level=1<<12;
	int v_instance=1;
	long sql_plan_hash_value;
	static long int v_rows_inserted_into_rt=0;
	char    v_PX_IS_CROSS_INSTANCE[2];
	double		v_IO_CELL_OFFLOAD_ELIGIBLE_BYTES,
		        v_px_servers_requested,
		        v_px_servers_allocated,
		        v_ELAPSED_TIME,
		        v_QUEUING_TIME,
		        v_CPU_TIME,
		        v_FETCHES,
		        v_BUFFER_GETS,
		        v_DISK_READS,
		        v_DIRECT_WRITES,
		        v_IO_INTERCONNECT_BYTES,
		        v_PHYSICAL_READ_REQUESTS,
		        v_PHYSICAL_READ_BYTES,
		        v_PHYSICAL_WRITE_REQUESTS,
		        v_PHYSICAL_WRITE_BYTES,
		        v_APPLICATION_WAIT_TIME,
		        v_CONCURRENCY_WAIT_TIME,
		        v_CLUSTER_WAIT_TIME,
		        v_USER_IO_WAIT_TIME,
		        v_PLSQL_EXEC_TIME,
		        v_JAVA_EXEC_TIME,
		        v_im_scans,
		        v_im_scan_bytes_uncompressed,
		        v_im_scan_bytes_inmemory;
    //if (*Vchar_prev_sql_id=='\0') return;
	v_IO_CELL_OFFLOAD_ELIGIBLE_BYTES=0.0;
    v_px_servers_requested=0.0;
    v_px_servers_allocated=0.0;
    v_ELAPSED_TIME=0.0;
    v_QUEUING_TIME=0.0;
    v_CPU_TIME=0.0;
    v_FETCHES=0.0;
    v_BUFFER_GETS=0.0;
    v_DISK_READS=0.0;
    v_DIRECT_WRITES=0.0;
    v_IO_INTERCONNECT_BYTES=0.0;
    v_PHYSICAL_READ_REQUESTS=0.0;
    v_PHYSICAL_READ_BYTES=0.0;
    v_PHYSICAL_WRITE_REQUESTS=0.0;
    v_PHYSICAL_WRITE_BYTES=0.0;
    v_APPLICATION_WAIT_TIME=0.0;
    v_CONCURRENCY_WAIT_TIME=0.0;
    v_CLUSTER_WAIT_TIME=0.0;
    v_USER_IO_WAIT_TIME=0.0;
    v_PLSQL_EXEC_TIME=0.0;
    v_JAVA_EXEC_TIME=0.0;
    v_im_scans=0.0;
    v_im_scan_bytes_uncompressed=0.0;
    v_im_scan_bytes_inmemory=0.0;
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"get_v_data");
	VVchar_prev_sql_id[0]='\0';

	/*VVChild_n=0*/;
	VVPrev_Exec_Id=0;
	sql_plan_hash_value=0;
	strcpy(VVchar_prev_sql_id, v_sql_id);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	sql_exec_start[0]='\0';
	/* exec sql at main_db select sql_exec_id, sql_plan_hash_value, st_time
			into :VVPrev_Exec_Id,:sql_plan_hash_value, :sql_exec_start
			from (select sql_exec_id,sql_plan_hash_value, to_char(sql_exec_start,'dd/mm/yyyy hh24:mi:ss') st_time
			from v$sql_monitor 
			where sid=sys_context('userenv','sid')
			and :VVchar_prev_sql_id = sql_id
			and action=to_char(:seq_nbr)
			and sql_exec_start >= to_timestamp(:loc_time, 'dd/mm/yyyy hh24:mi:ss.ff9')
            order by sql_exec_start desc)
			where rownum=1
			--and sql_exec_start >= to_timestamp(:loc_time, 'dd/mm/yyyy hh24:mi:ss')
			; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select sql_exec_id , sql_plan_hash_value , st_time into :b0 \
, :b1 , :b2 from ( select sql_exec_id , sql_plan_hash_value , to_char ( sql_ex\
ec_start , 'dd/mm/yyyy hh24:mi:ss' ) st_time from v$sql_monitor where sid = sy\
s_context ( 'userenv' , 'sid' ) and :b3 = sql_id and action = to_char ( :b4 ) \
and sql_exec_start >= to_timestamp ( :b5 , 'dd/mm/yyyy hh24:mi:ss.ff9' ) order\
 by sql_exec_start desc ) where rownum = 1 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2061;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.sqlpfmem = (unsigned int  )0;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&VVPrev_Exec_Id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&sql_plan_hash_value;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sql_exec_start;
 sqlstm.sqhstl[2] = (unsigned long )20;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)VVchar_prev_sql_id;
 sqlstm.sqhstl[3] = (unsigned long )30;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&seq_nbr;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)loc_time;
 sqlstm.sqhstl[5] = (unsigned long )0;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (debug&debug_level)
		my_print("prev_id=%s, prev_exec_id=%d and , query=%s  seq_nbr(action)=%d, child_nbr=%d sql_exec_start=%s loc_time=%s sqlcode=%d\n", VVchar_prev_sql_id, VVPrev_Exec_Id,  query_name,seq_nbr,VVChild_n, sql_exec_start, loc_time, sqlca.sqlcode);
	v_PX_IS_CROSS_INSTANCE[0]='\0';
	if (trial_nbr != 0) {
		if (v_db_version>12010) 
			/* exec sql at main_db select
				to_number(sys_context('USERENV','INSTANCE')),
				nvl(SQL_PROFILE,'None'),
				nvl(SQL_PATCH,'None'),
				nvl(SQL_PLAN_BASELINE,'Non'),
				EXACT_MATCHING_SIGNATURE,
				FORCE_MATCHING_SIGNATURE,
				nvl(sm.sql_exec_id,0),
				nvl(sq.IO_CELL_OFFLOAD_ELIGIBLE_BYTES,0) /    1024,
				nvl( sm.PX_IS_CROSS_INSTANCE,'N')   ,
				nvl( SM.px_servers_requested,0)     ,
				nvl( SM.px_servers_allocated,0)     ,
				nvl( nvl(SM.ELAPSED_TIME,sq.elapsed_time/decode(sq.executions,0,1,sq.executions)),0)     ,
				nvl( SM.QUEUING_TIME,0)     ,
				nvl( nvl(SM.CPU_TIME,sq.cpu_time/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.FETCHES,sq.fetches/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.BUFFER_GETS,sq.BUFFER_GETS/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.DISK_READS,sq.DISK_READS/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.DIRECT_WRITES,sq.DIRECT_WRITES/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.IO_INTERCONNECT_BYTES,sq.IO_INTERCONNECT_BYTES/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.PHYSICAL_READ_REQUESTS,sq.PHYSICAL_READ_REQUESTS/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.PHYSICAL_READ_BYTES,sq.PHYSICAL_READ_BYTES/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.PHYSICAL_WRITE_REQUESTS,sq.PHYSICAL_WRITE_REQUESTS/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.PHYSICAL_WRITE_BYTES,sq.PHYSICAL_WRITE_BYTES/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.APPLICATION_WAIT_TIME,sq.APPLICATION_WAIT_TIME/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.CONCURRENCY_WAIT_TIME,sq.CONCURRENCY_WAIT_TIME/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.CLUSTER_WAIT_TIME,sq.CLUSTER_WAIT_TIME/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.USER_IO_WAIT_TIME,sq.USER_IO_WAIT_TIME/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.PLSQL_EXEC_TIME,sq.PLSQL_EXEC_TIME/decode(sq.executions,0,1,sq.executions)), 0)     ,
				nvl( nvl(SM.JAVA_EXEC_TIME,sq.JAVA_EXEC_TIME/decode(sq.executions,0,1,sq.executions)), 0),
				nvl(sq.im_scans/decode(sq.executions,0,1,sq.executions),0),
				nvl(sq.im_scan_bytes_uncompressed/decode(sq.executions,0,1,sq.executions),0),
				nvl(sq.im_scan_bytes_inmemory/decode(sq.executions,0,1,sq.executions),0),
				nvl(sm.sql_plan_hash_value,sq.plan_hash_value)
				into :v_instance,
 				:v_SQL_PROFILE              ,
 				:v_SQL_PATCH                ,
 				:v_SQL_PLAN_BASELINE        ,
 				:v_EXACT_MATCHING_SIGNATURE ,
 				:v_FORCE_MATCHING_SIGNATURE ,
				:VVPrev_Exec_Id,
				:v_IO_CELL_OFFLOAD_ELIGIBLE_BYTES,
				:v_PX_IS_CROSS_INSTANCE,
				:v_px_servers_requested,
				:v_px_servers_allocated,
				:v_ELAPSED_TIME,
				:v_QUEUING_TIME,
				:v_CPU_TIME,
				:v_FETCHES,
				:v_BUFFER_GETS,
				:v_DISK_READS,
				:v_DIRECT_WRITES,
				:v_IO_INTERCONNECT_BYTES,
				:v_PHYSICAL_READ_REQUESTS,
				:v_PHYSICAL_READ_BYTES,
				:v_PHYSICAL_WRITE_REQUESTS,
				:v_PHYSICAL_WRITE_BYTES,
				:v_APPLICATION_WAIT_TIME,
				:v_CONCURRENCY_WAIT_TIME,
				:v_CLUSTER_WAIT_TIME,
				:v_USER_IO_WAIT_TIME,
				:v_PLSQL_EXEC_TIME,
				:v_JAVA_EXEC_TIME,
				:v_im_scans,
				:v_im_scan_bytes_uncompressed,
				:v_im_scan_bytes_inmemory,
				:sql_plan_hash_value
				from v$sql sq
				left join (
					select sys_context('userenv','sid') sid,sm.sql_exec_id,
					sum     (elapsed_time) elapsed_time,
					max     (sm.PX_IS_CROSS_INSTANCE) PX_IS_CROSS_INSTANCE,
					max     (SM.px_servers_requested) px_servers_requested,
					max     (SM.px_servers_allocated) px_servers_allocated,
					sum     (cpu_time) cpu_time,
					sum     (QUEUING_TIME) QUEUING_TIME,
					sum     (FETCHES) FETCHES,
					sum     (BUFFER_GETS) BUFFER_GETS,
					sum     (DISK_READS) DISK_READS,
					sum     (DIRECT_WRITES) DIRECT_WRITES,
					sum     (IO_INTERCONNECT_BYTES) IO_INTERCONNECT_BYTES,
					sum     (PHYSICAL_READ_REQUESTS) PHYSICAL_READ_REQUESTS,
					sum     (PHYSICAL_READ_BYTES) PHYSICAL_READ_BYTES,
					sum     (PHYSICAL_WRITE_REQUESTS) PHYSICAL_WRITE_REQUESTS,
					sum     (PHYSICAL_WRITE_BYTES) PHYSICAL_WRITE_BYTES,
					sum     (APPLICATION_WAIT_TIME) APPLICATION_WAIT_TIME,
					sum     (CONCURRENCY_WAIT_TIME) CONCURRENCY_WAIT_TIME,
					sum     (CLUSTER_WAIT_TIME) CLUSTER_WAIT_TIME,
					sum     (USER_IO_WAIT_TIME) USER_IO_WAIT_TIME,
					sum     (PLSQL_EXEC_TIME) PLSQL_EXEC_TIME,
					sum     (JAVA_EXEC_TIME) JAVA_EXEC_TIME,
					max(sql_plan_hash_value) sql_plan_hash_value
					from gv$sql_monitor sm
					where :VVchar_prev_sql_id = sm.sql_id
					and sm.sql_exec_id=:VVPrev_Exec_Id
					and sql_exec_start>=case when :sql_exec_start is null then sysdate else to_date(:sql_exec_start,'dd/mm/yyyy hh24:mi:ss') end
					group by sm.sql_exec_id) sm
				on(  sm.sid = sys_context('USERENV', 'SID'))
				where :VVchar_prev_sql_id = sq.sql_id and :VVChild_n = sq.child_number; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 39;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlbuft((void **)0, 
     "select to_number ( sys_context ( 'USERENV' , 'INSTANCE' ) ) , nvl ( SQ\
L_PROFILE , 'None' ) , nvl ( SQL_PATCH , 'None' ) , nvl ( SQL_PLAN_BASELINE \
, 'Non' ) , EXACT_MATCHING_SIGNATURE , FORCE_MATCHING_SIGNATURE , nvl ( sm .\
 sql_exec_id , 0 ) , nvl ( sq . IO_CELL_OFFLOAD_ELIGIBLE_BYTES , 0 ) / 1024 \
, nvl ( sm . PX_IS_CROSS_INSTANCE , 'N' ) , nvl ( SM . px_servers_requested \
, 0 ) , nvl ( SM . px_servers_allocated , 0 ) , nvl ( nvl ( SM . ELAPSED_TIM\
E , sq . elapsed_time / decode ( sq . executions , 0 , 1 , sq . executions )\
 ) , 0 ) , nvl ( SM . QUEUING_TIME , 0 ) , nvl ( nvl ( SM . CPU_TIME , sq . \
cpu_time / decode ( sq . executions , 0 , 1 , sq . executions ) ) , 0 ) , nv\
l ( nvl ( SM . FETCHES , sq . fetches / decode ( sq . executions , 0 , 1 , s\
q . executions ) ) , 0 ) , nvl ( nvl ( SM . BUFFER_GETS , sq . BUFFER_GETS /\
 decode ( sq . executions , 0 , 1 , sq . executions ) ) , 0 ) , nvl ( nvl ( \
SM . DISK_READS , sq . DISK_READS / decode ( sq . executions , 0 , 1 , sq . \
executions ) ) , 0 ) , nvl ( nvl ( SM . DI");
   sqlbuft((void **)0, 
     "RECT_WRITES , sq . DIRECT_WRITES / decode ( sq . executions , 0 , 1 , \
sq . executions ) ) , 0 ) , nvl ( nvl ( SM . IO_INTERCONNECT_BYTES , sq . IO\
_INTERCONNECT_BYTES / decode ( sq . executions , 0 , 1 , sq . executions ) )\
 , 0 ) , nvl ( nvl ( SM . PHYSICAL_READ_REQUESTS , sq . PHYSICAL_READ_REQUES\
TS / decode ( sq . executions , 0 , 1 , sq . executions ) ) , 0 ) , nvl ( nv\
l ( SM . PHYSICAL_READ_BYTES , sq . PHYSICAL_READ_BYTES / decode ( sq . exec\
utions , 0 , 1 , sq . executions ) ) , 0 ) , nvl ( nvl ( SM . PHYSICAL_WRITE\
_REQUESTS , sq . PHYSICAL_WRITE_REQUESTS / decode ( sq . executions , 0 , 1 \
, sq . executions ) ) , 0 ) , nvl ( nvl ( SM . PHYSICAL_WRITE_BYTES , sq . P\
HYSICAL_WRITE_BYTES / decode ( sq . executions , 0 , 1 , sq . executions ) )\
 , 0 ) , nvl ( nvl ( SM . APPLICATION_WAIT_TIME , sq . APPLICATION_WAIT_TIME\
 / decode ( sq . executions , 0 , 1 , sq . executions ) ) , 0 ) , nvl ( nvl \
( SM . CONCURRENCY_WAIT_TIME , sq . CONCURRENCY_WAIT_TIME / decode ( sq . ex\
ecutions , 0 , 1 , sq . executions ) ) , 0");
   sqlbuft((void **)0, 
     " ) , nvl ( nvl ( SM . CLUSTER_WAIT_TIME , sq . CLUSTER_WAIT_TIME / dec\
ode ( sq . executions , 0 , 1 , sq . executions ) ) , 0 ) , nvl ( nvl ( SM .\
 USER_IO_WAIT_TIME , sq . USER_IO_WAIT_TIME / decode ( sq . executions , 0 ,\
 1 , sq . executions ) ) , 0 ) , nvl ( nvl ( SM . PLSQL_EXEC_TIME , sq . PLS\
QL_EXEC_TIME / decode ( sq . executions , 0 , 1 , sq . executions ) ) , 0 ) \
, nvl ( nvl ( SM . JAVA_EXEC_TIME , sq . JAVA_EXEC_TIME / decode ( sq . exec\
utions , 0 , 1 , sq . executions ) ) , 0 ) , nvl ( sq . im_scans / decode ( \
sq . executions , 0 , 1 , sq . executions ) , 0 ) , nvl ( sq . im_scan_bytes\
_uncompressed / decode ( sq . executions , 0 , 1 , sq . executions ) , 0 ) ,\
 nvl ( sq . im_scan_bytes_inmemory / decode ( sq . executions , 0 , 1 , sq .\
 executions ) , 0 ) , nvl ( sm . sql_plan_hash_value , sq . plan_hash_value \
) into :b0 , :b1 , :b2 , :b3 , :b4 , :b5 , :b6 , :b7 , :b8 , :b9 , :b10 , :b\
11 , :b12 , :b13 , :b14 , :b15 , :b16 , :b17 , :b18 , :b19 , :b20 , :b21 , :\
b22 , :b23 , :b24 , :b25 , :b26 , :b27 , :");
   sqlbuft((void **)0, 
     "b28 , :b29 , :b30 , :b31 , :b32 from v$sql sq left join ( select sys_c\
ontext ( 'userenv' , 'sid' ) sid , sm . sql_exec_id , sum ( elapsed_time ) e\
lapsed_time , max ( sm . PX_IS_CROSS_INSTANCE ) PX_IS_CROSS_INSTANCE , max (\
 SM . px_servers_requested ) px_servers_requested , max ( SM . px_servers_al\
located ) px_servers_allocated , sum ( cpu_time ) cpu_time , sum ( QUEUING_T\
IME ) QUEUING_TIME , sum ( FETCHES ) FETCHES , sum ( BUFFER_GETS ) BUFFER_GE\
TS , sum ( DISK_READS ) DISK_READS , sum ( DIRECT_WRITES ) DIRECT_WRITES , s\
um ( IO_INTERCONNECT_BYTES ) IO_INTERCONNECT_BYTES , sum ( PHYSICAL_READ_REQ\
UESTS ) PHYSICAL_READ_REQUESTS , sum ( PHYSICAL_READ_BYTES ) PHYSICAL_READ_B\
YTES , sum ( PHYSICAL_WRITE_REQUESTS ) PHYSICAL_WRITE_REQUESTS , sum ( PHYSI\
CAL_WRITE_BYTES ) PHYSICAL_WRITE_BYTES , sum ( APPLICATION_WAIT_TIME ) APPLI\
CATION_WAIT_TIME , sum ( CONCURRENCY_WAIT_TIME ) CONCURRENCY_WAIT_TIME , sum\
 ( CLUSTER_WAIT_TIME ) CLUSTER_WAIT_TIME , sum ( USER_IO_WAIT_TIME ) USER_IO\
_WAIT_TIME , sum ( PLSQL_EXEC_TIME ) PLSQL");
   sqlstm.stmt = "_EXEC_TIME , sum ( JAVA_EXEC_TIME ) JAVA_EXEC_TIME , max (\
 sql_plan_hash_value ) sql_plan_hash_value from gv$sql_monitor sm where :b33 =\
 sm . sql_id and sm . sql_exec_id = :b6 and sql_exec_start >= case when :b35 i\
s null then sysdate else to_date ( :b35 , 'dd/mm/yyyy hh24:mi:ss' ) end group \
by sm . sql_exec_id ) sm on ( sm . sid = sys_context ( 'USERENV' , 'SID' ) ) w\
here :b33 = sq . sql_id and :b38 = sq . child_number ";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2107;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_instance;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)v_SQL_PROFILE;
   sqlstm.sqhstl[1] = (unsigned long )65;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)v_SQL_PATCH;
   sqlstm.sqhstl[2] = (unsigned long )129;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)v_SQL_PLAN_BASELINE;
   sqlstm.sqhstl[3] = (unsigned long )129;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)0;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)v_EXACT_MATCHING_SIGNATURE;
   sqlstm.sqhstl[4] = (unsigned long )41;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)0;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)v_FORCE_MATCHING_SIGNATURE;
   sqlstm.sqhstl[5] = (unsigned long )41;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)0;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&VVPrev_Exec_Id;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)0;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_IO_CELL_OFFLOAD_ELIGIBLE_BYTES;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)0;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)v_PX_IS_CROSS_INSTANCE;
   sqlstm.sqhstl[8] = (unsigned long )2;
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)0;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_px_servers_requested;
   sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)0;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_px_servers_allocated;
   sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)0;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&v_ELAPSED_TIME;
   sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)0;
   sqlstm.sqinds[11] = (         int  )0;
   sqlstm.sqharm[11] = (unsigned long )0;
   sqlstm.sqadto[11] = (unsigned short )0;
   sqlstm.sqtdso[11] = (unsigned short )0;
   sqlstm.sqhstv[12] = (unsigned char  *)&v_QUEUING_TIME;
   sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[12] = (         int  )0;
   sqlstm.sqindv[12] = (         short *)0;
   sqlstm.sqinds[12] = (         int  )0;
   sqlstm.sqharm[12] = (unsigned long )0;
   sqlstm.sqadto[12] = (unsigned short )0;
   sqlstm.sqtdso[12] = (unsigned short )0;
   sqlstm.sqhstv[13] = (unsigned char  *)&v_CPU_TIME;
   sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[13] = (         int  )0;
   sqlstm.sqindv[13] = (         short *)0;
   sqlstm.sqinds[13] = (         int  )0;
   sqlstm.sqharm[13] = (unsigned long )0;
   sqlstm.sqadto[13] = (unsigned short )0;
   sqlstm.sqtdso[13] = (unsigned short )0;
   sqlstm.sqhstv[14] = (unsigned char  *)&v_FETCHES;
   sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[14] = (         int  )0;
   sqlstm.sqindv[14] = (         short *)0;
   sqlstm.sqinds[14] = (         int  )0;
   sqlstm.sqharm[14] = (unsigned long )0;
   sqlstm.sqadto[14] = (unsigned short )0;
   sqlstm.sqtdso[14] = (unsigned short )0;
   sqlstm.sqhstv[15] = (unsigned char  *)&v_BUFFER_GETS;
   sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[15] = (         int  )0;
   sqlstm.sqindv[15] = (         short *)0;
   sqlstm.sqinds[15] = (         int  )0;
   sqlstm.sqharm[15] = (unsigned long )0;
   sqlstm.sqadto[15] = (unsigned short )0;
   sqlstm.sqtdso[15] = (unsigned short )0;
   sqlstm.sqhstv[16] = (unsigned char  *)&v_DISK_READS;
   sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[16] = (         int  )0;
   sqlstm.sqindv[16] = (         short *)0;
   sqlstm.sqinds[16] = (         int  )0;
   sqlstm.sqharm[16] = (unsigned long )0;
   sqlstm.sqadto[16] = (unsigned short )0;
   sqlstm.sqtdso[16] = (unsigned short )0;
   sqlstm.sqhstv[17] = (unsigned char  *)&v_DIRECT_WRITES;
   sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[17] = (         int  )0;
   sqlstm.sqindv[17] = (         short *)0;
   sqlstm.sqinds[17] = (         int  )0;
   sqlstm.sqharm[17] = (unsigned long )0;
   sqlstm.sqadto[17] = (unsigned short )0;
   sqlstm.sqtdso[17] = (unsigned short )0;
   sqlstm.sqhstv[18] = (unsigned char  *)&v_IO_INTERCONNECT_BYTES;
   sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[18] = (         int  )0;
   sqlstm.sqindv[18] = (         short *)0;
   sqlstm.sqinds[18] = (         int  )0;
   sqlstm.sqharm[18] = (unsigned long )0;
   sqlstm.sqadto[18] = (unsigned short )0;
   sqlstm.sqtdso[18] = (unsigned short )0;
   sqlstm.sqhstv[19] = (unsigned char  *)&v_PHYSICAL_READ_REQUESTS;
   sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[19] = (         int  )0;
   sqlstm.sqindv[19] = (         short *)0;
   sqlstm.sqinds[19] = (         int  )0;
   sqlstm.sqharm[19] = (unsigned long )0;
   sqlstm.sqadto[19] = (unsigned short )0;
   sqlstm.sqtdso[19] = (unsigned short )0;
   sqlstm.sqhstv[20] = (unsigned char  *)&v_PHYSICAL_READ_BYTES;
   sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[20] = (         int  )0;
   sqlstm.sqindv[20] = (         short *)0;
   sqlstm.sqinds[20] = (         int  )0;
   sqlstm.sqharm[20] = (unsigned long )0;
   sqlstm.sqadto[20] = (unsigned short )0;
   sqlstm.sqtdso[20] = (unsigned short )0;
   sqlstm.sqhstv[21] = (unsigned char  *)&v_PHYSICAL_WRITE_REQUESTS;
   sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[21] = (         int  )0;
   sqlstm.sqindv[21] = (         short *)0;
   sqlstm.sqinds[21] = (         int  )0;
   sqlstm.sqharm[21] = (unsigned long )0;
   sqlstm.sqadto[21] = (unsigned short )0;
   sqlstm.sqtdso[21] = (unsigned short )0;
   sqlstm.sqhstv[22] = (unsigned char  *)&v_PHYSICAL_WRITE_BYTES;
   sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[22] = (         int  )0;
   sqlstm.sqindv[22] = (         short *)0;
   sqlstm.sqinds[22] = (         int  )0;
   sqlstm.sqharm[22] = (unsigned long )0;
   sqlstm.sqadto[22] = (unsigned short )0;
   sqlstm.sqtdso[22] = (unsigned short )0;
   sqlstm.sqhstv[23] = (unsigned char  *)&v_APPLICATION_WAIT_TIME;
   sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[23] = (         int  )0;
   sqlstm.sqindv[23] = (         short *)0;
   sqlstm.sqinds[23] = (         int  )0;
   sqlstm.sqharm[23] = (unsigned long )0;
   sqlstm.sqadto[23] = (unsigned short )0;
   sqlstm.sqtdso[23] = (unsigned short )0;
   sqlstm.sqhstv[24] = (unsigned char  *)&v_CONCURRENCY_WAIT_TIME;
   sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[24] = (         int  )0;
   sqlstm.sqindv[24] = (         short *)0;
   sqlstm.sqinds[24] = (         int  )0;
   sqlstm.sqharm[24] = (unsigned long )0;
   sqlstm.sqadto[24] = (unsigned short )0;
   sqlstm.sqtdso[24] = (unsigned short )0;
   sqlstm.sqhstv[25] = (unsigned char  *)&v_CLUSTER_WAIT_TIME;
   sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[25] = (         int  )0;
   sqlstm.sqindv[25] = (         short *)0;
   sqlstm.sqinds[25] = (         int  )0;
   sqlstm.sqharm[25] = (unsigned long )0;
   sqlstm.sqadto[25] = (unsigned short )0;
   sqlstm.sqtdso[25] = (unsigned short )0;
   sqlstm.sqhstv[26] = (unsigned char  *)&v_USER_IO_WAIT_TIME;
   sqlstm.sqhstl[26] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[26] = (         int  )0;
   sqlstm.sqindv[26] = (         short *)0;
   sqlstm.sqinds[26] = (         int  )0;
   sqlstm.sqharm[26] = (unsigned long )0;
   sqlstm.sqadto[26] = (unsigned short )0;
   sqlstm.sqtdso[26] = (unsigned short )0;
   sqlstm.sqhstv[27] = (unsigned char  *)&v_PLSQL_EXEC_TIME;
   sqlstm.sqhstl[27] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[27] = (         int  )0;
   sqlstm.sqindv[27] = (         short *)0;
   sqlstm.sqinds[27] = (         int  )0;
   sqlstm.sqharm[27] = (unsigned long )0;
   sqlstm.sqadto[27] = (unsigned short )0;
   sqlstm.sqtdso[27] = (unsigned short )0;
   sqlstm.sqhstv[28] = (unsigned char  *)&v_JAVA_EXEC_TIME;
   sqlstm.sqhstl[28] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[28] = (         int  )0;
   sqlstm.sqindv[28] = (         short *)0;
   sqlstm.sqinds[28] = (         int  )0;
   sqlstm.sqharm[28] = (unsigned long )0;
   sqlstm.sqadto[28] = (unsigned short )0;
   sqlstm.sqtdso[28] = (unsigned short )0;
   sqlstm.sqhstv[29] = (unsigned char  *)&v_im_scans;
   sqlstm.sqhstl[29] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[29] = (         int  )0;
   sqlstm.sqindv[29] = (         short *)0;
   sqlstm.sqinds[29] = (         int  )0;
   sqlstm.sqharm[29] = (unsigned long )0;
   sqlstm.sqadto[29] = (unsigned short )0;
   sqlstm.sqtdso[29] = (unsigned short )0;
   sqlstm.sqhstv[30] = (unsigned char  *)&v_im_scan_bytes_uncompressed;
   sqlstm.sqhstl[30] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[30] = (         int  )0;
   sqlstm.sqindv[30] = (         short *)0;
   sqlstm.sqinds[30] = (         int  )0;
   sqlstm.sqharm[30] = (unsigned long )0;
   sqlstm.sqadto[30] = (unsigned short )0;
   sqlstm.sqtdso[30] = (unsigned short )0;
   sqlstm.sqhstv[31] = (unsigned char  *)&v_im_scan_bytes_inmemory;
   sqlstm.sqhstl[31] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[31] = (         int  )0;
   sqlstm.sqindv[31] = (         short *)0;
   sqlstm.sqinds[31] = (         int  )0;
   sqlstm.sqharm[31] = (unsigned long )0;
   sqlstm.sqadto[31] = (unsigned short )0;
   sqlstm.sqtdso[31] = (unsigned short )0;
   sqlstm.sqhstv[32] = (unsigned char  *)&sql_plan_hash_value;
   sqlstm.sqhstl[32] = (unsigned long )sizeof(long);
   sqlstm.sqhsts[32] = (         int  )0;
   sqlstm.sqindv[32] = (         short *)0;
   sqlstm.sqinds[32] = (         int  )0;
   sqlstm.sqharm[32] = (unsigned long )0;
   sqlstm.sqadto[32] = (unsigned short )0;
   sqlstm.sqtdso[32] = (unsigned short )0;
   sqlstm.sqhstv[33] = (unsigned char  *)VVchar_prev_sql_id;
   sqlstm.sqhstl[33] = (unsigned long )30;
   sqlstm.sqhsts[33] = (         int  )0;
   sqlstm.sqindv[33] = (         short *)0;
   sqlstm.sqinds[33] = (         int  )0;
   sqlstm.sqharm[33] = (unsigned long )0;
   sqlstm.sqadto[33] = (unsigned short )0;
   sqlstm.sqtdso[33] = (unsigned short )0;
   sqlstm.sqhstv[34] = (unsigned char  *)&VVPrev_Exec_Id;
   sqlstm.sqhstl[34] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[34] = (         int  )0;
   sqlstm.sqindv[34] = (         short *)0;
   sqlstm.sqinds[34] = (         int  )0;
   sqlstm.sqharm[34] = (unsigned long )0;
   sqlstm.sqadto[34] = (unsigned short )0;
   sqlstm.sqtdso[34] = (unsigned short )0;
   sqlstm.sqhstv[35] = (unsigned char  *)sql_exec_start;
   sqlstm.sqhstl[35] = (unsigned long )20;
   sqlstm.sqhsts[35] = (         int  )0;
   sqlstm.sqindv[35] = (         short *)0;
   sqlstm.sqinds[35] = (         int  )0;
   sqlstm.sqharm[35] = (unsigned long )0;
   sqlstm.sqadto[35] = (unsigned short )0;
   sqlstm.sqtdso[35] = (unsigned short )0;
   sqlstm.sqhstv[36] = (unsigned char  *)sql_exec_start;
   sqlstm.sqhstl[36] = (unsigned long )20;
   sqlstm.sqhsts[36] = (         int  )0;
   sqlstm.sqindv[36] = (         short *)0;
   sqlstm.sqinds[36] = (         int  )0;
   sqlstm.sqharm[36] = (unsigned long )0;
   sqlstm.sqadto[36] = (unsigned short )0;
   sqlstm.sqtdso[36] = (unsigned short )0;
   sqlstm.sqhstv[37] = (unsigned char  *)VVchar_prev_sql_id;
   sqlstm.sqhstl[37] = (unsigned long )30;
   sqlstm.sqhsts[37] = (         int  )0;
   sqlstm.sqindv[37] = (         short *)0;
   sqlstm.sqinds[37] = (         int  )0;
   sqlstm.sqharm[37] = (unsigned long )0;
   sqlstm.sqadto[37] = (unsigned short )0;
   sqlstm.sqtdso[37] = (unsigned short )0;
   sqlstm.sqhstv[38] = (unsigned char  *)&VVChild_n;
   sqlstm.sqhstl[38] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[38] = (         int  )0;
   sqlstm.sqindv[38] = (         short *)0;
   sqlstm.sqinds[38] = (         int  )0;
   sqlstm.sqharm[38] = (unsigned long )0;
   sqlstm.sqadto[38] = (unsigned short )0;
   sqlstm.sqtdso[38] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			else
		/* exec sql at main_db select
		        sys_context('USERENV','INSTANCE'),
				nvl(SQL_PROFILE,'None'),
				nvl(SQL_PATCH,'None'),
				nvl(SQL_PLAN_BASELINE,'Non'),
				EXACT_MATCHING_SIGNATURE,
				FORCE_MATCHING_SIGNATURE,
		        nvl(sm.sql_exec_id,0),
		        nvl(sq.IO_CELL_OFFLOAD_ELIGIBLE_BYTES,0) /    1024,
		        nvl( sm.PX_IS_CROSS_INSTANCE,'N')   ,
		        nvl( SM.px_servers_requested,0)     ,
		        nvl( SM.px_servers_allocated,0)     ,
		        nvl( nvl(SM.ELAPSED_TIME,sq.elapsed_time/decode(sq.executions,0,1,sq.executions)),0)     ,
		        nvl( SM.QUEUING_TIME,0)     ,
		        nvl( nvl(SM.CPU_TIME,sq.cpu_time/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.FETCHES,sq.fetches/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.BUFFER_GETS,sq.BUFFER_GETS/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.DISK_READS,sq.DISK_READS/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.DIRECT_WRITES,sq.DIRECT_WRITES/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.IO_INTERCONNECT_BYTES,sq.IO_INTERCONNECT_BYTES/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.PHYSICAL_READ_REQUESTS,sq.PHYSICAL_READ_REQUESTS/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.PHYSICAL_READ_BYTES,sq.PHYSICAL_READ_BYTES/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.PHYSICAL_WRITE_REQUESTS,sq.PHYSICAL_WRITE_REQUESTS/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.PHYSICAL_WRITE_BYTES,sq.PHYSICAL_WRITE_BYTES/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.APPLICATION_WAIT_TIME,sq.APPLICATION_WAIT_TIME/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.CONCURRENCY_WAIT_TIME,sq.CONCURRENCY_WAIT_TIME/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.CLUSTER_WAIT_TIME,sq.CLUSTER_WAIT_TIME/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.USER_IO_WAIT_TIME,sq.USER_IO_WAIT_TIME/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.PLSQL_EXEC_TIME,sq.PLSQL_EXEC_TIME/decode(sq.executions,0,1,sq.executions)), 0)     ,
		        nvl( nvl(SM.JAVA_EXEC_TIME,sq.JAVA_EXEC_TIME/decode(sq.executions,0,1,sq.executions)), 0),
		        0,0,0,nvl(sm.sql_plan_hash_value,plan_hash_value) plan_hash_value 
		        into :v_instance,
 				:v_SQL_PROFILE              ,
 				:v_SQL_PATCH                ,
 				:v_SQL_PLAN_BASELINE        ,
 				:v_EXACT_MATCHING_SIGNATURE ,
 				:v_FORCE_MATCHING_SIGNATURE ,
				:VVPrev_Exec_Id,
		        :v_IO_CELL_OFFLOAD_ELIGIBLE_BYTES,
		        :v_PX_IS_CROSS_INSTANCE,
		        :v_px_servers_requested,
		        :v_px_servers_allocated,
		        :v_ELAPSED_TIME,
		        :v_QUEUING_TIME,
		        :v_CPU_TIME,
		        :v_FETCHES,
		        :v_BUFFER_GETS,
		        :v_DISK_READS,
		        :v_DIRECT_WRITES,
		        :v_IO_INTERCONNECT_BYTES,
		        :v_PHYSICAL_READ_REQUESTS,
		        :v_PHYSICAL_READ_BYTES,
		        :v_PHYSICAL_WRITE_REQUESTS,
		        :v_PHYSICAL_WRITE_BYTES,
		        :v_APPLICATION_WAIT_TIME,
		        :v_CONCURRENCY_WAIT_TIME,
		        :v_CLUSTER_WAIT_TIME,
		        :v_USER_IO_WAIT_TIME,
		        :v_PLSQL_EXEC_TIME,
		        :v_JAVA_EXEC_TIME,
		        :v_im_scans,
		        :v_im_scan_bytes_uncompressed,
		        :v_im_scan_bytes_inmemory,
		        :sql_plan_hash_value
		        from v$sql sq
		        left join (
				select sys_context('userenv','sid') sid,sm.sql_exec_id,
				sum     (elapsed_time) elapsed_time,
				max     (sm.PX_IS_CROSS_INSTANCE) PX_IS_CROSS_INSTANCE,
				max     (SM.px_servers_requested) px_servers_requested,
				max     (SM.px_servers_allocated) px_servers_allocated,
				sum     (cpu_time) cpu_time,
				sum     (QUEUING_TIME) QUEUING_TIME,
				sum     (FETCHES) FETCHES,
				sum     (BUFFER_GETS) BUFFER_GETS,
				sum     (DISK_READS) DISK_READS,
				sum     (DIRECT_WRITES) DIRECT_WRITES,
				sum     (IO_INTERCONNECT_BYTES) IO_INTERCONNECT_BYTES,
				sum     (PHYSICAL_READ_REQUESTS) PHYSICAL_READ_REQUESTS,
				sum     (PHYSICAL_READ_BYTES) PHYSICAL_READ_BYTES,
				sum     (PHYSICAL_WRITE_REQUESTS) PHYSICAL_WRITE_REQUESTS,
				sum     (PHYSICAL_WRITE_BYTES) PHYSICAL_WRITE_BYTES,
				sum     (APPLICATION_WAIT_TIME) APPLICATION_WAIT_TIME,
				sum     (CONCURRENCY_WAIT_TIME) CONCURRENCY_WAIT_TIME,
				sum     (CLUSTER_WAIT_TIME) CLUSTER_WAIT_TIME,
				sum     (USER_IO_WAIT_TIME) USER_IO_WAIT_TIME,
				sum     (PLSQL_EXEC_TIME) PLSQL_EXEC_TIME,
				sum     (JAVA_EXEC_TIME) JAVA_EXEC_TIME,
				max(sm.sql_plan_hash_value) sql_plan_hash_value
				from gv$sql_monitor sm
				where :VVchar_prev_sql_id = sm.sql_id
				and sm.sql_exec_id=:VVPrev_Exec_Id
				and sql_exec_start>=case when :sql_exec_start is null then sysdate else to_date(:sql_exec_start,'dd/mm/yyyy hh24:mi:ss') end
				group by sm.sql_exec_id) sm
			on( sm.sid = sys_context('USERENV', 'SID')) 
			where :VVchar_prev_sql_id = sq.sql_id 
			and :VVChild_n = sq.child_number; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 39;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlbuft((void **)0, 
    "select sys_context ( 'USERENV' , 'INSTANCE' ) , nvl ( SQL_PROFILE , 'No\
ne' ) , nvl ( SQL_PATCH , 'None' ) , nvl ( SQL_PLAN_BASELINE , 'Non' ) , EXA\
CT_MATCHING_SIGNATURE , FORCE_MATCHING_SIGNATURE , nvl ( sm . sql_exec_id , \
0 ) , nvl ( sq . IO_CELL_OFFLOAD_ELIGIBLE_BYTES , 0 ) / 1024 , nvl ( sm . PX\
_IS_CROSS_INSTANCE , 'N' ) , nvl ( SM . px_servers_requested , 0 ) , nvl ( S\
M . px_servers_allocated , 0 ) , nvl ( nvl ( SM . ELAPSED_TIME , sq . elapse\
d_time / decode ( sq . executions , 0 , 1 , sq . executions ) ) , 0 ) , nvl \
( SM . QUEUING_TIME , 0 ) , nvl ( nvl ( SM . CPU_TIME , sq . cpu_time / deco\
de ( sq . executions , 0 , 1 , sq . executions ) ) , 0 ) , nvl ( nvl ( SM . \
FETCHES , sq . fetches / decode ( sq . executions , 0 , 1 , sq . executions \
) ) , 0 ) , nvl ( nvl ( SM . BUFFER_GETS , sq . BUFFER_GETS / decode ( sq . \
executions , 0 , 1 , sq . executions ) ) , 0 ) , nvl ( nvl ( SM . DISK_READS\
 , sq . DISK_READS / decode ( sq . executions , 0 , 1 , sq . executions ) ) \
, 0 ) , nvl ( nvl ( SM . DIRECT_WRITES , ");
  sqlbuft((void **)0, 
    "sq . DIRECT_WRITES / decode ( sq . executions , 0 , 1 , sq . executions\
 ) ) , 0 ) , nvl ( nvl ( SM . IO_INTERCONNECT_BYTES , sq . IO_INTERCONNECT_B\
YTES / decode ( sq . executions , 0 , 1 , sq . executions ) ) , 0 ) , nvl ( \
nvl ( SM . PHYSICAL_READ_REQUESTS , sq . PHYSICAL_READ_REQUESTS / decode ( s\
q . executions , 0 , 1 , sq . executions ) ) , 0 ) , nvl ( nvl ( SM . PHYSIC\
AL_READ_BYTES , sq . PHYSICAL_READ_BYTES / decode ( sq . executions , 0 , 1 \
, sq . executions ) ) , 0 ) , nvl ( nvl ( SM . PHYSICAL_WRITE_REQUESTS , sq \
. PHYSICAL_WRITE_REQUESTS / decode ( sq . executions , 0 , 1 , sq . executio\
ns ) ) , 0 ) , nvl ( nvl ( SM . PHYSICAL_WRITE_BYTES , sq . PHYSICAL_WRITE_B\
YTES / decode ( sq . executions , 0 , 1 , sq . executions ) ) , 0 ) , nvl ( \
nvl ( SM . APPLICATION_WAIT_TIME , sq . APPLICATION_WAIT_TIME / decode ( sq \
. executions , 0 , 1 , sq . executions ) ) , 0 ) , nvl ( nvl ( SM . CONCURRE\
NCY_WAIT_TIME , sq . CONCURRENCY_WAIT_TIME / decode ( sq . executions , 0 , \
1 , sq . executions ) ) , 0 ) , nvl ( nvl");
  sqlbuft((void **)0, 
    " ( SM . CLUSTER_WAIT_TIME , sq . CLUSTER_WAIT_TIME / decode ( sq . exec\
utions , 0 , 1 , sq . executions ) ) , 0 ) , nvl ( nvl ( SM . USER_IO_WAIT_T\
IME , sq . USER_IO_WAIT_TIME / decode ( sq . executions , 0 , 1 , sq . execu\
tions ) ) , 0 ) , nvl ( nvl ( SM . PLSQL_EXEC_TIME , sq . PLSQL_EXEC_TIME / \
decode ( sq . executions , 0 , 1 , sq . executions ) ) , 0 ) , nvl ( nvl ( S\
M . JAVA_EXEC_TIME , sq . JAVA_EXEC_TIME / decode ( sq . executions , 0 , 1 \
, sq . executions ) ) , 0 ) , 0 , 0 , 0 , nvl ( sm . sql_plan_hash_value , p\
lan_hash_value ) plan_hash_value into :b0 , :b1 , :b2 , :b3 , :b4 , :b5 , :b\
6 , :b7 , :b8 , :b9 , :b10 , :b11 , :b12 , :b13 , :b14 , :b15 , :b16 , :b17 \
, :b18 , :b19 , :b20 , :b21 , :b22 , :b23 , :b24 , :b25 , :b26 , :b27 , :b28\
 , :b29 , :b30 , :b31 , :b32 from v$sql sq left join ( select sys_context ( \
'userenv' , 'sid' ) sid , sm . sql_exec_id , sum ( elapsed_time ) elapsed_ti\
me , max ( sm . PX_IS_CROSS_INSTANCE ) PX_IS_CROSS_INSTANCE , max ( SM . px_\
servers_requested ) px_servers_requested ");
  sqlbuft((void **)0, 
    ", max ( SM . px_servers_allocated ) px_servers_allocated , sum ( cpu_ti\
me ) cpu_time , sum ( QUEUING_TIME ) QUEUING_TIME , sum ( FETCHES ) FETCHES \
, sum ( BUFFER_GETS ) BUFFER_GETS , sum ( DISK_READS ) DISK_READS , sum ( DI\
RECT_WRITES ) DIRECT_WRITES , sum ( IO_INTERCONNECT_BYTES ) IO_INTERCONNECT_\
BYTES , sum ( PHYSICAL_READ_REQUESTS ) PHYSICAL_READ_REQUESTS , sum ( PHYSIC\
AL_READ_BYTES ) PHYSICAL_READ_BYTES , sum ( PHYSICAL_WRITE_REQUESTS ) PHYSIC\
AL_WRITE_REQUESTS , sum ( PHYSICAL_WRITE_BYTES ) PHYSICAL_WRITE_BYTES , sum \
( APPLICATION_WAIT_TIME ) APPLICATION_WAIT_TIME , sum ( CONCURRENCY_WAIT_TIM\
E ) CONCURRENCY_WAIT_TIME , sum ( CLUSTER_WAIT_TIME ) CLUSTER_WAIT_TIME , su\
m ( USER_IO_WAIT_TIME ) USER_IO_WAIT_TIME , sum ( PLSQL_EXEC_TIME ) PLSQL_EX\
EC_TIME , sum ( JAVA_EXEC_TIME ) JAVA_EXEC_TIME , max ( sm . sql_plan_hash_v\
alue ) sql_plan_hash_value from gv$sql_monitor sm where :b33 = sm . sql_id a\
nd sm . sql_exec_id = :b6 and sql_exec_start >= case when :b35 is null then \
sysdate else to_date ( :b35 , 'dd/mm/yyyy");
  sqlstm.stmt = " hh24:mi:ss' ) end group by sm . sql_exec_id ) sm on ( sm .\
 sid = sys_context ( 'USERENV' , 'SID' ) ) where :b33 = sq . sql_id and :b38 =\
 sq . child_number ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2285;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_instance;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)v_SQL_PROFILE;
  sqlstm.sqhstl[1] = (unsigned long )65;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)v_SQL_PATCH;
  sqlstm.sqhstl[2] = (unsigned long )129;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)v_SQL_PLAN_BASELINE;
  sqlstm.sqhstl[3] = (unsigned long )129;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)v_EXACT_MATCHING_SIGNATURE;
  sqlstm.sqhstl[4] = (unsigned long )41;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)v_FORCE_MATCHING_SIGNATURE;
  sqlstm.sqhstl[5] = (unsigned long )41;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&VVPrev_Exec_Id;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_IO_CELL_OFFLOAD_ELIGIBLE_BYTES;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)v_PX_IS_CROSS_INSTANCE;
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_px_servers_requested;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_px_servers_allocated;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_ELAPSED_TIME;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_QUEUING_TIME;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_CPU_TIME;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_FETCHES;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_BUFFER_GETS;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_DISK_READS;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_DIRECT_WRITES;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_IO_INTERCONNECT_BYTES;
  sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_PHYSICAL_READ_REQUESTS;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_PHYSICAL_READ_BYTES;
  sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_PHYSICAL_WRITE_REQUESTS;
  sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_PHYSICAL_WRITE_BYTES;
  sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_APPLICATION_WAIT_TIME;
  sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&v_CONCURRENCY_WAIT_TIME;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_CLUSTER_WAIT_TIME;
  sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&v_USER_IO_WAIT_TIME;
  sqlstm.sqhstl[26] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)&v_PLSQL_EXEC_TIME;
  sqlstm.sqhstl[27] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&v_JAVA_EXEC_TIME;
  sqlstm.sqhstl[28] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&v_im_scans;
  sqlstm.sqhstl[29] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)&v_im_scan_bytes_uncompressed;
  sqlstm.sqhstl[30] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[30] = (         int  )0;
  sqlstm.sqindv[30] = (         short *)0;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)&v_im_scan_bytes_inmemory;
  sqlstm.sqhstl[31] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[31] = (         int  )0;
  sqlstm.sqindv[31] = (         short *)0;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)&sql_plan_hash_value;
  sqlstm.sqhstl[32] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[32] = (         int  )0;
  sqlstm.sqindv[32] = (         short *)0;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)VVchar_prev_sql_id;
  sqlstm.sqhstl[33] = (unsigned long )30;
  sqlstm.sqhsts[33] = (         int  )0;
  sqlstm.sqindv[33] = (         short *)0;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)&VVPrev_Exec_Id;
  sqlstm.sqhstl[34] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[34] = (         int  )0;
  sqlstm.sqindv[34] = (         short *)0;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)sql_exec_start;
  sqlstm.sqhstl[35] = (unsigned long )20;
  sqlstm.sqhsts[35] = (         int  )0;
  sqlstm.sqindv[35] = (         short *)0;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)sql_exec_start;
  sqlstm.sqhstl[36] = (unsigned long )20;
  sqlstm.sqhsts[36] = (         int  )0;
  sqlstm.sqindv[36] = (         short *)0;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)VVchar_prev_sql_id;
  sqlstm.sqhstl[37] = (unsigned long )30;
  sqlstm.sqhsts[37] = (         int  )0;
  sqlstm.sqindv[37] = (         short *)0;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
  sqlstm.sqhstv[38] = (unsigned char  *)&VVChild_n;
  sqlstm.sqhstl[38] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[38] = (         int  )0;
  sqlstm.sqindv[38] = (         short *)0;
  sqlstm.sqinds[38] = (         int  )0;
  sqlstm.sqharm[38] = (unsigned long )0;
  sqlstm.sqadto[38] = (unsigned short )0;
  sqlstm.sqtdso[38] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

			
		if (debug&debug_level&&sqlca.sqlcode!=0)
			my_print("Could not fetch data from v$sql for this query: prev_id=%s, prev_child=%d, prev_exec_id=%d and sqlcode=%d, query=%s loc_time=%s\n", VVchar_prev_sql_id, VVChild_n, VVPrev_Exec_Id, sqlca.sqlcode, query_name, loc_time);
			/* code to get the query_name from a qb_block hint in the sql
			we do this only if query_name from parfile='qb_name' */
		/* EXEC SQL at :db_name insert into response_times(
			trial_nbr,
			process_id,
			inst_id,
			query_name,
			executions,
			rows_p,
			elapsed_t,
			elapsed_first_fetch,
			time_st,
			sql_id,
			child_nbr,
			exec_id,
			IO_CELL_OFFLOAD_ELIGIBLE_BYTES,
			PX_IS_CROSS_INSTANCE,
			px_servers_requested,
			px_servers_allocated,
			ELAPSED_TIME,
			QUEUING_TIME,
			CPU_TIME,
			FETCHES,
			BUFFER_GETS,
			DISK_READS,
			DIRECT_WRITES,
			IO_INTERCONNECT_BYTES,
			PHYSICAL_READ_REQUESTS,
			PHYSICAL_READ_BYTES,
			PHYSICAL_WRITE_REQUESTS,
			PHYSICAL_WRITE_BYTES,
			APPLICATION_WAIT_TIME,
			CONCURRENCY_WAIT_TIME,
			CLUSTER_WAIT_TIME,
			USER_IO_WAIT_TIME,
			PLSQL_EXEC_TIME,
			JAVA_EXEC_TIME,
			im_scans,
			im_scan_bytes_uncompressed,
			im_scan_bytes_inmemory,
			sql_plan_hash_value,
			SQL_PROFILE,
			SQL_PATCH,
			SQL_PLAN_BASELINE,
			EXACT_MATCHING_SIGNATURE,
			FORCE_MATCHING_SIGNATURE
			) VALUES (
				:trial_nbr,
				:pid,
	        	:v_instance,
				:query_name,
				:executions,
				:rows_p,
				:real_time,
				:first_fetch,
				to_timestamp(:loc_time,'dd/mm/yyyy hh24:mi:ss.ff'),
				:VVchar_prev_sql_id,
				:VVChild_n,
				:VVPrev_Exec_Id,
				:v_IO_CELL_OFFLOAD_ELIGIBLE_BYTES,
		        :v_PX_IS_CROSS_INSTANCE,
		        :v_px_servers_requested,
		        :v_px_servers_allocated,
		        :v_ELAPSED_TIME,
		        :v_QUEUING_TIME,
		        :v_CPU_TIME,
		        :v_FETCHES,
		        :v_BUFFER_GETS,
		        :v_DISK_READS,
		        :v_DIRECT_WRITES,
		        :v_IO_INTERCONNECT_BYTES,
		        :v_PHYSICAL_READ_REQUESTS,
		        :v_PHYSICAL_READ_BYTES,
		        :v_PHYSICAL_WRITE_REQUESTS,
		        :v_PHYSICAL_WRITE_BYTES,
		        :v_APPLICATION_WAIT_TIME,
		        :v_CONCURRENCY_WAIT_TIME,
		        :v_CLUSTER_WAIT_TIME,
		        :v_USER_IO_WAIT_TIME,
		        :v_PLSQL_EXEC_TIME,
		        :v_JAVA_EXEC_TIME,
		        :v_im_scans,
		        :v_im_scan_bytes_uncompressed,
		        :v_im_scan_bytes_inmemory,
		        :sql_plan_hash_value,
 				:v_SQL_PROFILE              ,
 				:v_SQL_PATCH                ,
 				:v_SQL_PLAN_BASELINE        ,
 				:v_EXACT_MATCHING_SIGNATURE ,
 				:v_FORCE_MATCHING_SIGNATURE 
				); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlbuft((void **)0, 
    "insert into response_times ( trial_nbr , process_id , inst_id , query_n\
ame , executions , rows_p , elapsed_t , elapsed_first_fetch , time_st , sql_\
id , child_nbr , exec_id , IO_CELL_OFFLOAD_ELIGIBLE_BYTES , PX_IS_CROSS_INST\
ANCE , px_servers_requested , px_servers_allocated , ELAPSED_TIME , QUEUING_\
TIME , CPU_TIME , FETCHES , BUFFER_GETS , DISK_READS , DIRECT_WRITES , IO_IN\
TERCONNECT_BYTES , PHYSICAL_READ_REQUESTS , PHYSICAL_READ_BYTES , PHYSICAL_W\
RITE_REQUESTS , PHYSICAL_WRITE_BYTES , APPLICATION_WAIT_TIME , CONCURRENCY_W\
AIT_TIME , CLUSTER_WAIT_TIME , USER_IO_WAIT_TIME , PLSQL_EXEC_TIME , JAVA_EX\
EC_TIME , im_scans , im_scan_bytes_uncompressed , im_scan_bytes_inmemory , s\
ql_plan_hash_value , SQL_PROFILE , SQL_PATCH , SQL_PLAN_BASELINE , EXACT_MAT\
CHING_SIGNATURE , FORCE_MATCHING_SIGNATURE ) VALUES ( :b1 , :b2 , :b3 , :b4 \
, :b5 , :b6 , :b7 , :b8 , to_timestamp ( :b9 , 'dd/mm/yyyy hh24:mi:ss.ff' ) \
, :b10 , :b11 , :b12 , :b13 , :b14 , :b15 , :b16 , :b17 , :b18 , :b19 , :b20\
 , :b21 , :b22 , :b23 , :b24 , :b25 , :b2");
  sqlstm.stmt = "6 , :b27 , :b28 , :b29 , :b30 , :b31 , :b32 , :b33 , :b34 ,\
 :b35 , :b36 , :b37 , :b38 , :b39 , :b40 , :b41 , :b42 , :b43 ) ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2463;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&trial_nbr;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&pid;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_instance;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)query_name;
  sqlstm.sqhstl[3] = (unsigned long )0;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&executions;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&rows_p;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&real_time;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&first_fetch;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)loc_time;
  sqlstm.sqhstl[8] = (unsigned long )0;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)VVchar_prev_sql_id;
  sqlstm.sqhstl[9] = (unsigned long )30;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&VVChild_n;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&VVPrev_Exec_Id;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_IO_CELL_OFFLOAD_ELIGIBLE_BYTES;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)v_PX_IS_CROSS_INSTANCE;
  sqlstm.sqhstl[13] = (unsigned long )2;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_px_servers_requested;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_px_servers_allocated;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_ELAPSED_TIME;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_QUEUING_TIME;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_CPU_TIME;
  sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_FETCHES;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_BUFFER_GETS;
  sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_DISK_READS;
  sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_DIRECT_WRITES;
  sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_IO_INTERCONNECT_BYTES;
  sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&v_PHYSICAL_READ_REQUESTS;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_PHYSICAL_READ_BYTES;
  sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&v_PHYSICAL_WRITE_REQUESTS;
  sqlstm.sqhstl[26] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)&v_PHYSICAL_WRITE_BYTES;
  sqlstm.sqhstl[27] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&v_APPLICATION_WAIT_TIME;
  sqlstm.sqhstl[28] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&v_CONCURRENCY_WAIT_TIME;
  sqlstm.sqhstl[29] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)&v_CLUSTER_WAIT_TIME;
  sqlstm.sqhstl[30] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[30] = (         int  )0;
  sqlstm.sqindv[30] = (         short *)0;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)&v_USER_IO_WAIT_TIME;
  sqlstm.sqhstl[31] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[31] = (         int  )0;
  sqlstm.sqindv[31] = (         short *)0;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)&v_PLSQL_EXEC_TIME;
  sqlstm.sqhstl[32] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[32] = (         int  )0;
  sqlstm.sqindv[32] = (         short *)0;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)&v_JAVA_EXEC_TIME;
  sqlstm.sqhstl[33] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[33] = (         int  )0;
  sqlstm.sqindv[33] = (         short *)0;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)&v_im_scans;
  sqlstm.sqhstl[34] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[34] = (         int  )0;
  sqlstm.sqindv[34] = (         short *)0;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)&v_im_scan_bytes_uncompressed;
  sqlstm.sqhstl[35] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[35] = (         int  )0;
  sqlstm.sqindv[35] = (         short *)0;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)&v_im_scan_bytes_inmemory;
  sqlstm.sqhstl[36] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[36] = (         int  )0;
  sqlstm.sqindv[36] = (         short *)0;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)&sql_plan_hash_value;
  sqlstm.sqhstl[37] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[37] = (         int  )0;
  sqlstm.sqindv[37] = (         short *)0;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
  sqlstm.sqhstv[38] = (unsigned char  *)v_SQL_PROFILE;
  sqlstm.sqhstl[38] = (unsigned long )65;
  sqlstm.sqhsts[38] = (         int  )0;
  sqlstm.sqindv[38] = (         short *)0;
  sqlstm.sqinds[38] = (         int  )0;
  sqlstm.sqharm[38] = (unsigned long )0;
  sqlstm.sqadto[38] = (unsigned short )0;
  sqlstm.sqtdso[38] = (unsigned short )0;
  sqlstm.sqhstv[39] = (unsigned char  *)v_SQL_PATCH;
  sqlstm.sqhstl[39] = (unsigned long )129;
  sqlstm.sqhsts[39] = (         int  )0;
  sqlstm.sqindv[39] = (         short *)0;
  sqlstm.sqinds[39] = (         int  )0;
  sqlstm.sqharm[39] = (unsigned long )0;
  sqlstm.sqadto[39] = (unsigned short )0;
  sqlstm.sqtdso[39] = (unsigned short )0;
  sqlstm.sqhstv[40] = (unsigned char  *)v_SQL_PLAN_BASELINE;
  sqlstm.sqhstl[40] = (unsigned long )129;
  sqlstm.sqhsts[40] = (         int  )0;
  sqlstm.sqindv[40] = (         short *)0;
  sqlstm.sqinds[40] = (         int  )0;
  sqlstm.sqharm[40] = (unsigned long )0;
  sqlstm.sqadto[40] = (unsigned short )0;
  sqlstm.sqtdso[40] = (unsigned short )0;
  sqlstm.sqhstv[41] = (unsigned char  *)v_EXACT_MATCHING_SIGNATURE;
  sqlstm.sqhstl[41] = (unsigned long )41;
  sqlstm.sqhsts[41] = (         int  )0;
  sqlstm.sqindv[41] = (         short *)0;
  sqlstm.sqinds[41] = (         int  )0;
  sqlstm.sqharm[41] = (unsigned long )0;
  sqlstm.sqadto[41] = (unsigned short )0;
  sqlstm.sqtdso[41] = (unsigned short )0;
  sqlstm.sqhstv[42] = (unsigned char  *)v_FORCE_MATCHING_SIGNATURE;
  sqlstm.sqhstl[42] = (unsigned long )41;
  sqlstm.sqhsts[42] = (         int  )0;
  sqlstm.sqindv[42] = (         short *)0;
  sqlstm.sqinds[42] = (         int  )0;
  sqlstm.sqharm[42] = (unsigned long )0;
  sqlstm.sqadto[42] = (unsigned short )0;
  sqlstm.sqtdso[42] = (unsigned short )0;
  sqlstm.sqhstv[43] = (unsigned char  *)db_name;
  sqlstm.sqhstl[43] = (unsigned long )20;
  sqlstm.sqhsts[43] = (         int  )0;
  sqlstm.sqindv[43] = (         short *)0;
  sqlstm.sqinds[43] = (         int  )0;
  sqlstm.sqharm[43] = (unsigned long )0;
  sqlstm.sqadto[43] = (unsigned short )0;
  sqlstm.sqtdso[43] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		v_rows_inserted_into_rt++;
		if (sqlca.sqlcode==-1722) {
			/* error in initializing some data, let's print it all*/
			my_print("get sqlca.sqlcode=%d, so printing the data to see what's wrong", sqlca.sqlcode);
			my_print("executions=%d",executions);
			my_print("rows_p=%ld",rows_p);
			my_print("VVPrev_Exec_Id=%d",VVPrev_Exec_Id);
			my_print("child_nbr=%d",VVChild_n);
			my_print("real_time=%ld",real_time);
			my_print("first_fetch=%ld",first_fetch);
			my_print("v_IO_CELL_OFFLOAD_ELIGIBLE_BYTES=%lf",			v_IO_CELL_OFFLOAD_ELIGIBLE_BYTES);
			my_print("v_px_servers_requested=%lf",		        v_px_servers_requested);
			my_print("v_px_servers_allocated=%lf",		        v_px_servers_allocated);
			my_print("v_ELAPSED_TIME=%lf",		        v_ELAPSED_TIME);
			my_print("v_QUEUING_TIME=%lf",		        v_QUEUING_TIME);
			my_print("v_CPU_TIME=%lf",		        v_CPU_TIME);
			my_print("v_FETCHES=%lf",		        v_FETCHES);
			my_print("v_BUFFER_GETS=%lf",		        v_BUFFER_GETS);
			my_print("v_DISK_READS=%lf",		        v_DISK_READS);
			my_print("v_DIRECT_WRITES=%lf",		        v_DIRECT_WRITES);
			my_print("v_IO_INTERCONNECT_BYTES=%lf",		        v_IO_INTERCONNECT_BYTES);
			my_print("v_PHYSICAL_READ_REQUESTS=%lf",		        v_PHYSICAL_READ_REQUESTS);
			my_print("v_PHYSICAL_READ_BYTES=%lf",		        v_PHYSICAL_READ_BYTES);
			my_print("v_PHYSICAL_WRITE_REQUESTS=%lf",		        v_PHYSICAL_WRITE_REQUESTS);
			my_print("v_PHYSICAL_WRITE_BYTES=%lf",		        v_PHYSICAL_WRITE_BYTES);
			my_print("v_APPLICATION_WAIT_TIME=%lf",		        v_APPLICATION_WAIT_TIME);
			my_print("v_CONCURRENCY_WAIT_TIME=%lf",		        v_CONCURRENCY_WAIT_TIME);
			my_print("v_CLUSTER_WAIT_TIME=%lf",		        v_CLUSTER_WAIT_TIME);
			my_print("v_USER_IO_WAIT_TIME=%lf",		        v_USER_IO_WAIT_TIME);
			my_print("v_PLSQL_EXEC_TIME=%lf",		        v_PLSQL_EXEC_TIME);
			my_print("v_JAVA_EXEC_TIME=%lf",		        v_JAVA_EXEC_TIME);
			my_print("v_im_scans=%lf",		        v_im_scans);
			my_print("v_im_scan_bytes_uncompressed=%lf",		        v_im_scan_bytes_uncompressed);
		    my_print("v_im_scan_bytes_inmemory=%ld",v_im_scan_bytes_inmemory);
		}
		if (debug&debug_level||sqlca.sqlcode!=0)
			my_print("v_rows_inserted_into_rt=%d, flush_results_every=%d sqlcode=%d\n",v_rows_inserted_into_rt, flush_results_every,sqlca.sqlcode);
		if (sqlca.sqlcode!=0){
				/* EXEC SQL at :db_name insert into response_times(
				trial_nbr,
				process_id,
				inst_id,
				query_name,
				executions,
				rows_p,
				elapsed_t,
				elapsed_first_fetch,
				time_st,
				sql_id
				) VALUES (
				:trial_nbr,
				:pid,
				:v_instance,
				:query_name,
				:executions,
				:rows_p,
				:real_time,
				:first_fetch,
				to_timestamp(:loc_time,'dd/mm/yyyy hh24:mi:ss.ff'),
				:VVchar_prev_sql_id); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 44;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into response_times ( trial_nbr , process_id , ins\
t_id , query_name , executions , rows_p , elapsed_t , elapsed_first_fetch , ti\
me_st , sql_id ) VALUES ( :b1 , :b2 , :b3 , :b4 , :b5 , :b6 , :b7 , :b8 , to_t\
imestamp ( :b9 , 'dd/mm/yyyy hh24:mi:ss.ff' ) , :b10 ) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2654;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&trial_nbr;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&pid;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&v_instance;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)query_name;
    sqlstm.sqhstl[3] = (unsigned long )0;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&executions;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&rows_p;
    sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&real_time;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&first_fetch;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)loc_time;
    sqlstm.sqhstl[8] = (unsigned long )0;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)VVchar_prev_sql_id;
    sqlstm.sqhstl[9] = (unsigned long )30;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)db_name;
    sqlstm.sqhstl[10] = (unsigned long )20;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			if (debug&debug_level||sqlca.sqlcode!=0)
				my_print("after first error, trying again=%d, flush_results_every=%d sqlcode=%d\n",v_rows_inserted_into_rt, flush_results_every,sqlca.sqlcode);
		}
		if (v_rows_inserted_into_rt>=flush_results_every){
			/* exec sql at :db_name commit work; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2713;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)db_name;
   sqlstm.sqhstl[0] = (unsigned long )20;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			v_rows_inserted_into_rt=0;
		}
	}
	if (debug&debug_level)
		my_print("got prev_id=%s, prev_child=%d, prev_exec_id=%d and sqlcode=%d, query=%s loc_time=%s\n", VVchar_prev_sql_id, VVChild_n, VVPrev_Exec_Id, sqlca.sqlcode, query_name, loc_time);
	strcpy(Vchar_prev_sql_id, VVchar_prev_sql_id);
	*Vchild_n = VVChild_n;
	*VPrev_Exec_Id = VVPrev_Exec_Id;
	strcpy(function_name,saved_function_name);
}

void save_my_stats(
	int before_after)
{
	double  adStat_valueB[MAX_STATS],adStat_value_f[MAX_STATS];
	int     debug_level=1<<12,i=MAX_STATS, rows_this_turn, c_rows, aiStats_nbr[MAX_STATS],aiStats_nbr_f[MAX_STATS], aiTrial_nbr[MAX_STATS],aiPid[MAX_STATS],aiSID[MAX_STATS] ;
	char query_names[MAX_STATS][200], saved_function_name[50];
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"save_my_stats");
	if (before_after==BEFORE) {
		for (c_rows=0;c_rows<i;c_rows++) {
			adStat_value[c_rows]=0.;
		}
		/* exec sql at main_db
		select statistic#, value
		into :aiStats_nbr,:adStat_valueB
		from v$mystat m
		where value > 0
		and rownum<:i
		order by 1; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select statistic# , value into :b0 , :b1 from v$mystat m wh\
ere value > 0 and rownum < :b2 order by 1 ";
  sqlstm.iters = (unsigned int  )1000;
  sqlstm.offset = (unsigned int  )2732;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)aiStats_nbr;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)adStat_valueB;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )sizeof(double);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&i;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if (debug&debug_level) my_print("got %d lines from mystat\n",sqlca.sqlerrd[2]);
		for (i=0; i<sqlca.sqlerrd[2];i++) {
			adStat_value[aiStats_nbr[i]]=adStat_valueB[i];
			if (debug&debug_level) my_print("before stat_nbr=%d value=%lf\n",aiStats_nbr[i],adStat_valueB[i]);
		}
	} else {
		for (c_rows=0;c_rows<MAX_STATS;c_rows++) {
			aiPid[c_rows]=mypid;
			aiTrial_nbr[c_rows]=trial_nbr;
			strcpy(query_names[c_rows],query_name);
		}
		/* exec sql at main_db
		select statistic#, value,SID
		into :aiStats_nbr,:adStat_valueB, :aiSID
		from v$mystat m
		where value > 0
		and rownum<:i
		order by 1; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select statistic# , value , SID into :b0 , :b1 , :b2 from v\
$mystat m where value > 0 and rownum < :b3 order by 1 ";
  sqlstm.iters = (unsigned int  )1000;
  sqlstm.offset = (unsigned int  )2766;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)aiStats_nbr;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)adStat_valueB;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )sizeof(double);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)aiSID;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&i;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		for (i=0; i<sqlca.sqlerrd[2];i++){ 
			adStat_value[aiStats_nbr[i]]=adStat_valueB[i]-adStat_value[aiStats_nbr[i]];
			if (debug&debug_level) my_print("after stat_nbr=%d value=%lf\n",aiStats_nbr[i],adStat_valueB[i]);
		}
		for (c_rows=0,rows_this_turn=0;c_rows<MAX_STATS;c_rows++) {
			aiStats_nbr[c_rows]=c_rows;
			aiSID[c_rows]=aiSID[0];
			if (adStat_value[c_rows]!=0.) { /* there's a value, copy it to final array*/
				adStat_value_f[rows_this_turn]=adStat_value[c_rows];
				aiStats_nbr_f[rows_this_turn]=c_rows;
				rows_this_turn++;
			}
		}
//		c_rows=aiSID[0];
		for (i=0; debug&debug_level&&i<MAX_STATS;i++) {
			if (adStat_value[i]!=0.) my_print("stat_nbr=%d value=%lf\n",aiStats_nbr[i],adStat_value[i]);
		}
		/* exec sql at :db_name for :rows_this_turn insert into my_stats (trial_nbr, pid, sid, statistic#,value,query_name) 
			values (:aiTrial_nbr,:aiPid, :aiSID, :aiStats_nbr_f, :adStat_value_f,:query_names); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into my_stats ( trial_nbr , pid , sid , statistic# ,\
 value , query_name ) values ( :b2 , :b3 , :b4 , :b5 , :b6 , :b7 ) ";
  sqlstm.iters = (unsigned int  )rows_this_turn;
  sqlstm.offset = (unsigned int  )2804;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)aiTrial_nbr;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)aiPid;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)aiSID;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)aiStats_nbr_f;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)adStat_value_f;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )sizeof(double);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)query_names;
  sqlstm.sqhstl[5] = (unsigned long )200;
  sqlstm.sqhsts[5] = (         int  )200;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)db_name;
  sqlstm.sqhstl[6] = (unsigned long )20;
  sqlstm.sqhsts[6] = (         int  )20;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if (sqlca.sqlcode!=0) my_print("Error inserting data into my_stats=%d, had %d rows to insert\n",sqlca.sqlcode, rows_this_turn);
		/* exec sql at :db_name commit work; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2847;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)db_name;
  sqlstm.sqhstl[0] = (unsigned long )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	}
	strcpy(function_name,saved_function_name);
}

void print_mystat(
	FILE * logfile)
{
	char    aVCStat_name[100];
	double  adStat_value;
	int     i, rows_this_turn, c_rows;
	/* exec sql at main_db declare c0_stat cursor for
		select name, value
		from v$mystat m,
		v$statname n
		where n.statistic#=m.statistic#
	        and value > 0; */ 

	/* exec sql open c0_stat; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 44;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0028;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2866;
 sqlstm.selerr = (unsigned short)100;
 sqlstm.sqlpfmem = (unsigned int  )0;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	c_rows= 0;
	rows_this_turn = 100;
	fprintf(logfile, "Printing non-zero values from v$mystat\n");
	fprintf(logfile,
		"Statistic name								Value\n");
	fprintf(logfile,
		"---------------------------------------------------------------------- ---------------\n");
	for (; sqlca.sqlcode==0;) {
		/* exec sql fetch c0_stat into:aVCStat_name, adStat_value; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2888;
  sqlstm.selerr = (unsigned short)100;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)aVCStat_name;
  sqlstm.sqhstl[0] = (unsigned long )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&adStat_value;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		rows_this_turn = sqlca.sqlerrd[2] - c_rows;
		c_rows = sqlca.sqlerrd[2];
		if (sqlca.sqlcode==0)	fprintf(logfile, "%-70s   %13.2lf\n",
				aVCStat_name, adStat_value);
	}

}

void print_pgastat(
	FILE * logfile)
{
	char    tstamp[30];
	long int used, alloc, freeable, pag_max;
	/* exec sql at main_db select PGA_USED_MEM, PGA_ALLOC_MEM, PGA_FREEABLE_MEM,
		PGA_MAX_MEM, to_char( systimestamp, 'dd/mm/yyyy hh24:mi:ss.ff6') into:used,
		:alloc,
		:freeable,
		:pag_max,
		:tstamp
		from v$session s,
		v$process
		where paddr = addr
		and s.sid =sys_context('USERENV', 'SID'); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 44;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select PGA_USED_MEM , PGA_ALLOC_MEM , PGA_FREEABLE_MEM , PGA\
_MAX_MEM , to_char ( systimestamp , 'dd/mm/yyyy hh24:mi:ss.ff6' ) into :b0 , :\
b1 , :b2 , :b3 , :b4 from v$session s , v$process where paddr = addr and s . s\
id = sys_context ( 'USERENV' , 'SID' ) ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2918;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.sqlpfmem = (unsigned int  )0;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&used;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&alloc;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&freeable;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&pag_max;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)tstamp;
 sqlstm.sqhstl[4] = (unsigned long )30;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	fprintf(logfile,
		"PGA STATS: Time stamp	       Used	Allocated  Freeable	Max\n");
	fprintf(logfile,
		"------------------------------ ---------- ---------- ---------- ----------\n");
	fprintf(logfile, "%-30s %10ld %10ld %10ld %10ld\n", tstamp, used,
		alloc, freeable, pag_max);
}

void sql_error(
	)
{
	/* ORACLE error handler */
	my_print("Error in function %s while executing statement %s : %.70s\n", function_name, query_name,
	       sqlca.sqlerrm.sqlerrmc);
	printf("The statement is: %s\n",dyn_statement);

	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

}

void strip_right_space(
	char *string_par)
{
	char   *pch, pch1,saved_function_name[50];
	int     len,debug_level=1<<10;
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"strip_right_space");
	if (string_par == NULL)
		return;
	pch=strrchr(string_par,'\r');
	if (pch)*pch=' ';
	pch1='\0';
	pch = string_par + strlen(string_par) - 1;
	if (debug&debug_level) my_print("pch=%cx\n",*pch);
	if (*pch=='\n') { pch1=*pch;pch--;}
	while (*pch == ' ')
		pch--;
	pch++;
	if (pch1=='\n') {
		*pch = '\n';pch++;*pch='\0';
	} else *pch='\0';
	strcpy(function_name,saved_function_name);
}
void strip_initial_comment(char *sqlstatement)
/* we will detect if there's a comment at the start of the SQL and strip it off*/
{
	char *point, *point1;
	point=(char *) malloc(strlen(sqlstatement));
	if (*sqlstatement!='/') return;
	if (*(sqlstatement+1)!='*') return; // this should give an erroneous statement, but the dbms will detect it
	// now we have a comment at the start, let's get the */ ending it, and position the param at the end of it
	strcpy(point,strstr(sqlstatement,"*/"));
	point1=point;
	point+=2;
	while(*point==' '||*point=='\t'||*point=='\n') point++;
	strcpy(sqlstatement,point);
	point-=2;
	free(point1);
}
void get_next_sql(
	FILE * fp,
	char *statement,
	char *line,
	int *linenbr,
	int *actual_start_line)
{
	char   *argument,saved_function_name[50],*end_comment,*pline;
	int     len,debug_level=1<<10, stmt_len=0, in_comment=FALSE,is_plsql=FALSE, is_firstline=TRUE;
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"get_next_sql");
	while (!feof(fp)) {
		argument = fgets(line, MAX_LINE_SIZE, fp);
		if (argument == NULL){
			if (debug&debug_level) my_print("argument is null at line %d\n",*linenbr);
			strcpy(function_name,saved_function_name);
			return;
		}
		(*linenbr)++;
		/* find first non space char */
		pline=argument;
		if (!(*statement=='\0' && (strncasecmp(pline,"set ",4)==0||strncasecmp(pline,"spo",3)==0||strncasecmp(pline,"--",2)==0||strncasecmp(pline,"exit",4)==0))) {
			while (*pline==' '||*pline=='\t') pline++;
			end_comment=strstr(pline,"*/");
			if (debug&debug_level) my_print("in_comment=%d end_comment=%s got pline=%s",in_comment,end_comment,pline);
			if (((strncmp(pline,"/*",2)==0 && end_comment!=NULL) || 
				(!in_comment && strncmp(pline,"/*",2)!=0)|| 
				(in_comment && end_comment!=NULL)
				)){
				/* if we are not starting a comment, or we're not in a comment, or we ended a comment, continue*/
				if (debug&debug_level) my_print("we'll set in_comment to false\n");
				if (debug&debug_level && end_comment!=NULL && *(end_comment+2)=='\n') my_print("end_comment is at the end of the line and strlen(pline)=%d\n",strlen(pline));
				if (!in_comment&&(end_comment!=NULL && strstr(pline,"/*")!=NULL)) end_comment=NULL; // we consider that we have a comment withing the line
				// somehting like select /* .... */
				in_comment=FALSE;
				if (strlen(pline)>1 &&(end_comment==NULL || *(end_comment+2)!='\n')){
					if (end_comment!=NULL&&in_comment) argument=end_comment+2;
					if (debug&debug_level)my_print("argument=%s",argument);
					if (debug&debug_level&&strncasecmp(argument,"rem",3)==0) my_print("getting rem len=%d, line=%s\n",strlen(line), line);
					if (!(strncasecmp(argument,"rem ",4)==0 || (strncasecmp(argument,"rem",3)==0 && strlen(argument)==4) ||
						strncasecmp(argument,"remark ",7)==0 || (strncasecmp(argument,"remark",6)==0 && strlen(argument)==7))){
						if (is_firstline) {
							is_firstline=FALSE;
							*actual_start_line=*linenbr-1;
							if (debug&debug_level) my_print("we have actual_line_nbr=%d\n",*actual_start_line);
							if (strncasecmp(argument,"begin",5)==0||strncasecmp(argument,"declare",7)==0) // it is a pl/sql
								is_plsql=TRUE;
						}
						strip_right_space(argument);
						len = strlen(argument)-1;
						if (debug&debug_level)
							my_print("len=%d str=%s", len, argument);
						if ((len == 1 && *argument == '/')
							|| (len==1 && *argument == ';')){
							if (debug&debug_level)
								my_print("got ; or / as the sole char on a line, statement is: %s \n", statement);
							strcpy(function_name,saved_function_name);
							return;
						}
						if (strlen(statement)+strlen(argument)>MAX_STMT_SIZE-1) {
							my_print("found a statement that is more than %d long, we will return and this will mlake the sql incomplete\n",MAX_STMT_SIZE);
							return;
						}
						if (*statement!='\0') strcat(statement, " ");
						strcat(statement, argument);
						if (*(len-1+argument)==';'&&is_plsql==FALSE) {/* there's a ; at the end of the line, and this is not a pl/sql, so the SQL is finished*/
							/* strip the ';' at the end */
							if (debug&debug_level)
								my_print("got ; at then end of line, len=%d str=%s", strlen(statement), statement);
							*(statement+strlen(statement)-2)='\0';
							strcpy(function_name,saved_function_name);
							return;
						}
					}
				}
			} else in_comment=TRUE;
		}
	}
	if (debug&debug_level)
		my_print("file is finished len=%d str=%s\n", strlen(statement), statement);
	strcpy(function_name,saved_function_name);

}

void get_st_time(
	char *local_time)
{
	time_t  raw_time;
	struct tm *time_info;
	struct timespec spec;
	time(&raw_time);
	clock_gettime(CLOCK_REALTIME,&spec);
	time_info = localtime(&raw_time);
	sprintf(local_time, "%d/%d/%d %d:%d:%d.%d", time_info->tm_mday,
		1 + (time_info->tm_mon), 1900 + time_info->tm_year,
		time_info->tm_hour, time_info->tm_min, time_info->tm_sec,spec.tv_nsec);
}

int processing_thread(
	)
{
	int     pid, VInst_id, ret_code, i, Vchild_n, Vlobsize,
		VPrev_Exec_Id, sql_start_line;
	int     query_nbr, yet_more_rows, ticks1;
	long    cum_rows;
	long    real_time_total = 0;
	time_t  raw_time;
	struct tm time_info;
	struct timeval B_time1, E_time1;
	long    Vexecutions, Vpx_servers_executions, VSorts, VCpu, VElap,
		VRows, VDr, VBg, VIOCuncomp, VIOel, VIOin, VIOd;
	long    mx_time, real_t;
	double  tot_per_proc = 0.;
	char    d_file_name[MAX_FILENAME_SIZE],v_set_app_info[500],
		sqlm_file_name[MAX_FILENAME_SIZE], Vchar_prev_sql_id[30],
		loc_time[30], argument1[2], query_name1[101], saved_function_name[50],*dir_name;
	int     debug_level=1<<11,Reduced_size, VOffset;
	pid = 0;
	real_t = 0;
	sp_sql_id[0]='\0';
	time_first_fetch.tv_sec=0;
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"processing_thread");
	srand(time(NULL));
	Vchild_n=0;
	mx_time = max_time;
	gethostname(v_host_name,256);
	strcpy(logfile_dir,log_file_name);
	dir_name=strrchr(logfile_dir,'/');
	if (dir_name!=NULL)*(dir_name+1)='\0'; 
	else logfile_dir[0]='\0';
	if (debug&debug_level) my_print("host_name=%s max_time=%ld bind_file_name=%s, username=%s, saved_username=%s\n",v_host_name,mx_time,bind_file_name, username,saved_username);
	if (saved_username[0] == '\0' || strcmp(saved_username, username)) {
		/* either this was the first connection, or username has changed, so we reconnect */
		if (debug == debug_level)
			my_print("connecting to db in pid=%d username(len=%d)=%s,\n", mypid, strlen(username), username);
		/* EXEC SQL WHENEVER SQLERROR GOTO proc_error; */ 

		/* EXEC SQL CONNECT :username at main_db; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )10;
  sqlstm.offset = (unsigned int  )2960;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)username;
  sqlstm.sqhstl[0] = (unsigned long )256;
  sqlstm.sqhsts[0] = (         int  )256;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlstm.sqlcmax = (unsigned int )100;
  sqlstm.sqlcmin = (unsigned int )2;
  sqlstm.sqlcincr = (unsigned int )1;
  sqlstm.sqlctimeout = (unsigned int )0;
  sqlstm.sqlcnowait = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto proc_error;
}


		/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

		snprintf(v_set_app_info,499,"begin  "
			"\ndbms_application_info.set_client_info(substr('%s',1,case when instr('%s',',')=0 then 64 else instr('%s',',')-1 end));"
			"\ndbms_application_info.set_module('%d:%d','');"
			"\nend;",v_host_name,v_host_name,v_host_name,mypid,trial_nbr);
		/* exec sql at main_db execute immediate  :v_set_app_info; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2998;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)v_set_app_info;
  sqlstm.sqhstl[0] = (unsigned long )500;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if (sqlca.sqlcode!=0) 
			my_print("could not set app info with statement=%s\n",v_set_app_info);
		strcpy(saved_username, username);
		/* exec sql at main_db select replace(version,'.'), sys_context('userenv','sid'), sys_context('userenv','instance')
			into :v_db_version, :mysid, :myinstance
			from product_component_version
			where lower(product) like '%database%'
			and rownum=1; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select replace ( version , '.' ) , sys_context ( 'userenv' \
, 'sid' ) , sys_context ( 'userenv' , 'instance' ) into :b0 , :b1 , :b2 from p\
roduct_component_version where lower ( product ) like '%database%' and rownum \
= 1 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3024;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_db_version;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&mysid;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&myinstance;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if (debug&debug_level)
			my_print("connected to db in pid=%d and set app_info sqlca.sqlcode=%d, mysid=%d, myinstance=%d\n", mypid,sqlca.sqlcode,
			mysid, myinstance);
	}
	if (strcmp(perf_db_uname,username)!=0 && connect_perf==0) {
		/* the response_times table is in a different db, and we're not connected there yet */
		if (debug == debug_level)
			my_print("connecting to perf db in pid=%d username(len=%d)=%s\n", mypid, strlen(perf_db_uname), perf_db_uname);
		/* EXEC SQL WHENEVER SQLERROR GOTO proc_error; */ 

		/* EXEC SQL CONNECT :perf_db_uname at perf_db; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )10;
  sqlstm.offset = (unsigned int  )3058;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)perf_db_uname;
  sqlstm.sqhstl[0] = (unsigned long )256;
  sqlstm.sqhsts[0] = (         int  )256;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlstm.sqlcmax = (unsigned int )100;
  sqlstm.sqlcmin = (unsigned int )2;
  sqlstm.sqlcincr = (unsigned int )1;
  sqlstm.sqlctimeout = (unsigned int )0;
  sqlstm.sqlcnowait = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto proc_error;
}


		/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

		connect_perf=1;
		strcpy(db_name,"perf_db");
		if (debug&debug_level)
			my_print("connected to %s\n", db_name);
	}
	if (debug&debug_level)
		my_print("in pid=%d processing for query_name=%s\n", mypid,
		       query_name);
	{
		FILE   *out_fp,  *log_fp, *sqlm_fp, *qfile_fp;
		/*query_name1 = (char *) malloc(strlen(query_name) + 1);*/
		strcpy(query_name1, query_name);
		if (debug&debug_level)
			my_print("processing thread with pid=%d\n", mypid);
		if (file_name[0] != '\0') {
			sprintf(d_file_name, file_name, mypid);
			if (debug&debug_level)
				my_print(" Data file name %s\n",
				       d_file_name);
			out_fp = fopen(d_file_name, "w");
			if (out_fp == NULL) {
				my_print("Open Error for data file %s\n",
				       d_file_name);
				strcpy(function_name,saved_function_name);
				return 0 - mypid;
			}
		} else
			out_fp = NULL;
		if (*setup_script != '\0')
			/* exec sql at main_db execute immediate :setup_script; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3096;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)setup_script;
   sqlstm.sqhstl[0] = (unsigned long )257000;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if (sqlca.sqlcode != 0) {
			my_print("\n\n%.70s\n", sqlca.sqlerrm.sqlerrmc);
			my_print("Setup SQL is: %s\n", setup_script);
		} else
			*setup_script = '\0';
		if (trial_nbr != 0) {
			if (debug&debug_level) my_print("inserting into runs_desc at db_name=%s\n",db_name);
			if (already_inserted==0) /* exec sql at :db_name  insert into runs_desc(
					trial_nbr,
					pid,
					time_stamp_beg,
					sid,
					instance,host_name,bind_file_name) values(
					:trial_nbr,
					:mypid,
					systimestamp,
					sys_context('USERENV', 'SID'),
					sys_context('USERENV', 'INSTANCE'), :v_host_name, :bind_file_name)
					returning rowid into :runs_desc_rowid; */ 

{
                            struct sqlexd sqlstm;
                            sqlstm.sqlvsn = 13;
                            sqlstm.arrsiz = 44;
                            sqlstm.sqladtp = &sqladt;
                            sqlstm.sqltdsp = &sqltds;
                            sqlstm.stmt = "insert into runs_desc ( trial_nbr\
 , pid , time_stamp_beg , sid , instance , host_name , bind_file_name ) values\
 ( :b1 , :b2 , systimestamp , sys_context ( 'USERENV' , 'SID' ) , sys_context \
( 'USERENV' , 'INSTANCE' ) , :b3 , :b4 ) returning rowid into :b5 ";
                            sqlstm.iters = (unsigned int  )1;
                            sqlstm.offset = (unsigned int  )3122;
                            sqlstm.cud = sqlcud0;
                            sqlstm.sqlest = (unsigned char  *)&sqlca;
                            sqlstm.sqlety = (unsigned short)4352;
                            sqlstm.occurs = (unsigned int  )1;
                            sqlstm.sqhstv[0] = (unsigned char  *)&trial_nbr;
                            sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                            sqlstm.sqhsts[0] = (         int  )0;
                            sqlstm.sqindv[0] = (         short *)0;
                            sqlstm.sqinds[0] = (         int  )0;
                            sqlstm.sqharm[0] = (unsigned long )0;
                            sqlstm.sqadto[0] = (unsigned short )0;
                            sqlstm.sqtdso[0] = (unsigned short )0;
                            sqlstm.sqhstv[1] = (unsigned char  *)&mypid;
                            sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                            sqlstm.sqhsts[1] = (         int  )0;
                            sqlstm.sqindv[1] = (         short *)0;
                            sqlstm.sqinds[1] = (         int  )0;
                            sqlstm.sqharm[1] = (unsigned long )0;
                            sqlstm.sqadto[1] = (unsigned short )0;
                            sqlstm.sqtdso[1] = (unsigned short )0;
                            sqlstm.sqhstv[2] = (unsigned char  *)v_host_name;
                            sqlstm.sqhstl[2] = (unsigned long )257;
                            sqlstm.sqhsts[2] = (         int  )0;
                            sqlstm.sqindv[2] = (         short *)0;
                            sqlstm.sqinds[2] = (         int  )0;
                            sqlstm.sqharm[2] = (unsigned long )0;
                            sqlstm.sqadto[2] = (unsigned short )0;
                            sqlstm.sqtdso[2] = (unsigned short )0;
                            sqlstm.sqhstv[3] = (unsigned char  *)bind_file_name;
                            sqlstm.sqhstl[3] = (unsigned long )513;
                            sqlstm.sqhsts[3] = (         int  )0;
                            sqlstm.sqindv[3] = (         short *)0;
                            sqlstm.sqinds[3] = (         int  )0;
                            sqlstm.sqharm[3] = (unsigned long )0;
                            sqlstm.sqadto[3] = (unsigned short )0;
                            sqlstm.sqtdso[3] = (unsigned short )0;
                            sqlstm.sqhstv[4] = (unsigned char  *)runs_desc_rowid;
                            sqlstm.sqhstl[4] = (unsigned long )20;
                            sqlstm.sqhsts[4] = (         int  )0;
                            sqlstm.sqindv[4] = (         short *)0;
                            sqlstm.sqinds[4] = (         int  )0;
                            sqlstm.sqharm[4] = (unsigned long )0;
                            sqlstm.sqadto[4] = (unsigned short )0;
                            sqlstm.sqtdso[4] = (unsigned short )0;
                            sqlstm.sqhstv[5] = (unsigned char  *)db_name;
                            sqlstm.sqhstl[5] = (unsigned long )20;
                            sqlstm.sqhsts[5] = (         int  )0;
                            sqlstm.sqindv[5] = (         short *)0;
                            sqlstm.sqinds[5] = (         int  )0;
                            sqlstm.sqharm[5] = (unsigned long )0;
                            sqlstm.sqadto[5] = (unsigned short )0;
                            sqlstm.sqtdso[5] = (unsigned short )0;
                            sqlstm.sqphsv = sqlstm.sqhstv;
                            sqlstm.sqphsl = sqlstm.sqhstl;
                            sqlstm.sqphss = sqlstm.sqhsts;
                            sqlstm.sqpind = sqlstm.sqindv;
                            sqlstm.sqpins = sqlstm.sqinds;
                            sqlstm.sqparm = sqlstm.sqharm;
                            sqlstm.sqparc = sqlstm.sqharc;
                            sqlstm.sqpadto = sqlstm.sqadto;
                            sqlstm.sqptdso = sqlstm.sqtdso;
                            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			already_inserted=1;
			/* exec sql at :db_name select substr(sessiontimezone,1,3)*3600+(substr(sessiontimezone,1,1)||substr(sessiontimezone,5))*60
					into :sessiontimezone_seconds
					from dual; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "select substr ( sessiontimezone , 1 , 3 ) * 3600 + ( subst\
r ( sessiontimezone , 1 , 1 ) || substr ( sessiontimezone , 5 ) ) * 60 into :b\
1 from dual ";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3161;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&sessiontimezone_seconds;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)db_name;
   sqlstm.sqhstl[1] = (unsigned long )20;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			/* exec sql at :db_name commit work; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3184;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)db_name;
   sqlstm.sqhstl[0] = (unsigned long )20;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		}
		if (log_file_name[0] != '\0') {
			sprintf(d_file_name, log_file_name, mypid);
			if (debug&1)
				my_print("log name %s from %s\n",
				       d_file_name, log_file_name);
			log_fp = fopen(d_file_name, "w");
			if (log_fp == NULL) {
				my_print("Open Error for log file %s\n",
				       d_file_name);
				strcpy(function_name,saved_function_name);
				return 0 - mypid;
			}
		} else
			log_fp = NULL;
		if (log_fp == NULL
		    && (print_plan == 1)) {
			printf("Please provide a logfile name (log file= in parameter file) if you want to print statistics or get sqlmon output\n");
			strcpy(function_name,saved_function_name);
			print_plan=0;
			//save_sqlmon=0;
		}
		if (series_of_queries == 1) { // we have to read the statements from a file
			char    line[MAX_LINE_SIZE], *cptr, *sql_file_name;
			int     line_nbr, query_nbr = 0;
			sql_file_name =
				(char *) malloc(strlen(dyn_statement) + 1);
			strcpy(sql_file_name, dyn_statement);
			qfile_fp = fopen(sql_file_name, "r");
			if (qfile_fp == NULL) {
				printf("Open Error for queries file %s\n",
				       sql_file_name);
				strcpy(function_name,saved_function_name);
				free(sql_file_name);
				return 0 - mypid;
			}
			if (debug&debug_level)
				my_print("opened %s file\n", sql_file_name);
			strcpy(dyn_statement, " ");
			yet_more_rows = 0;
			line_nbr = 1;
			query_nbr = 0;
			//argument1 = (char *) malloc(2);
			while ((!feof(qfile_fp)) && yet_more_rows == 0) {
				int     executions, not_plsql, c_executions;
				long    rt = 0;
				cum_rows = 0;
				not_plsql = 0;
				strcpy(argument1, " ");
				dyn_statement[0] = '\0';
				get_next_sql(qfile_fp, dyn_statement, line,
					     &line_nbr,&sql_start_line);
				strip_initial_comment(dyn_statement);
				snprintf(query_name, 190,"%s : (line %d)",
					query_name1,
					sql_start_line  );
				rt = 0;
				real_time_total=0;
				if (debug&debug_level)
					my_print("exec count=%d, Statement from file=%s\n", exec_count, dyn_statement);
				if (debug&debug_level)
					my_print("bind  file=%s\n", bind_file_name);
				sp_sql_id[0]='\0';
				if (strlen(dyn_statement) > 2) {
					get_sql_id();
					if (save_mystats==1) save_my_stats(BEFORE);
					ticks1 = gettimeofday(&B_time1,
							      NULL);
					get_st_time(loc_time);
					/* check if it is a select, if not it is a dml, so we just execute it as is, only once, no time limit */
					if (strncasecmp (dyn_statement, "select", 6) != 0 && strncasecmp(dyn_statement, "with", 4) != 0) {
						if (debug&debug_level)
							my_print("executing a non SELECT statement %s\nbind file name=%s", dyn_statement,bind_file_name);
						if (bind_file_name[0]=='\0') { /* there're no bind fvars, so just execute the statement */
								/* exec sql at main_db execute
									immediate :dyn_statement; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3203;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)dyn_statement;
        sqlstm.sqhstl[0] = (unsigned long )257000;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


								if (sqlca.sqlcode == 0)
									cum_rows =sqlca.sqlerrd[2];
								else my_print("error executing statement=%d",sqlca.sqlcode);
								ticks1 = gettimeofday(&E_time1, NULL);
								real_time =
									(E_time1.tv_sec -
									 B_time1.tv_sec) *
									1000000 +
									(E_time1.tv_usec -
									 B_time1.tv_usec);
								real_time_total =
									real_time;
								if (print_pga_stats == 1
								    && log_fp != NULL)
									print_pgastat
										(log_fp);
								executions = 1;

						} else { /* we have bind vars, so let's loop and execute:
								we execute the SQL once for each line in the file, we don't take into account neither
								the max_time, nor exec_count, as this may lead to inconsistencies, like deleteing the same row twice, ...
								*/
							if (debug&debug_level)
								my_print("executing the sql using bind file  %s\n",bind_file_name);
							process_non_sel();
						}
					} else
						for (executions = 0,first_time=0, c_executions=0;
						     executions < exec_count && (rt < mx_time || mx_time==0);
						     executions++) {
							int     tt;
							if (bind_file_name[0]=='\0'){
								if (think_time_min == think_time_max)
									tt = think_time_min;
								else
									tt = rand() % (think_time_max - think_time_min) + think_time_min;
								usleep(tt);
							}
							ret_code =
								process_sql
								(out_fp,
								 bind_file_name,
								 think_time_min,
								 think_time_max,
								 (mx_time==0)?0:mx_time-rt);
							if (ret_code>=0) { 
								if (print_pga_stats == 1 && log_fp != NULL)
									print_pgastat(log_fp);
								ticks1 = gettimeofday(&E_time1, NULL);
								rt += (E_time1.tv_sec - B_time1.tv_sec) * 1000000 + (E_time1.tv_usec - B_time1.tv_usec);
								B_time1.tv_sec = E_time1.tv_sec;
								B_time1.tv_usec = E_time1.tv_usec;
								real_time_total += real_time;
								cum_rows += cumulative_rows;
								c_executions++;
								if (debug&debug_level) my_print("exec_count=%d, executions=%d, mx_time=%ld, rt=%ld first_time=%ld\n",exec_count,executions,mx_time,real_time_total,first_time);
								if (asked_to_quit ()) {
									mx_time = -1;
								}
							} else {
								rt=mx_time;
							}
							if (/*exec_binds_counter < 2 &&*/ c_executions>flush_results_every){
								int fre=flush_results_every;
								flush_results_every=1;
								get_v_data(query_name, Vchar_prev_sql_id,
									   &Vchild_n, &VPrev_Exec_Id,
									   trial_nbr, executions,
									   cumulative_rows,
									   real_time_total, first_time,loc_time,
									   mypid);
								get_st_time(loc_time);
								flush_results_every=fre;
								c_executions=0;
							}
						}
					if (ret_code>=0) {
						if (save_mystats==1) save_my_stats(BEFORE+1);
						if (1/*exec_binds_counter*/ < 2)	/* we only put the data if it is not executed with binds, more than one time */
							get_v_data(query_name,
								   Vchar_prev_sql_id,
								   &Vchild_n,
								   &VPrev_Exec_Id,
								   trial_nbr,
								   executions,
								   cum_rows,
								   real_time_total,
								   first_time,
								   loc_time,
								   mypid);
						if (sqlset_save > 0 ) {
							save_to_sqlset (Vchar_prev_sql_id, sqlset_name);
						}
						if ((real_time_total>save_sqlmon&&save_sqlmon>0)) {
							get_sql_mon(query_name, Vchar_prev_sql_id, VPrev_Exec_Id);
						}
						if (print_plan == 1) {
							print_sql_plan(log_fp, Vchar_prev_sql_id, Vchild_n, rt);
						}
						if (release_px_slaves==1 && executions==1) { /* need to release px_slaves , do that by 
						calling process_sql with a dummy statement to select * from dual
						we do this only if the query was executed just once */
							strcpy(dyn_statement,"select /* rwpbench release_px_slaves==1*/ * from dual where 1=0");
							char bf[2];
							bf[0]='\0';
							ret_code=process_sql(out_fp, bf, 0,0,0);
						}
					}
					/* EXEC SQL WHENEVER SQLERROR GOTO proc_error; */ 

					if (asked_to_quit()) {
						mx_time = -1;
						yet_more_rows = 1403;
					}
				}
			}
			if (debug&debug_level)
				my_print("Total Execution Time=%lf for proc=%d\n", tot_per_proc, mypid);
			if (sql_file_name!=NULL) free(sql_file_name);
			if (log_fp != NULL)
				fprintf(log_fp,
					"Total Execution Time=%lf\n",
					tot_per_proc);
		} else if (series_of_queries == 2) {
			int     VStmtSize;
			char    ch_read_sql[500], chrowid[50],
				chupdate_stmt[500];
			OCIClobLocator *SQLstmt;
			/* EXEC SQL at main_db ALLOCATE:SQLstmt; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3229;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&SQLstmt;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) goto proc_error;
}


			yet_more_rows = 0;
			query_nbr = 0;

			/* exec sql at main_db declare  get_queries statement; */ 

			/* exec sql at main_db PREPARE get_queries from :dyn_statement; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3255;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)dyn_statement;
   sqlstm.sqhstl[0] = (unsigned long )257000;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) goto proc_error;
}


			/* exec sql at main_db declare get_sql cursor for get_queries; */ 

			if (debug&debug_level)
				printf("opened cursor to get sql from %s\n", dyn_statement);
			/* exec sql open get_sql; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3281;
   sqlstm.selerr = (unsigned short)100;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqcmod = (unsigned int )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) goto proc_error;
}


			while (yet_more_rows == 0) {
				/* exec sql fetch get_sql
					into :SQLstmt, :chrowid; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 44;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3303;
    sqlstm.selerr = (unsigned short)100;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)&SQLstmt;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)chrowid;
    sqlstm.sqhstl[1] = (unsigned long )50;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) goto proc_error;
}


				yet_more_rows = sqlca.sqlcode;
				if (debug&debug_level)
					my_print("got sqlca.sqlcode=%d\n",
					       sqlca.sqlcode);
				sprintf(query_name, "%s : %s",
					query_name1, chrowid);
				strcpy(dyn_statement,"");
				if (asked_to_quit()) {
					yet_more_rows = 1403;
				}
				if (yet_more_rows == 0) {
					/* EXEC SQL at main_db LOB DESCRIBE :SQLstmt GET
						LENGTH INTO :VStmtSize; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 13;
     sqlstm.arrsiz = 44;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )3333;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqhstv[0] = (unsigned char  *)&SQLstmt;
     sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)&VStmtSize;
     sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqphss = sqlstm.sqhsts;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqpins = sqlstm.sqinds;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlstm.sqpadto = sqlstm.sqadto;
     sqlstm.sqptdso = sqlstm.sqtdso;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode < 0) goto proc_error;
}


					Reduced_size = 10000;
					VOffset = 1;
					/* varchar *VStmt = (varchar *) malloc(Reduced_size + 4); */ 
varchar *VStmt
 = malloc((Reduced_size+4));

					VStmt->len = Reduced_size;
					/* EXEC SQL at main_db LOB READ :VStmtSize
						FROM :SQLstmt at :VOffset
						into :VStmt; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 13;
     sqlstm.arrsiz = 44;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )3363;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqhstv[0] = (unsigned char  *)&VStmtSize;
     sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)&SQLstmt;
     sqlstm.sqhstl[1] = (unsigned long )sizeof(void *);
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&VOffset;
     sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)VStmt;
     sqlstm.sqhstl[3] = (unsigned long )0;
     sqlstm.sqhsts[3] = (         int  )0;
     sqlstm.sqindv[3] = (         short *)0;
     sqlstm.sqinds[3] = (         int  )0;
     sqlstm.sqharm[3] = (unsigned long )0;
     sqlstm.sqadto[3] = (unsigned short )0;
     sqlstm.sqtdso[3] = (unsigned short )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqphss = sqlstm.sqhsts;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqpins = sqlstm.sqinds;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlstm.sqpadto = sqlstm.sqadto;
     sqlstm.sqptdso = sqlstm.sqtdso;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode < 0) goto proc_error;
}


					strncat(dyn_statement, VStmt->arr,
						VStmt->len);
					while (sqlca.sqlcode == 0) {
						/* EXEC SQL at main_db LOB
							READ :Reduced_size
							FROM :SQLstmt
							into :VStmt; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 13;
      sqlstm.arrsiz = 44;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )3405;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Reduced_size;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&SQLstmt;
      sqlstm.sqhstl[1] = (unsigned long )sizeof(void *);
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)VStmt;
      sqlstm.sqhstl[3] = (unsigned long )0;
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) goto proc_error;
}


						strncat(dyn_statement,
							VStmt->arr,
							VStmt->len);
						if (debug&debug_level)
							my_print("Got %d of statement\n", Reduced_size);
					}
					free(VStmt);
					long    rt = 0;
					real_time_total=0;
					int     executions, c_executions=0;
					cum_rows = 0;
					ticks1 = gettimeofday(&B_time1, NULL);
					get_st_time(loc_time);
					sp_sql_id[0]='\0';
					get_sql_id();
					if (save_mystats==1) save_my_stats(BEFORE);
					if (strncasecmp (dyn_statement, "select", 6) != 0 && strncasecmp(dyn_statement, "with", 4) != 0) {
						if (debug&debug_level)
							my_print("executing a non SELECT statement %s\n", dyn_statement);
						if (bind_file_name[0]=='\0') { /* there're no bind fvars, so just execute the statement */
							/* exec sql at main_db execute immediate :dyn_statement; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 13;
       sqlstm.arrsiz = 44;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )3447;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)dyn_statement;
       sqlstm.sqhstl[0] = (unsigned long )257000;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqphsv = sqlstm.sqhstv;
       sqlstm.sqphsl = sqlstm.sqhstl;
       sqlstm.sqphss = sqlstm.sqhsts;
       sqlstm.sqpind = sqlstm.sqindv;
       sqlstm.sqpins = sqlstm.sqinds;
       sqlstm.sqparm = sqlstm.sqharm;
       sqlstm.sqparc = sqlstm.sqharc;
       sqlstm.sqpadto = sqlstm.sqadto;
       sqlstm.sqptdso = sqlstm.sqtdso;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) goto proc_error;
}


							if (sqlca.sqlcode == 0)
								cum_rows = sqlca. sqlerrd[2];
							if (print_pga_stats == 1 && log_fp != NULL)
								print_pgastat (log_fp);
							ticks1 = gettimeofday (&E_time1, NULL);
							real_time = (E_time1.tv_sec - B_time1.tv_sec) * 1000000 + (E_time1.tv_usec - B_time1.tv_usec);
							executions = 1;
							first_time=(time_first_fetch.tv_sec - B_time1.tv_sec) * 1000000 + (time_first_fetch.tv_usec - B_time1.tv_usec);
							real_time_total = real_time;
						} else { /* we have bind vars, so let's loop and execute:
								we execute the SQL once for each line in the file, we don't take into account neither
								the max_time, nor exec_count, as this may lead to inconsistencies, like deleteing the same row twice, ...
								*/
							if (debug&debug_level)
								my_print("executing the sql using bind file  %s\n",bind_file_name);
							process_non_sel();
						}
					} else
						for (executions = 0,first_time=0;
						     executions < exec_count
						     && (rt < mx_time|| mx_time==0);
						     executions++) {
							int     tt;
							if (bind_file_name[0]=='\0') {
								if (think_time_min == think_time_max)
									tt = think_time_min;
								else
									tt = rand() % (think_time_max - think_time_min) + think_time_min;
								usleep(tt);
							}
							ret_code =
								process_sql
								(out_fp,
								 bind_file_name,
								 think_time_min,
								 think_time_max,
								 (mx_time==0)?0:mx_time-rt);
							if (ret_code<0) rt=mx_time;
							else {
								if (print_pga_stats == 1 && log_fp != NULL)
									print_pgastat (log_fp);
								ticks1 = gettimeofday(&E_time1, NULL);
								rt += (E_time1. tv_sec - B_time1. tv_sec) * 1000000 + (E_time1.tv_usec - B_time1.tv_usec);
								B_time1.tv_sec = E_time1.tv_sec;
								B_time1.tv_usec = E_time1.tv_usec;
								query_nbr++;
								real_time_total += real_time;
								cum_rows += cumulative_rows;
								c_executions++;
							}
							if (/*exec_binds_counter < 2 &&*/ c_executions>flush_results_every){
								int fre=flush_results_every;
								flush_results_every=1;
								get_v_data(query_name, Vchar_prev_sql_id,
									   &Vchild_n, &VPrev_Exec_Id,
									   trial_nbr, executions,
									   cumulative_rows,
									   real_time_total, first_time,loc_time,
									   mypid);
								get_st_time(loc_time);
								flush_results_every=fre;
								c_executions=0;
							}
							if (asked_to_quit ()) {
								mx_time = -1;
							}
						}
					if (save_mystats==1) save_my_stats(BEFORE+1);
					if (ret_code>=0){
						if (exec_binds_counter < 2)
							get_v_data(query_name,
								   Vchar_prev_sql_id,
								   &Vchild_n,
								   &VPrev_Exec_Id,
								   trial_nbr,
								   executions,
								   cum_rows,
								   real_time_total,
								   first_time,
								   loc_time,
								   mypid);
						if (sqlset_save > 0) {
							save_to_sqlset (Vchar_prev_sql_id, sqlset_name);
						}
						if (real_time_total>save_sqlmon&&save_sqlmon>0) {
							get_sql_mon(query_name,
								    Vchar_prev_sql_id,
								    VPrev_Exec_Id);
						}
						if (print_plan == 1) {
							print_sql_plan(log_fp,
								       Vchar_prev_sql_id,
								       Vchild_n,
								       rt);
						}
						if (release_px_slaves==1 && executions==1) { /* need to release px_slaves , do that by 
						calling process_sql with a dummy statement to select * from dual
						we do this only if the query was executed just once */
							strcpy(dyn_statement,"select /* rwpbench release_px_slaves==1*/ * from dual where 1=0");
							char bf[1]; 
							bf[0]='\0';
							ret_code=process_sql(out_fp, bf, 0,0,0);
						}
					}
					/* EXEC SQL WHENEVER SQLERROR GOTO
						proc_error; */ 

					if (asked_to_quit()) {
						mx_time = -1;
					}
				}
			}
			/* exec sql close get_sql; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3473;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) goto proc_error;
}


			/* exec sql at main_db free :SQLstmt; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3495;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&SQLstmt;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) goto proc_error;
}


			if (log_fp != NULL)
				fprintf(log_fp,
					"Total Execution Time=%lf\n",
					tot_per_proc);
			if (debug&debug_level)
				printf("Total Execution Time=%lf for proc=%d\n", tot_per_proc, mypid);
		} else {	/* single statement entry */
			real_t = 0;
			int     executions = 0;
			int c_executions=0;
			cum_rows = 0;
			if (debug&debug_level)
				printf("%s\n", dyn_statement);
			ticks1 = gettimeofday(&B_time1, NULL);
			get_st_time(loc_time);
			get_sql_id();
			if (save_mystats==1) save_my_stats(BEFORE);
			if (strncasecmp(dyn_statement, "select", 6) != 0
			    && strncasecmp(dyn_statement, "with", 4) != 0) {
				if (debug&debug_level)
					my_print("executing a non SELECT statement %s\n", dyn_statement);
				if (bind_file_name[0]=='\0') { /* there're no bind fvars, so just execute the statement */
						/* exec sql at main_db execute immediate:dyn_statement; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 13;
      sqlstm.arrsiz = 44;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )3521;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)dyn_statement;
      sqlstm.sqhstl[0] = (unsigned long )257000;
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) goto proc_error;
}


						if (sqlca.sqlcode == 0)
							cum_rows = sqlca.sqlerrd[2];
						if (print_pga_stats == 1 && log_fp != NULL)
							print_pgastat(log_fp);
						ticks1 = gettimeofday(&E_time1, NULL);
						real_time_total =
							(E_time1.tv_sec -
							 B_time1.tv_sec) * 1000000 +
							(E_time1.tv_usec -
							 B_time1.tv_usec);
				} else { /* we have bind vars, so let's loop and execute:
								we execute the SQL once for each line in the file, we don't take into account neither
								the max_time, nor exec_count, as this may lead to inconsistencies, like deleteing the same row twice, ...
								*/
							if (debug&debug_level)
								my_print("executing the sql using bind file  %s\n",bind_file_name);
							process_non_sel();
				}
			} else
				while ((real_t < mx_time||mx_time==0)
				       && executions < exec_count) {
					int     tt;
					if (think_time_min == think_time_max)
						tt = think_time_min;
					else
						tt = rand() % (think_time_max - think_time_min) + think_time_min;
					usleep(tt);
					ret_code =
						process_sql(out_fp, 
							    bind_file_name,
							    think_time_min,
							    think_time_max,
							    (mx_time==0)?0:mx_time-real_t);
					ticks1 = gettimeofday(&E_time1, NULL);
					if (print_pga_stats == 1 && log_fp != NULL)
						print_pgastat(log_fp);
					if (ret_code < 0) {
						strcpy(function_name,saved_function_name);
						return (0 - mypid);
						}
					cum_rows += cumulative_rows;
					executions++;
					c_executions++;
					if (debug&debug_level)
						my_print("exec_count=%d mx_time=%ld executions=%d flush_r_e=%d\n", exec_count, mx_time, c_executions, flush_results_every);
					real_time_total += real_time;
					real_t += (E_time1.tv_sec - B_time1.tv_sec) * 1000000 + (E_time1.tv_usec - B_time1.tv_usec);
					B_time1.tv_sec = E_time1.tv_sec;
					B_time1.tv_usec = E_time1.tv_usec;
					if (asked_to_quit()) {
						mx_time = -1;
					}
					if (/*exec_binds_counter < 2 &&*/ c_executions>flush_results_every){
						int fre=flush_results_every;
						flush_results_every=1;
						get_v_data(query_name, Vchar_prev_sql_id,
							   &Vchild_n, &VPrev_Exec_Id,
							   trial_nbr, executions,
							   cumulative_rows,
							   real_time_total, first_time,loc_time,
							   mypid);
						get_st_time(loc_time);
						flush_results_every=fre;
						c_executions=0;
					}
/*					if (mx_time == 0)
						mx_time--; */
				}
			if (save_mystats==1) save_my_stats(BEFORE+1);
			Vexecutions = executions;
			if (exec_binds_counter < 2){
				get_v_data(query_name, Vchar_prev_sql_id,
					   &Vchild_n, &VPrev_Exec_Id,
					   trial_nbr, executions,
					   cumulative_rows,
					   real_time_total, first_time,loc_time,
					   mypid);
				if (sqlset_save > 0) {
					save_to_sqlset(Vchar_prev_sql_id, sqlset_name);
				}
				if (real_time_total>save_sqlmon&&save_sqlmon>0) {
					get_sql_mon(query_name, Vchar_prev_sql_id, VPrev_Exec_Id);
				}
				if (print_plan == 1) {
					print_sql_plan(log_fp, Vchar_prev_sql_id,
						       Vchild_n, real_time_total);
				}
			}
			if (release_px_slaves==1 && executions==1) { /* need to release px_slaves , do that by 
					calling process_sql with a dummy statement to select * from dual
					we do this only if the query was executed just once */
				strcpy(dyn_statement,"select /* rwpbench release_px_slaves==1*/ * from dual where 1=0");
				char bf[1]; 
				bf[0]='\0';
				ret_code=process_sql(out_fp, bf, 0,0,0);
			}
			/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

		}
		if (trial_nbr != 0) {
			if (debug&debug_level) my_print("updating runs_desc at db_name=%s\n",db_name);
			/* exec sql at :db_name update runs_desc set time_stamp_end=systimestamp, description=:run_desc
				where rowid=:runs_desc_rowid; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "update runs_desc set time_stamp_end = systimestamp , descr\
iption = :b1 where rowid = :b2 ";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3547;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)run_desc;
   sqlstm.sqhstl[0] = (unsigned long )101;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)runs_desc_rowid;
   sqlstm.sqhstl[1] = (unsigned long )20;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)db_name;
   sqlstm.sqhstl[2] = (unsigned long )20;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				/*pid=:mypid
				and instance=sys_context('USERENV', 'INSTANCE')
				and sid=sys_context('USERENV', 'SID')
				and trial_nbr=:trial_nbr
				-- and time_stamp_end is null
				;*/
			if (debug&debug_level) my_print("after update runs_desc errc=%d, trial_nbr=%d, mypid=%d\n",sqlca.sqlcode,trial_nbr,mypid );
			/* exec sql at :db_name commit; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3574;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)db_name;
   sqlstm.sqhstl[0] = (unsigned long )20;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		}
		if (debug&debug_level) my_print("print_my_stats=%d log file is opened %d\n",print_my_stats,(log_fp==NULL)?0:1);
		if (print_my_stats == 1 && log_fp != NULL)
			print_mystat(log_fp);
		if (log_fp != NULL)
			fclose(log_fp);
		if (out_fp != NULL)
			fclose(out_fp);
		strcpy(function_name,saved_function_name);
		return 0 - mypid;
	      proc_error:
		my_print("Got error: %.70s\n", sqlca.sqlerrm.sqlerrmc);
		my_print("SQL stmt:%s",dyn_statement);
		if (log_fp != NULL)
			fclose(log_fp);
		if (out_fp != NULL)
			fclose(out_fp);
		strcpy(function_name,saved_function_name);
		return 0 - mypid;
	}
}


void check_create_tracking_tables(
	char *user_name)
{				/* if trial_nbr is set to something, then we check for the user in question if the tracking tables, response_times and runs_desc are there, if not, we create them
				   this is only done for the main user, passed on the command line, if you're using different usernames, then add these tables manually to each schema */
	int     trial_nbr,cnt;

	char *achColumns[]={
			    "QUERY_NAME VARCHAR2 (200)",
"PROCESS_ID NUMBER ",
"INST_ID NUMBER ",
"TRIAL_NBR NUMBER ",
"SQL_ID VARCHAR2 (20)",
"CHILD_NBR NUMBER ",
"EXEC_ID NUMBER ",
"ROWS_P NUMBER ",
"ELAPSED_T NUMBER ",
"ELAPSED_FIRST_FETCH NUMBER ",
"EXECUTIONS NUMBER ",
"TIME_ST TIMESTAMP(6) ",
"IO_CELL_OFFLOAD_ELIGIBLE_BYTES NUMBER ",
"PX_IS_CROSS_INSTANCE CHAR (1)",
"PX_SERVERS_REQUESTED NUMBER ",
"PX_SERVERS_ALLOCATED NUMBER ",
"ELAPSED_TIME NUMBER ",
"QUEUING_TIME NUMBER ",
"CPU_TIME NUMBER ",
"FETCHES NUMBER ",
"BUFFER_GETS NUMBER ",
"DISK_READS NUMBER ",
"DIRECT_WRITES NUMBER ",
"IO_INTERCONNECT_BYTES NUMBER ",
"PHYSICAL_READ_REQUESTS NUMBER ",
"PHYSICAL_READ_BYTES NUMBER ",
"PHYSICAL_WRITE_REQUESTS NUMBER ",
"PHYSICAL_WRITE_BYTES NUMBER ",
"APPLICATION_WAIT_TIME NUMBER ",
"CONCURRENCY_WAIT_TIME NUMBER ",
"CLUSTER_WAIT_TIME NUMBER ",
"USER_IO_WAIT_TIME NUMBER ",
"PLSQL_EXEC_TIME NUMBER ",
"JAVA_EXEC_TIME NUMBER ",
"BIND_FILE_LINE_NBR NUMBER ",
"SQL_PLAN_HASH_VALUE NUMBER ",
"IM_SCANS NUMBER ",
"IM_SCAN_BYTES_UNCOMPRESSED NUMBER ",
"IM_SCAN_BYTES_INMEMORY NUMBER ",
"SQL_PROFILE VARCHAR2 (64)",
"SQL_PATCH VARCHAR2 (128)",
"SQL_PLAN_BASELINE VARCHAR2 (128)",
"EXACT_MATCHING_SIGNATURE varchar2(40) ",
"FORCE_MATCHING_SIGNATURE  varchar2(40) "};
	char    chCreate_Table[2500] = "CREATE TABLE RESPONSE_TIMES\
			   (	query_name VARCHAR2(200),\
				process_id number,\
				Inst_id number,\
				trial_nbr number,\
				sql_id	varchar2(20),\
				child_nbr	number,\
				exec_id number,\
				rows_p number,\
				elapsed_t number,\
				elapsed_first_fetch number,\
				executions number,\
				time_st timestamp,\
				IO_CELL_OFFLOAD_ELIGIBLE_BYTES NUMBER,\
				PX_IS_CROSS_INSTANCE  char(1),\
				px_servers_requested  number,\
				px_servers_allocated  number,\
				ELAPSED_TIME		 NUMBER,\
				QUEUING_TIME		 NUMBER,\
				CPU_TIME		 NUMBER,\
				FETCHES			 NUMBER,\
				BUFFER_GETS		 NUMBER,\
				DISK_READS		 NUMBER,\
				DIRECT_WRITES		 NUMBER,\
				IO_INTERCONNECT_BYTES	 NUMBER,\
				PHYSICAL_READ_REQUESTS	 NUMBER,\
				PHYSICAL_READ_BYTES	 NUMBER,\
				PHYSICAL_WRITE_REQUESTS	 NUMBER,\
				PHYSICAL_WRITE_BYTES	 NUMBER,\
				APPLICATION_WAIT_TIME NUMBER,\
				CONCURRENCY_WAIT_TIME NUMBER,\
				CLUSTER_WAIT_TIME     NUMBER,\
				USER_IO_WAIT_TIME     NUMBER,\
				PLSQL_EXEC_TIME	      NUMBER,\
				JAVA_EXEC_TIME	      NUMBER,\
				bind_file_line_nbr	number,\
				sql_plan_hash_value number,\
				IM_SCANS                            NUMBER,\
				IM_SCAN_BYTES_UNCOMPRESSED          NUMBER,\
				IM_SCAN_BYTES_INMEMORY              NUMBER,\
				SQL_PROFILE                VARCHAR2(64), \
				SQL_PATCH                  VARCHAR2(128), \
				SQL_PLAN_BASELINE          VARCHAR2(128), \
				EXACT_MATCHING_SIGNATURE   NUMBER, \
				FORCE_MATCHING_SIGNATURE   NUMBER\
								)";
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	if (strcmp(db_name,"perf_db")==0){
		/* EXEC SQL CONNECT :user_name at :db_name; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )10;
  sqlstm.offset = (unsigned int  )3593;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)user_name;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)db_name;
  sqlstm.sqhstl[4] = (unsigned long )20;
  sqlstm.sqhsts[4] = (         int  )20;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlstm.sqlcmax = (unsigned int )100;
  sqlstm.sqlcmin = (unsigned int )2;
  sqlstm.sqlcincr = (unsigned int )1;
  sqlstm.sqlctimeout = (unsigned int )0;
  sqlstm.sqlcnowait = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if (debug == 1)
			my_print("connected to perfdb=%s, after select sqlca.sqlcode=%d, nbr_of_cols=%d\n", user_name, sqlca.sqlcode,trial_nbr);
		if (sqlca.sqlcode!=0){
			my_print("Cannot connect to perf db as %s, aborting\n",user_name);
			exit(EXIT_FAILURE);
		}
	}
	/* exec sql at :db_name select count(0)
		into :trial_nbr
		from user_tab_columns
		where table_name='RESPONSE_TIMES'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 44;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 0 ) into :b1 from user_tab_columns where tabl\
e_name = 'RESPONSE_TIMES' ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3628;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.sqlpfmem = (unsigned int  )0;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&trial_nbr;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)db_name;
 sqlstm.sqhstl[1] = (unsigned long )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (debug == 1)
		my_print("connected to schema=%s, after select sqlca.sqlcode=%d, nbr_of_cols=%d\n", user_name, sqlca.sqlcode,trial_nbr);
	if (trial_nbr==0) {
		/* Table not found or not accessible */
		/* exec sql at :db_name execute immediate :chCreate_Table; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3651;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)chCreate_Table;
  sqlstm.sqhstl[0] = (unsigned long )2500;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)db_name;
  sqlstm.sqhstl[1] = (unsigned long )20;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		/* exec sql at :db_name execute immediate
			'create table runs_desc (trial_nbr number, pid number, time_stamp_beg timestamp, time_stamp_end timestamp, sid number, instance number,bind_file_name VARCHAR2(512),host_name varchar2(256),description varchar2(100))'; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "create table runs_desc (trial_nbr number, pid number, time_stamp_beg timestamp, time_stamp_end timestamp, sid number, instance number,bind_file_name VARCHAR2(512),host_name varchar2(256),description varchar2(100))";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3674;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)db_name;
  sqlstm.sqhstl[0] = (unsigned long )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		/* exec sql at :db_name execute immediate
			'create table my_stats (trial_nbr number, pid number, query_name varchar2(200),sid number, statistic# number,value number)'; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "create table my_stats (trial_nbr number, pid number, query_name varchar2(200),sid number, statistic# number,value number)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3693;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)db_name;
  sqlstm.sqhstl[0] = (unsigned long )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		/* exec sql at :db_name execute immediate 'grant all on response_times to public'; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "grant all on response_times to public";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3712;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)db_name;
  sqlstm.sqhstl[0] = (unsigned long )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		/* exec sql at :db_name execute immediate 'create public synonym response_times for response_times'; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "create public synonym response_times for response_times";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3731;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)db_name;
  sqlstm.sqhstl[0] = (unsigned long )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		/* exec sql at :db_name execute immediate 'grant all on runs_desc to public'; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "grant all on runs_desc to public";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3750;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)db_name;
  sqlstm.sqhstl[0] = (unsigned long )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		/* exec sql at :db_name execute immediate 'create public synonym runs_desc for runs_desc'; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "create public synonym runs_desc for runs_desc";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3769;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)db_name;
  sqlstm.sqhstl[0] = (unsigned long )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		/* exec sql at :db_name execute immediate 'grant all on my_stats to public'; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "grant all on my_stats to public";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3788;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)db_name;
  sqlstm.sqhstl[0] = (unsigned long )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		/* exec sql at :db_name execute immediate 'create public synonym my_stats for my_stats'; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "create public synonym my_stats for my_stats";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3807;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)db_name;
  sqlstm.sqhstl[0] = (unsigned long )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	} else if (trial_nbr!=44){
		char altertab[5000];
		strcpy(altertab,"alter table response_times add (");
		for (cnt=trial_nbr;cnt<43;cnt++) {
			strcat(altertab,achColumns[cnt]);
			strcat(altertab,",");
			if (debug == 1)
				my_print("cnt=%d altertab=%s\n",cnt, altertab);
		}
		strcat(altertab,achColumns[cnt]);
		strcat(altertab,")");
		if (debug == 1)
			my_print("altertab=%s\n", altertab);
		/* exec sql at :db_name execute immediate :altertab; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3826;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)altertab;
  sqlstm.sqhstl[0] = (unsigned long )5000;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)db_name;
  sqlstm.sqhstl[1] = (unsigned long )20;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	}
	if (strcmp(db_name,"perf_db")==0) {
			my_print("disconnecting from db %s",db_name);
			/* exec sql at :db_name commit work release; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3849;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)db_name;
   sqlstm.sqhstl[0] = (unsigned long )20;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	}
}

void print_results(
	int trial_nbr,
	char *username)
{
	char    V_arr_query_name[200];
	double  V_arr_IO_INTERCONNECT_BYTES,
		V_arr_PHYSICAL_READ_BYTES,
		V_arr_PHYSICAL_WRITE_BYTES;
	int     proc_count,i, fetched_this_time, cumulative_rows,
		V_arr_APPLICATION_WAIT_TIME,
		V_arr_CONCURRENCY_WAIT_TIME,
		V_arr_CLUSTER_WAIT_TIME, V_arr_USER_IO_WAIT_TIME,
		V_arr_elapsed_time, V_arr_QUEUING_TIME,
		V_arr_CPU_TIME, V_arr_px_servers_requested,
		V_arr_px_servers_allocated, V_arr_elapsed_t,
		V_arr_executions, V_arr_BUFFER_GETS,
		V_arr_PHYSICAL_WRITE_REQUESTS, im_used,rac_used,
		V_arr_PHYSICAL_READ_REQUESTS,V_arr_IM_SCANS, V_arr_IM_S_B_UNCOMP, V_arr_IM_S_B_IMC;
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	im_used=0;
	rac_used=0;
	if (strcmp(db_name,"perf_db")==0)	/* EXEC SQL CONNECT :username at :db_name; */ 

{
                                   struct sqlexd sqlstm;
                                   sqlstm.sqlvsn = 13;
                                   sqlstm.arrsiz = 44;
                                   sqlstm.sqladtp = &sqladt;
                                   sqlstm.sqltdsp = &sqltds;
                                   sqlstm.iters = (unsigned int  )10;
                                   sqlstm.offset = (unsigned int  )3868;
                                   sqlstm.cud = sqlcud0;
                                   sqlstm.sqlest = (unsigned char  *)&sqlca;
                                   sqlstm.sqlety = (unsigned short)4352;
                                   sqlstm.occurs = (unsigned int  )0;
                                   sqlstm.sqhstv[0] = (unsigned char  *)username;
                                   sqlstm.sqhstl[0] = (unsigned long )0;
                                   sqlstm.sqhsts[0] = (         int  )0;
                                   sqlstm.sqindv[0] = (         short *)0;
                                   sqlstm.sqinds[0] = (         int  )0;
                                   sqlstm.sqharm[0] = (unsigned long )0;
                                   sqlstm.sqadto[0] = (unsigned short )0;
                                   sqlstm.sqtdso[0] = (unsigned short )0;
                                   sqlstm.sqhstv[4] = (unsigned char  *)db_name;
                                   sqlstm.sqhstl[4] = (unsigned long )20;
                                   sqlstm.sqhsts[4] = (         int  )20;
                                   sqlstm.sqindv[4] = (         short *)0;
                                   sqlstm.sqinds[4] = (         int  )0;
                                   sqlstm.sqharm[4] = (unsigned long )0;
                                   sqlstm.sqadto[4] = (unsigned short )0;
                                   sqlstm.sqtdso[4] = (unsigned short )0;
                                   sqlstm.sqphsv = sqlstm.sqhstv;
                                   sqlstm.sqphsl = sqlstm.sqhstl;
                                   sqlstm.sqphss = sqlstm.sqhsts;
                                   sqlstm.sqpind = sqlstm.sqindv;
                                   sqlstm.sqpins = sqlstm.sqinds;
                                   sqlstm.sqparm = sqlstm.sqharm;
                                   sqlstm.sqparc = sqlstm.sqharc;
                                   sqlstm.sqpadto = sqlstm.sqadto;
                                   sqlstm.sqptdso = sqlstm.sqtdso;
                                   sqlstm.sqlcmax = (unsigned int )100;
                                   sqlstm.sqlcmin = (unsigned int )2;
                                   sqlstm.sqlcincr = (unsigned int )1;
                                   sqlstm.sqlctimeout = (unsigned int )0;
                                   sqlstm.sqlcnowait = (unsigned int )0;
                                   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* exec sql at :db_name declare c_p_r cursor for
		select substr(r.query_name,1,40) query_name,
		sum( trunc(elapsed_t/1000)) wall_time,
		sum( trunc(nvl(elapsed_time, 0)/1000))     elapsed_sql,
		sum( executions) execs
		from response_times r, (select query_name,max(executions) m_execs from response_times where trial_nbr=:trial_nbr group by query_name) m
		where trial_nbr =:trial_nbr
		and executions=m_execs
		and r.query_name=m.query_name
		group by r.query_name
		order by r.query_name; */ 

	/* exec sql open c_p_r; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 44;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0058;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3903;
 sqlstm.selerr = (unsigned short)100;
 sqlstm.sqlpfmem = (unsigned int  )0;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&trial_nbr;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&trial_nbr;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)db_name;
 sqlstm.sqhstl[2] = (unsigned long )20;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	fetched_this_time = 50;
	cumulative_rows = 0;
	/* exec sql at :db_name select count(distinct pid||','||sid||','||instance)
	into :proc_count
	from runs_desc
	where trial_nbr=:trial_nbr; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 44;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( distinct pid || ',' || sid || ',' || instance\
 ) into :b1 from runs_desc where trial_nbr = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3930;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.sqlpfmem = (unsigned int  )0;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&proc_count;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&trial_nbr;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)db_name;
 sqlstm.sqhstl[2] = (unsigned long )20;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	printf("Results for Trial: %d\nAll Summed by query, except for 'Req' and 'All', where we take the MAX for each\n", trial_nbr);
	printf("Of the requested number of processes, %d got something to do\n", proc_count);
	printf("Elapsed, dbtime, In Queue and CPU times are all in milliseconds.\nReq and All are the number of requested PX servers, and the Allocated ones\n");
	printf("Gets, is the buffer gets in thousands, Same for Physical reads and writes.\nIntercon. Gives the volumes going thru the Interconnect, in GB\n");
	printf("Bytes Read and Written are also in GBytes.\nThe last 4 columns are the wait times, in milliseconds,for the four classes:Application, Concurrency, Cluster and I/Os respectevily\n");
	printf("--------------------------------------------------------------------------\n");
	printf("|query name                              |  Elapsed    | db time | Execs |\n");
	printf("|----------------------------------------|-------------|---------|-------|\n");
	for (; sqlca.sqlcode == 0;) {
		/* exec sql fetch c_p_r
			into :V_arr_query_name,:V_arr_elapsed_t,:V_arr_elapsed_time,:V_arr_executions; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3957;
  sqlstm.selerr = (unsigned short)100;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)V_arr_query_name;
  sqlstm.sqhstl[0] = (unsigned long )200;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&V_arr_elapsed_t;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&V_arr_elapsed_time;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&V_arr_executions;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)db_name;
  sqlstm.sqhstl[4] = (unsigned long )20;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		fetched_this_time = sqlca.sqlerrd[2] - cumulative_rows;
		cumulative_rows = sqlca.sqlerrd[2];
		if (sqlca.sqlcode==0) printf("|%-40s|%13d|%9d|%7d|\n",
				V_arr_query_name, V_arr_elapsed_t, V_arr_elapsed_time, V_arr_executions);
	}
	printf("--------------------------------------------------------------------------\n");
	/* exec sql close c_p_r; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 44;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3992;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)db_name;
 sqlstm.sqhstl[0] = (unsigned long )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (out_csv!=NULL){
		/* exec sql at :db_name declare c_p_ra cursor for
			select substr(r.query_name,1,40) query_name,
			elapsed_t wall_time,
			nvl(elapsed_time, 0),
			nvl(px_servers_requested, 0),
			nvl(px_servers_allocated, 0),
			executions execs,
			nvl(QUEUING_TIME, 0),
			nvl(CPU_TIME, 0),
			nvl(BUFFER_GETS, 0),
			nvl(IO_INTERCONNECT_BYTES, 0),
			nvl(PHYSICAL_READ_REQUESTS, 0),
			nvl(PHYSICAL_READ_BYTES, 0),
			nvl(PHYSICAL_WRITE_REQUESTS, 0),
			nvl(PHYSICAL_WRITE_BYTES, 0),
			nvl(APPLICATION_WAIT_TIME, 0),
			nvl(CONCURRENCY_WAIT_TIME, 0),
			nvl(CLUSTER_WAIT_TIME, 0),
			nvl(USER_IO_WAIT_TIME, 0),
			nvl(im_scans, 0),
			nvl(im_scan_bytes_uncompressed, 0)    ,
			nvl(IM_SCAN_BYTES_INMEMORY, 0)
			from response_times r, (select query_name,max(executions) m_execs from response_times where trial_nbr=:trial_nbr group by query_name) m
			where trial_nbr =:trial_nbr
			and executions=m_execs
			and r.query_name=m.query_name
			order by r.query_name; */ 

		/* exec sql open c_p_ra; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0060;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4011;
  sqlstm.selerr = (unsigned short)100;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&trial_nbr;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&trial_nbr;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)db_name;
  sqlstm.sqhstl[2] = (unsigned long )20;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		cumulative_rows=0;
		for (; sqlca.sqlcode == 0;) {
			/* exec sql fetch c_p_ra
				into :V_arr_query_name,:V_arr_elapsed_t,:V_arr_elapsed_time,:V_arr_px_servers_requested,:V_arr_px_servers_allocated,:V_arr_executions,:V_arr_QUEUING_TIME,
				:V_arr_CPU_TIME,:V_arr_BUFFER_GETS,:V_arr_IO_INTERCONNECT_BYTES,:V_arr_PHYSICAL_READ_REQUESTS,:V_arr_PHYSICAL_READ_BYTES,:V_arr_PHYSICAL_WRITE_REQUESTS,
				:V_arr_PHYSICAL_WRITE_BYTES,:V_arr_APPLICATION_WAIT_TIME,:V_arr_CONCURRENCY_WAIT_TIME,:V_arr_CLUSTER_WAIT_TIME,:V_arr_USER_IO_WAIT_TIME,:V_arr_IM_SCANS, :V_arr_IM_S_B_UNCOMP, :V_arr_IM_S_B_IMC; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4038;
   sqlstm.selerr = (unsigned short)100;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)V_arr_query_name;
   sqlstm.sqhstl[0] = (unsigned long )200;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&V_arr_elapsed_t;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&V_arr_elapsed_time;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&V_arr_px_servers_requested;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)0;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&V_arr_px_servers_allocated;
   sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)0;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&V_arr_executions;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)0;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&V_arr_QUEUING_TIME;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)0;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&V_arr_CPU_TIME;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)0;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&V_arr_BUFFER_GETS;
   sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)0;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&V_arr_IO_INTERCONNECT_BYTES;
   sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)0;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&V_arr_PHYSICAL_READ_REQUESTS;
   sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)0;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&V_arr_PHYSICAL_READ_BYTES;
   sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)0;
   sqlstm.sqinds[11] = (         int  )0;
   sqlstm.sqharm[11] = (unsigned long )0;
   sqlstm.sqadto[11] = (unsigned short )0;
   sqlstm.sqtdso[11] = (unsigned short )0;
   sqlstm.sqhstv[12] = (unsigned char  *)&V_arr_PHYSICAL_WRITE_REQUESTS;
   sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[12] = (         int  )0;
   sqlstm.sqindv[12] = (         short *)0;
   sqlstm.sqinds[12] = (         int  )0;
   sqlstm.sqharm[12] = (unsigned long )0;
   sqlstm.sqadto[12] = (unsigned short )0;
   sqlstm.sqtdso[12] = (unsigned short )0;
   sqlstm.sqhstv[13] = (unsigned char  *)&V_arr_PHYSICAL_WRITE_BYTES;
   sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[13] = (         int  )0;
   sqlstm.sqindv[13] = (         short *)0;
   sqlstm.sqinds[13] = (         int  )0;
   sqlstm.sqharm[13] = (unsigned long )0;
   sqlstm.sqadto[13] = (unsigned short )0;
   sqlstm.sqtdso[13] = (unsigned short )0;
   sqlstm.sqhstv[14] = (unsigned char  *)&V_arr_APPLICATION_WAIT_TIME;
   sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[14] = (         int  )0;
   sqlstm.sqindv[14] = (         short *)0;
   sqlstm.sqinds[14] = (         int  )0;
   sqlstm.sqharm[14] = (unsigned long )0;
   sqlstm.sqadto[14] = (unsigned short )0;
   sqlstm.sqtdso[14] = (unsigned short )0;
   sqlstm.sqhstv[15] = (unsigned char  *)&V_arr_CONCURRENCY_WAIT_TIME;
   sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[15] = (         int  )0;
   sqlstm.sqindv[15] = (         short *)0;
   sqlstm.sqinds[15] = (         int  )0;
   sqlstm.sqharm[15] = (unsigned long )0;
   sqlstm.sqadto[15] = (unsigned short )0;
   sqlstm.sqtdso[15] = (unsigned short )0;
   sqlstm.sqhstv[16] = (unsigned char  *)&V_arr_CLUSTER_WAIT_TIME;
   sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[16] = (         int  )0;
   sqlstm.sqindv[16] = (         short *)0;
   sqlstm.sqinds[16] = (         int  )0;
   sqlstm.sqharm[16] = (unsigned long )0;
   sqlstm.sqadto[16] = (unsigned short )0;
   sqlstm.sqtdso[16] = (unsigned short )0;
   sqlstm.sqhstv[17] = (unsigned char  *)&V_arr_USER_IO_WAIT_TIME;
   sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[17] = (         int  )0;
   sqlstm.sqindv[17] = (         short *)0;
   sqlstm.sqinds[17] = (         int  )0;
   sqlstm.sqharm[17] = (unsigned long )0;
   sqlstm.sqadto[17] = (unsigned short )0;
   sqlstm.sqtdso[17] = (unsigned short )0;
   sqlstm.sqhstv[18] = (unsigned char  *)&V_arr_IM_SCANS;
   sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[18] = (         int  )0;
   sqlstm.sqindv[18] = (         short *)0;
   sqlstm.sqinds[18] = (         int  )0;
   sqlstm.sqharm[18] = (unsigned long )0;
   sqlstm.sqadto[18] = (unsigned short )0;
   sqlstm.sqtdso[18] = (unsigned short )0;
   sqlstm.sqhstv[19] = (unsigned char  *)&V_arr_IM_S_B_UNCOMP;
   sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[19] = (         int  )0;
   sqlstm.sqindv[19] = (         short *)0;
   sqlstm.sqinds[19] = (         int  )0;
   sqlstm.sqharm[19] = (unsigned long )0;
   sqlstm.sqadto[19] = (unsigned short )0;
   sqlstm.sqtdso[19] = (unsigned short )0;
   sqlstm.sqhstv[20] = (unsigned char  *)&V_arr_IM_S_B_IMC;
   sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[20] = (         int  )0;
   sqlstm.sqindv[20] = (         short *)0;
   sqlstm.sqinds[20] = (         int  )0;
   sqlstm.sqharm[20] = (unsigned long )0;
   sqlstm.sqadto[20] = (unsigned short )0;
   sqlstm.sqtdso[20] = (unsigned short )0;
   sqlstm.sqhstv[21] = (unsigned char  *)db_name;
   sqlstm.sqhstl[21] = (unsigned long )20;
   sqlstm.sqhsts[21] = (         int  )0;
   sqlstm.sqindv[21] = (         short *)0;
   sqlstm.sqinds[21] = (         int  )0;
   sqlstm.sqharm[21] = (unsigned long )0;
   sqlstm.sqadto[21] = (unsigned short )0;
   sqlstm.sqtdso[21] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			fetched_this_time = sqlca.sqlerrd[2] - cumulative_rows;
			cumulative_rows = sqlca.sqlerrd[2];
			if (sqlca.sqlcode==0) fprintf(out_csv,"%s|%d|%d|%d|%d|%d|%d|%d|%d|%lf|%d|%lf|%d|%lf|%d|%d|%d|%d|%d|%d|%d\n",
					V_arr_query_name, V_arr_elapsed_t, V_arr_elapsed_time, V_arr_px_servers_requested, V_arr_px_servers_allocated,
					V_arr_executions, V_arr_QUEUING_TIME, V_arr_CPU_TIME, V_arr_BUFFER_GETS, V_arr_IO_INTERCONNECT_BYTES,
					V_arr_PHYSICAL_READ_REQUESTS, V_arr_PHYSICAL_READ_BYTES, V_arr_PHYSICAL_WRITE_REQUESTS, V_arr_PHYSICAL_WRITE_BYTES,
					V_arr_APPLICATION_WAIT_TIME, V_arr_CONCURRENCY_WAIT_TIME, V_arr_CLUSTER_WAIT_TIME, V_arr_USER_IO_WAIT_TIME,V_arr_IM_SCANS, V_arr_IM_S_B_UNCOMP, V_arr_IM_S_B_IMC);
		}
		/* exec sql close c_p_ra; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4141;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)db_name;
  sqlstm.sqhstl[0] = (unsigned long )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	}
	if (comp_trial_nbr!=0){
		/* printing a comp between 2 runs*/
		if (comp_trial_nbr==-1) /* exec sql at :db_name select nvl(max(trial_nbr),0)
								into :comp_trial_nbr
								from runs_desc
								where trial_nbr<:trial_nbr; */ 

{
                          struct sqlexd sqlstm;
                          sqlstm.sqlvsn = 13;
                          sqlstm.arrsiz = 44;
                          sqlstm.sqladtp = &sqladt;
                          sqlstm.sqltdsp = &sqltds;
                          sqlstm.stmt = "select nvl ( max ( trial_nbr ) , 0 \
) into :b1 from runs_desc where trial_nbr < :b2 ";
                          sqlstm.iters = (unsigned int  )1;
                          sqlstm.offset = (unsigned int  )4160;
                          sqlstm.selerr = (unsigned short)1;
                          sqlstm.sqlpfmem = (unsigned int  )0;
                          sqlstm.cud = sqlcud0;
                          sqlstm.sqlest = (unsigned char  *)&sqlca;
                          sqlstm.sqlety = (unsigned short)4352;
                          sqlstm.occurs = (unsigned int  )0;
                          sqlstm.sqhstv[0] = (unsigned char  *)&comp_trial_nbr;
                          sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                          sqlstm.sqhsts[0] = (         int  )0;
                          sqlstm.sqindv[0] = (         short *)0;
                          sqlstm.sqinds[0] = (         int  )0;
                          sqlstm.sqharm[0] = (unsigned long )0;
                          sqlstm.sqadto[0] = (unsigned short )0;
                          sqlstm.sqtdso[0] = (unsigned short )0;
                          sqlstm.sqhstv[1] = (unsigned char  *)&trial_nbr;
                          sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                          sqlstm.sqhsts[1] = (         int  )0;
                          sqlstm.sqindv[1] = (         short *)0;
                          sqlstm.sqinds[1] = (         int  )0;
                          sqlstm.sqharm[1] = (unsigned long )0;
                          sqlstm.sqadto[1] = (unsigned short )0;
                          sqlstm.sqtdso[1] = (unsigned short )0;
                          sqlstm.sqhstv[2] = (unsigned char  *)db_name;
                          sqlstm.sqhstl[2] = (unsigned long )20;
                          sqlstm.sqhsts[2] = (         int  )0;
                          sqlstm.sqindv[2] = (         short *)0;
                          sqlstm.sqinds[2] = (         int  )0;
                          sqlstm.sqharm[2] = (unsigned long )0;
                          sqlstm.sqadto[2] = (unsigned short )0;
                          sqlstm.sqtdso[2] = (unsigned short )0;
                          sqlstm.sqphsv = sqlstm.sqhstv;
                          sqlstm.sqphsl = sqlstm.sqhstl;
                          sqlstm.sqphss = sqlstm.sqhsts;
                          sqlstm.sqpind = sqlstm.sqindv;
                          sqlstm.sqpins = sqlstm.sqinds;
                          sqlstm.sqparm = sqlstm.sqharm;
                          sqlstm.sqparc = sqlstm.sqharc;
                          sqlstm.sqpadto = sqlstm.sqadto;
                          sqlstm.sqptdso = sqlstm.sqtdso;
                          sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if (comp_trial_nbr>0) /* there is one */
		{
			char VRatio[10];
			/* exec sql at :db_name declare comp_c cursor for
			    select substr(a.query_name,1,40),round(a.elapsed_time/1000/a.executions) Elapsed1, round(b.elapsed_time/1000/b.executions), 
			    case when b.elapsed_time=0 or a.elapsed_time=0 then 'NA' 
			    	 when a.elapsed_time/a.executions>b.elapsed_time/b.executions then 'S'|| to_char(a.elapsed_time*b.executions/b.elapsed_time/a.executions,'9999.99')
			    	 else 'F'||to_char(b.elapsed_time/a.elapsed_time,'9999.99') 
			    	 end 
				from response_times a, response_times b
				where a.trial_nbr=:trial_nbr
				and b.trial_nbr=:comp_trial_nbr
				and a.query_name=b.query_name
				order by a.query_name; */ 

			/* exec sql at :db_name select substr(b.description,1,30)
			    into :V_arr_query_name
				from runs_desc b
				where b.trial_nbr=:comp_trial_nbr
				and rownum=1; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "select substr ( b . description , 1 , 30 ) into :b1 from r\
uns_desc b where b . trial_nbr = :b2 and rownum = 1 ";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4187;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)V_arr_query_name;
   sqlstm.sqhstl[0] = (unsigned long )200;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&comp_trial_nbr;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)db_name;
   sqlstm.sqhstl[2] = (unsigned long )20;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			/* exec sql open comp_c; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = sq0062;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4214;
   sqlstm.selerr = (unsigned short)100;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqcmod = (unsigned int )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&trial_nbr;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&comp_trial_nbr;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)db_name;
   sqlstm.sqhstl[2] = (unsigned long )20;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			printf("Comparing runs %d (%s) and %d (%s), Showing elapsed times and ratio: F means first is fatser, S means it is Slower \n", trial_nbr,run_desc, comp_trial_nbr, V_arr_query_name);
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|query name                              |%-30s|%-30s|  Ratio  |\n",run_desc,V_arr_query_name);
			printf("|----------------------------------------|------------------------------|------------------------------|---------|\n");
			
			for (;sqlca.sqlcode==0;) {
				/* exec sql fetch comp_c into :V_arr_query_name, :V_arr_elapsed_t, :V_arr_elapsed_time,:VRatio; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 44;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4241;
    sqlstm.selerr = (unsigned short)100;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)V_arr_query_name;
    sqlstm.sqhstl[0] = (unsigned long )200;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&V_arr_elapsed_t;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&V_arr_elapsed_time;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)VRatio;
    sqlstm.sqhstl[3] = (unsigned long )10;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)db_name;
    sqlstm.sqhstl[4] = (unsigned long )20;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				if (sqlca.sqlcode==0) printf("|%-40s|                %14d|                %14d|%-9s|\n",V_arr_query_name, V_arr_elapsed_t,V_arr_elapsed_time, VRatio);
			}
			printf("------------------------------------------------------------------------------------------------------------------\n");
		}
	}
		if (strcmp(db_name,"perf_db")==0) {
			/* exec sql at :db_name commit work release; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4276;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)db_name;
   sqlstm.sqhstl[0] = (unsigned long )20;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			my_print("log off from %s",db_name);
		}
}

void handle_awrs(
	char *username,
	int begin_snap_id,
	char *awr_instances,
	int trial_nbr)
{
	long    dbid, end_snap_id;
	int     instance_id, i, nbr_of_instances, print_global,
		fetched_this_time, cumulative_rows, j,
		arr_instance_ids[500];
	short   awr_indicators;
	char   *inst_id, file_name[MAX_FILENAME_SIZE], awr_lines[1501],
		*str;
	FILE   *out_file;
	/* EXEC SQL WHENEVER SQLERROR GOTO proc_error_awr; */ 

	/* exec sql at main_db select dbms_workload_repository.create_snapshot, dbid
		into :end_snap_id, :dbid
		from v$database; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 44;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select dbms_workload_repository . create_snapshot , dbid int\
o :b0 , :b1 from v$database ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4295;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.sqlpfmem = (unsigned int  )0;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&end_snap_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&dbid;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto proc_error_awr;
}


	j=sqlca.sqlcode;
	if (debug&1)
		my_print("got dbid=%ld, end_snap_id=%ld\n", dbid, end_snap_id);
	/* loop on all specified instances */
	if (awr_instances[0] == 'N' || awr_instances[0] == 'n') {
		printf("AWR snapshots taken are: %d and %ld (sqlerr=%d)\n", begin_snap_id, end_snap_id,j);
		return;
	}
	if (awr_instances[0] == 'A' || awr_instances[0] == 'a') {
		/* exec sql at main_db select inst_id
		into :arr_instance_ids
		from gv$instance; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select inst_id into :b0 from gv$instance ";
  sqlstm.iters = (unsigned int  )500;
  sqlstm.offset = (unsigned int  )4325;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)arr_instance_ids;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto proc_error_awr;
}


		nbr_of_instances = sqlca.sqlerrd[2] - 1;
		print_global = 1;
	} else {		/* get list using strtok */

		for (i = 0, str = awr_instances;; str = NULL) {
			inst_id = strtok(str, ",");
			if (inst_id == NULL)
				break;
			if (debug&1)
				my_print("awr_instances=%s, inst_id=%s i=%d\n", awr_instances, inst_id, i);
			if (inst_id[0] == 'G' || inst_id[0] == 'g')
				print_global = 1;
			else
				arr_instance_ids[i++] = atoi(inst_id);
		}
		nbr_of_instances = i - 1;
	}
	/* print global report */
	if (print_global == 1) {
		/* exec sql at main_db declare cur_get_glob_awr cursor for
			select output
			from table( dbms_workload_repository.awr_global_report_html(:dbid,
							'',
							:begin_snap_id,
							:end_snap_id)); */ 

		/* exec sql open cur_get_glob_awr; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0067;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4351;
  sqlstm.selerr = (unsigned short)100;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&dbid;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&begin_snap_id;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&end_snap_id;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto proc_error_awr;
}


		fetched_this_time = 50;
		cumulative_rows = 0;
		sprintf(file_name, "awr_report_global_%d_%ld_%d.html",
			begin_snap_id, end_snap_id, trial_nbr);
		out_file = fopen(file_name, "w");
		if (out_file == NULL) {
			printf("Cannot open file %s\n", file_name);
			return;
		}
		/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

		for (;sqlca.sqlcode == 0;) {
			/* exec sql fetch cur_get_glob_awr
				into :awr_lines:awr_indicators; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4385;
   sqlstm.selerr = (unsigned short)100;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)awr_lines;
   sqlstm.sqhstl[0] = (unsigned long )1501;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&awr_indicators;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			if (debug == 1)
				my_print("fetching global awr lines =%d sqlca.sqlcode=%d\n", sqlca.sqlerrd[2], sqlca.sqlcode);
			fetched_this_time =
				sqlca.sqlerrd[2] - cumulative_rows;
			cumulative_rows = sqlca.sqlerrd[2];
			if (awr_indicators == 0&&sqlca.sqlcode==0)
					fprintf(out_file, "%s\n",
						awr_lines);
		}
		/* exec sql close cur_get_glob_awr; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4411;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		fclose(out_file);
	}
	/* EXEC SQL WHENEVER SQLERROR GOTO proc_error_awr; */ 

	/* exec sql at main_db declare cur_get_awr cursor for select output from table(
	dbms_workload_repository.awr_report_html(:dbid,
						 :instance_id,
						 :begin_snap_id,
						 :end_snap_id)); */ 

	for (i = 0; i <= nbr_of_instances; i++) {
		instance_id = arr_instance_ids[i];
		/* exec sql open cur_get_awr; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0068;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4433;
  sqlstm.selerr = (unsigned short)100;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&dbid;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&instance_id;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&begin_snap_id;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&end_snap_id;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto proc_error_awr;
}


		fetched_this_time = 50;
		cumulative_rows = 0;
		sprintf(file_name, "awr_report_%d_%d_%ld_%d.html",
			instance_id, begin_snap_id, end_snap_id,
			trial_nbr);
		out_file = fopen(file_name, "w");
		if (out_file == NULL) {
			printf("Cannot open file %s\n", file_name);
			return;
		}
		/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

		for (;sqlca.sqlcode == 0;) {
			/* exec sql fetch cur_get_awr
				into :awr_lines:awr_indicators; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4471;
   sqlstm.selerr = (unsigned short)100;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)awr_lines;
   sqlstm.sqhstl[0] = (unsigned long )1501;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&awr_indicators;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			if (debug&1)
				my_print("fetching awr lines =%d sqlca.sqlcode=%d\n", sqlca.sqlerrd[2], sqlca.sqlcode);
			fetched_this_time =
				sqlca.sqlerrd[2] - cumulative_rows;
			cumulative_rows = sqlca.sqlerrd[2];
			if (awr_indicators == 0&&sqlca.sqlcode==0)
					fprintf(out_file, "%s\n",
						awr_lines);
		}
		/* exec sql close cur_get_glob_awr; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4497;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		fclose(out_file);
	}
	return;
    proc_error_awr:
		printf("Got error in handle_awrs, sqlcode=%d\n", sqlca.sqlcode);
		if (out_file!=NULL) fclose(out_file);
		return;
}

int fork_proc(
	int cnt,
	char *username,
	char *master_ip,
	int   master_port,
	int   sqlid_port)
{
	int     pid, yourid = cnt, bw, errn;
	int	master_socket,debug_level=1<<13;
	char saved_function_name[50];
	pid = fork();
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"fork_proc");
	if (pid == (pid_t) 0) {
		/* This is the child process. Close our copy of the read end of main pipe
		   and the write end of our pipe. then we open for read our pipe, and for write the main pipe
		   */
		mypid = getpid();
		debug_file=NULL;
		sleep(5); // we sleep 5 seconds to allow forking of all processes and then we try to connect to the master
		if ((master_socket=open_socket_to_master(master_ip,master_port))<0){
			printf("could not connect to specified master %s, on port %d, if it is not yet started, please do so and restart\n", master_ip, master_port);
			strcpy(function_name,saved_function_name);
			return (-1);
		}
		if (separate_process_sqlid>0)
		   if ((sqlid_socket=open_socket_to_master(master_ip,sqlid_port))<0){
			printf("could not connect to specified sqlid server %s, on port %d, if it is not yet started, please do so and restart\n", master_ip, sqlid_port);
			strcpy(function_name,saved_function_name);
			return (-1);
		}
		if (debug&debug_level)
			my_print("in pid=%d, opened sockets %d and %d to master\n", mypid, master_socket, sqlid_socket);
		query_name[0]=file_name[0]=stop_file_name[0]=bind_file_name[0]=exec_stats_file_name[0]=log_file_name[0]=dyn_statement[0]=setup_script[0]='\0';
		global_socket=master_socket;
		while (1) {
		switch (get_master_message
		       (master_socket, 10000000)) {
			case 1: break;
			case 4: send_msg_to_master(master_socket,"X\n");
				/* exec sql at main_db commit work release; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 44;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4519;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				/* exec sql at :db_name commit work release; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 44;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4541;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)db_name;
    sqlstm.sqhstl[0] = (unsigned long )20;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				my_print("process %d will exit\n",mypid);
				strcpy(function_name,saved_function_name);
				if (debug_file!=NULL) fclose(debug_file);
				exit(EXIT_FAILURE);
			case 0: send_msg_to_master(master_socket,"X\n");
				/* exec sql at main_db commit work release; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 44;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4560;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				/* exec sql at :db_name commit work release; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 44;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4582;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)db_name;
    sqlstm.sqhstl[0] = (unsigned long )20;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				my_print("process %d will exit\n",mypid);
				strcpy(function_name,saved_function_name);
				if (debug_file!=NULL) fclose(debug_file);
				exit(EXIT_FAILURE);
			case 3: break;
			case 2:bw = processing_thread();
					if (debug&debug_level)
						my_print("process %d returned for query %s\n", mypid,query_name);
				break;
			}
			send_msg_to_master(master_socket,"F\n");
			if (debug&debug_level)
				my_print("process %d sent message to master to say we're ready\n",mypid);
		}
	} else {
		process_busy[cnt] = 0;
		if (debug&debug_level)
			my_print("process %d was forked (processing SQL)",pid);
	}
	strcpy(function_name,saved_function_name);
	return (-1);
}

void start_processes(
	char *username,
	int degree,
	char *master_ip,
	int master_port)
{
	int     cnt, id,debug_level=1<<14;
	char saved_function_name[50];
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"start_processes");

	/* start by creating the pipe on which we will receive the messages from the different processes */
	if (debug&debug_level)
		my_print("starting processes %d, \n",degree);
	/* Fork a child process.  */
	for (cnt = 0; cnt < degree; cnt++) {
		id = fork_proc(cnt,  username, master_ip, master_port, sqlid_port);
		if (id > -1) {
			//my_print("process %d (pid=%d) will exit\n", id);
			exit(0);
		}
		if (debug&debug_level)
			my_print("forked process for %d, pid=%d \n", cnt,id);
	}
	//sleep(1);
	if (debug&debug_level)
		my_print("main, forked all processes, will exit %d\n");
	strcpy(function_name,saved_function_name);
}
int fork_process_sqlid(char *master_ip, int socket_sqlid, int degree, char *username)
{
	fd_set inc_set, act_set;
	struct sockaddr_in server_sqlid , client;
	struct timeval tv;
	char saved_function_name[50], buffer[20],msg_to_send[20],*s,*p;
	int pid,c, i=0, something_set,debug_level=1<<14, *sockets_sqlid,returned,ret_bytes;
	pid=fork();
	if (pid!= (pid_t) 0) return (pid);
	mypid=getpid();
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"fork_process_sqlid");
	if (debug&debug_level)
		my_print("starting sql listener, on port %d, ip %s, and for  %d processes, \n",sqlid_port, master_ip,degree);
	server_sqlid.sin_family = AF_INET;
	server_sqlid.sin_addr.s_addr = INADDR_ANY;
	server_sqlid.sin_port = htons( sqlid_port );
	socket_sqlid = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_sqlid == -1)
	{
		my_print("Could not create socket for sqlid");
		exit(EXIT_FAILURE);
	}


	//Bind
	if( bind(socket_sqlid,(struct sockaddr *)&server_sqlid , sizeof(server_sqlid)) < 0)
	{
		perror("bind to socket for sqlid failed with error");
		my_print("bind to socket failed on port %d\n",sqlid_port);
		exit(EXIT_FAILURE);
	}
	/* exec sql connect :username at main_db; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 44;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )10;
 sqlstm.offset = (unsigned int  )4601;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)username;
 sqlstm.sqhstl[0] = (unsigned long )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlstm.sqlcmax = (unsigned int )100;
 sqlstm.sqlcmin = (unsigned int )2;
 sqlstm.sqlcincr = (unsigned int )1;
 sqlstm.sqlctimeout = (unsigned int )0;
 sqlstm.sqlcnowait = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	c = sizeof(struct sockaddr_in);
	sockets_sqlid=(int *)malloc(degree*sizeof(int));

	// now we'll wait for degree processes to connect
	while (degree>i) {
		FD_ZERO(&act_set);
		listen(socket_sqlid , 100);
		FD_SET(socket_sqlid,&act_set);
		inc_set=act_set;
		if (debug&debug_level)
			my_print("waiting to get connection %d demands, already got %d, \n",degree,i);

		tv.tv_sec = 30;
		tv.tv_usec = 0;
		returned = select(FD_SETSIZE, &inc_set, NULL, NULL, &tv);
		if (debug&debug_level)
			my_print("returned from select, returned=%d\n",returned);

		if (returned) {
		    // got a request, so connect it
		    sockets_sqlid[i++] = accept(socket_sqlid, (struct sockaddr *)&client, (socklen_t*)&c);
		    my_print("got connection nbr %d from %s\n",i-1,inet_ntoa(client.sin_addr));
		} else {
		    my_print("waited 5 minutes, not all arrived, will quit\n");
			strcpy(function_name,saved_function_name);
		    exit(EXIT_FAILURE);
		}
	}
	something_set=1;
	while (something_set>0) {
		FD_ZERO(&act_set);
		FD_ZERO(&inc_set);
		something_set=0;
		for (i=0;i<degree;i++)
			if (sockets_sqlid[i]!=-1) {
				FD_SET(sockets_sqlid[i],&act_set);
				something_set=1;
			}
		if (debug&debug_level)
			my_print("waiting for a processes among %d to ask for sqlid\n",degree);
		inc_set=act_set;
		tv.tv_sec=10;
		tv.tv_usec=0;
		returned=0;
		if (something_set>0) returned=select(FD_SETSIZE,&inc_set,NULL,NULL,&tv);
		if (returned) { // returned>0 means there's something to read
			if (debug&debug_level)
				my_print("someone asked for sqlid, returned=%d",returned);
			for (i=0;i<degree;i++){
				if (FD_ISSET(sockets_sqlid[i],&inc_set)){
					if (debug&debug_level)
						my_print("reading from socket nbr %d\n",i);
					ret_bytes = recv(sockets_sqlid[i], buffer, sizeof(buffer),0);
					if (debug&debug_level)
						my_print("got a message from socket %d, message %s of len %d\n",i,buffer,ret_bytes);
					if (ret_bytes<3) {
						// remove the socket, as this means that the process on the other end is not there anymore
							sockets_sqlid[i]=-1;
							my_print("removing socket nbr %d",i);
						}
					else {
						buffer[ret_bytes]='\0';
						s=strchr(buffer,'=');
						if (debug&debug_level&&s!=NULL)
							my_print("got a message from socket with s= %s\n",s);
						s++;
						p=strchr(s,';');
						*p='\0';
						p++;
						mysid=(int) atol(s);
						myinstance=(int)atol(p);
						if (debug&debug_level)
							my_print("got a message for sqlid from sid=%d and instance=%d",mysid,myinstance);
						/* exec sql at main_db select nvl(sql_id,'NULL')||';'||nvl(sql_child_number,0)
						into :msg_to_send
						from gv$session
						where sid=:mysid and inst_id=:myinstance; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 13;
      sqlstm.arrsiz = 44;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select nvl ( sql_id , 'NULL' ) || ';' || nvl ( sql_chil\
d_number , 0 ) into :b0 from gv$session where sid = :b1 and inst_id = :b2 ";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )4639;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.sqlpfmem = (unsigned int  )0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)msg_to_send;
      sqlstm.sqhstl[0] = (unsigned long )20;
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&mysid;
      sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&myinstance;
      sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


						if (debug&debug_level)
							my_print("sent a message to socket %d, message %s, sqlca.sqlcode=%d\n",sockets_sqlid[i],msg_to_send, sqlca.sqlcode);
						sendall(sockets_sqlid[i], msg_to_send,strlen(msg_to_send));
					}
				}
			}
			returned=0;
		}
/*		if (asked_to_quit()) {
			exec sql at main_db commit work release;
			my_print("sqlid process is quitting");
			strcpy(function_name,saved_function_name);
			exit(0);
		}
*/	}
	if (debug&debug_level)
		my_print("run seems to have finished, quitting");
	/* exec sql at main_db commit work release; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 44;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4673;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	exit(0);	
}
int setup_master(char *master_ip, int master_port, int nbr_clients, int degree, char *username, int is_multi_machine)
{
	// this function will start listening on the given port, and will wait, up to 5 minutes,
	// for the administrator to start all the remote processes.
	// it returns the number of sockets opened, which should be equal to nbr_of_machines
	int socket_desc , debug_level=1<<14,new_socket , c , *new_sock, socket_sqlid;
	struct sockaddr_in server , client, server_sqlid;
	fd_set inc_set, act_set;
	char saved_function_name[50];
	struct timeval tv;
	int retval, i;
	strcpy(saved_function_name,function_name);
	strcpy(function_name,"setup_master");

	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		my_print("Could not create socket");
		exit(EXIT_FAILURE);
	}

	//Prepare the sockaddr_in structure
	// for this first version, we listen on all ips
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( master_port );

	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("bind to socket failed with error");
		my_print("bind to socket failed on port %d\n",master_port);
		exit(EXIT_FAILURE);
	}
/*	
*/
	if (separate_process_sqlid>0) sqlid_proc=fork_process_sqlid(master_ip, socket_sqlid,degree, username);
	else sqlid_proc=0;
	if (debug&debug_level)
		my_print("forked sqlid processor with pid= %d, \n",sqlid_proc);
	//Listen
	//Accept and incoming connection
	if (is_multi_machine==1){
		my_print("Waiting for incoming connections, please start the remote processes, process will wait maximum 5 minutes \n");
		my_print("for all connections, and will wait at most 30 seconds between any 2 consecutive, nbr_clients=%d  \n", nbr_clients);
	}
	c = sizeof(struct sockaddr_in);

	int time_waited=0, returned=0;
	i=0;
	while (nbr_clients>i && time_waited<301) {
		FD_ZERO(&act_set);
		listen(socket_desc , 100);
		FD_SET(socket_desc,&act_set);
		inc_set=act_set;

		tv.tv_sec = 30;
		tv.tv_usec = 0;

		returned = select(FD_SETSIZE, &inc_set, NULL, NULL, &tv);
		time_waited+=30;

		if (returned) {
		    // got a request, so connect it
		    sockets_list[i++] = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
		    my_print("got connection from remote machine=%s\n",inet_ntoa(client.sin_addr));
		} else if (time_waited>301){
		    my_print("waited 5 minutes, not all arrived, will quit\n");
		    close(socket_desc);
		    exit(EXIT_FAILURE);
		}
	}
	int deg1=degree, rem_deg;

	if (nbr_clients>0) {
		if (degree==nbr_clients*((int) degree/nbr_clients)) deg1=(int)floor(degree/(nbr_clients+1)*1.0);
		else deg1=(int)floor(degree/nbr_clients*1.0);
		int rem_deg=degree-deg1;
		for (i=0;i<nbr_clients;i++) {
			if (debug&debug_level)
				my_print("sending message to remote nbr %d, to start %d processes \n",i, (i==(nbr_clients-1))?rem_deg:deg1);
			sprintf(dyn_statement,"start=%d\n",(i==(nbr_clients-1))?rem_deg:deg1);
			sendall(sockets_list[i],dyn_statement,strlen(dyn_statement));
			rem_deg-=deg1;
		}
	} else nbr_clients=1;
		//Accept and incoming connection
	c = sizeof(struct sockaddr_in);
	i=0;
	start_processes (username, deg1, master_ip, master_port);
	if (debug&debug_level)
		my_print("started processes %d, \n",(int)ceil(1.0*degree/nbr_clients));
	while (degree>i) {
		FD_ZERO(&act_set);
		listen(socket_desc , 100);
		FD_SET(socket_desc,&act_set);
		inc_set=act_set;
		if (debug&debug_level)
			my_print("waiting to get connection %d demands, already got %d, \n",degree,i);

		tv.tv_sec = 30;
		tv.tv_usec = 0;
		int returned = select(FD_SETSIZE, &inc_set, NULL, NULL, &tv);
		if (debug&debug_level)
			my_print("returned from select, returned=%d\n",returned);

		if (returned) {
		    // got a request, so connect it
		    sockets_listf[i] = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
		    process_busy[i++]=0;
		    my_print("got connection nbr %d from %s\n",i,inet_ntoa(client.sin_addr));
		} else {
		    my_print("waited 5 minutes, not all arrived, will quit\n");
		    exit(EXIT_FAILURE);
		}
	}
	strcpy(function_name,saved_function_name);
	return (i);
}

int oracle_connect(
	int argc,
	char *argv[])
{
	int     got_to_quit,nbr_partitions, get_more_part, ln, nbr_processes,
		sleep_time, wait_pid,debug_level=1<<15,
		awr_create, begin_snap_id, end_snap_id, exec_all_in_file,finished,ret_code;
	long    ramp_up_time, ramp_up_remains,ramp_up_time_remain;
	char   *argument, *argument1,
		v_add_monitor_hint[20], out_csv_fname[513];
	char    line[MAX_LINE_SIZE], wait_string[200],
		parfilename[MAX_FILENAME_SIZE], awr_instances[1023], master_ip[50];
	char   *cptr, **cptr1;
	int     proc_num, serial_num;
	FILE   *parfile, *sqlf, *pincfile;
	struct timeval ctime;
	int     i, prc_id, 
		linenbr, i_am_master, master_port, master_socket;
	sleep_time = 1;
	got_to_quit=0;
	strcpy(v_add_monitor_hint, " ");
	comma_len = degree = 1;
	mypid = getpid();
	print_my_stats = 0;
	print_pga_stats = 0;
	ramp_up_time = 0;
	awr_instances[0] = 'N';
	exec_stats_file_name[0]='\0';
	bind_file_name[0]='\0';
	proc_num = serial_num = 0;
	/* EXEC SQL WHENEVER SQLERROR GOTO connect_error; */ 

	out_array_size = MAX_ARRSZ;
	awr_create = 0;
	max_time=0;
	file_name[0]='\0';
	strcpy(dyn_statement, " ");
	setup_script[0]='\0';
	username[0] = ' ';
	strcpy(function_name,"oracle_connect");
	strncpy(program_name,argv[0],50);
	if (argc <= 2 || !strncasecmp(argv[1], "help", 4)) {
		printf("%s POC tool"
"\nPurpose:	%s is a tool that is used for simulating a workload on a Oracle database."
"\nusage:		%s { HELP|{{parfile=parameter_file_name userid=user/password@service nbr_of_processes=...} master_ip=xxx.xxx.xxx.xxx master_port=n number_of_machines=x sep_process_sqlid=Y/n}"
"\n	parfile=              name of the parameters files, it contains the scenario for the bench"
"\n	userid=               is the one used to connect to the database, if no service is provided, the ORACLE_SID is used"
"\n	nbr_of_processes=     gives the total number of processes that will be used, on all machines, to execute the queries"
"\n	master_ip=            gives the ip on which the master process will be listening and will communicate with other "
"\n			      contributing machines"
"\n	master_port=          gives the port number to use, be sure it is available"
"\n	number_of_machines=   gives the number of contributing machines. The master process will wait for these machines "
"\n	                      to connect before continuing"
"\n sep_process_sqld=Y/N  tells the system to start a separate process to get the sqlid, should be used when cursor_sharing=force"
"\n                       as in that case the sqlid depends on bind variable replacement done by the optimizer"
"\n	out_csv=			  name of a file where the response times will be written at the end, in a | separated format"
"\n	"
"\n	You use the the last master_port, master_ip and number_of_machines parameters when you have multiple machines contributing to the benchmark."
"\n	Please refer to the twiki page on the RWP web for more info."
"\n	For the contributing machines, you do not have to specify parfile and userid, but the other parameters must be specified"
"\n	you have 5 minutes to start these processes once you started the master one. They can be started before"
"\n	you have to specify the parfile and the userid for the master program"
"\n	a description of the contents of the parfile is given below"
"\n	When fetching data, the programs usses arrays of size of 500 "
"\n	MAX char column length is 500 "
"\n	Max number of columns is 1000 "
"\n	The system uses a set of tables to track performance of queries. The main one is RESPONSE_TIMES, and it looks like this:"
"\n	CREATE TABLE RESPONSE_TIMES"
"\n	   (	query_name VARCHAR2(200),"
"\n		process_id number,"
"\n		Inst_id number,"
"\n		trial_nbr number,"
"\n		sql_id	varchar2(20),"
"\n		child_nbr	number,"
"\n		exec_id number,"
"\n		rows_p number,"
"\n		elapsed_t number,"
"\n		time_st timestamp,"
"\n		IO_CELL_OFFLOAD_ELIGIBLE_BYTES NUMBER,"
"\n		PX_IS_CROSS_INSTANCE  char(1),"
"\n		px_servers_requested  number,"
"\n		px_servers_allocated  number,"
"\n		ELAPSED_TIME		 NUMBER,"
"\n		QUEUING_TIME		 NUMBER,"
"\n		CPU_TIME		 NUMBER,"
"\n		FETCHES			 NUMBER,"
"\n		BUFFER_GETS		 NUMBER,"
"\n		DISK_READS		 NUMBER,"
"\n		DIRECT_WRITES		 NUMBER,"
"\n		IO_INTERCONNECT_BYTES	 NUMBER,"
"\n		PHYSICAL_READ_REQUESTS	 NUMBER,"
"\n		PHYSICAL_READ_BYTES	 NUMBER,"
"\n		PHYSICAL_WRITE_REQUESTS	 NUMBER,"
"\n		PHYSICAL_WRITE_BYTES	 NUMBER,"
"\n		APPLICATION_WAIT_TIME NUMBER,"
"\n		CONCURRENCY_WAIT_TIME NUMBER,"
"\n		CLUSTER_WAIT_TIME     NUMBER,"
"\n		USER_IO_WAIT_TIME     NUMBER,"
"\n		PLSQL_EXEC_TIME	      NUMBER,"
"\n		JAVA_EXEC_TIME	      NUMBER,"
"\n		bind_file_line_nbr	number,"
"\n		IM_SCANS                            NUMBER,"
"\n		IM_SCAN_BYTES_UNCOMPRESSED          NUMBER,"
"\n		IM_SCAN_BYTES_INMEMORY              NUMBER)"
"\n	Most of the columns are taken from v$sql_monitor, they will be null is the statement was not monitored."
"\n	Another table used is runs_desc (create table runs_desc (trial_nbr number, pid number, time_stamp_beg timestamp, "
"\n	        time_stamp_end timestamp, sid number, instance number,bind_file_name VARCHAR2(512), host_name varchar2(256));"
"\n		it is used to note when each process started, and when it finished."
"\n	The query_name is to be specified as a parameter in the parameter file"
"\n	rows_p is the number of rows in the output file"
"\n	elapsed_t is the elapsed time as registered by the program (in microseconds)"
"\n	time_st is a start time taken from SYSTIMESTAMP"
"\n	some columns are taken from V$SQL"
"\n	These are used for benchmarking purposes"
"\n	The parameter file can have the following entries(they are case insensitive): "
"\n	query name=	gives a name to the query (see above)"
"\n	PRINT PLAN STATS= if Y/y then the program will print to the log file statistics from V$SQL as well as the execution plan"
"\n	sqlmonitor=	if N/n then the program will not print to a file named query_name_trial_nbr.html the sqlmonitor report"
"\n	                by default, the report is of type 'ACTIVE'. If you pout here any integer value X>0, then all queries with an elapsed_time"
"\n	                >X will have it's active report printed. If you want any other type of report, you put the value here, and it will be printed for all queries"
"\n	add monitor hint=     if Y/y then the program will add a monitor hint when it generates the SQL statement"
"\n			      this is applicable only when you specify a table name in the sql= parameter"
"\n	awr snapshots=Y/y/nbr take awr snapshots before and after starting the runs, snapshot ids will be printed at the end."
"\n			      you can also specify a number, which will mean that rwpbench will take also snapshots "
"\n			      at the specified interval (in seconds)"
"\n	awr reports= this can take several values: N/n no reports produced, G/g means global report will be printed"
"\n			comma-separated list of instances: produce an awr for each one of the instances, the list can include G"
"\n			e.g. 1,2,3,4,G. Report names will be awr_report_inst_id/global_start_snap_end_snap_trial_nbr.html"
"\n	rows to fetch=	 This is used to limit the number of rows fetched for each query. Useful when the query can "
"\n			return millions of rows, thus making the fetch time longer than the actual execution time."
"\n	silent=		if set to N or n, then no progress messages will be printed. "
"\n	think time min=	    lower bound on think time, in seconds"
"\n	think time max=	    upper bound on think time, in seconds"
"\n	release px wa=  Y/y tells rwpbench to open the main cursor with a dummy sql just to release the px slaves"
"\n	print my stats= Y/y to print the non-zero values of v$mystat at then end of each process, before logging out "
"\n	print pga stats=	Y/y to print the PGA data from v$process. They will be printed to the log file, after each SQL"
"\n	flush bc=	if Y/y do an 'alter system flush buffer_cache' immediatly"
"\n	flush sp=	if Y/y do an 'alter system flush shared_pool' immediatly"
"\n	sqlset=		the name of an existing sqlset to which the executed queries will be added"
"\n	trial nbr=	the number of the run, used mainly with the response_times table. "
"\n	                if = N/n then the max from that table is taken and incrementd"
"\n	user name=	the username to be used by the forked processes, IT REPLACES the one specified on the command line,"
"\n	                FOR ALL THE CONNECTIONS FROM THERE ON"
"\n	file=		the file name where to store the results of the sql that is specified after this line "
"\n			it can be either a 'normal' file name, or contain a %%d, which will be replaced by the pid of the process"
"\n	bind file separator=	the character to be used a a field separator in the bind file defaults to a pipe '|'"
"\n	bind file=	the name of a file containing bind values for the query that follows this line"
"\n			the first line of the file must contain a '|'-separated list (or what is specified by the bind file separator param)"
"\n			of bind variable names and types like this: V1:INTEGER|V2:NUMBER|V3:CHAR"
"\n			The values start at line 2, and should also be separated by '|' or what is specified by bind file separator"
"\n	bind send results to host= name of a host on which a receiving program will read the execution data from a socket"
"\n	bind send results to port= port number on which the receiving program will be listening"
"\n	bind results to db= Y/y will insert the results for bind executions into the db (into response_times, "
"\n	                    but only a subset of the columns is filled)"
"\n	exec stats file= prefix for the name of a file where execution stats will be written, in csv format . The file name"
"\n			will get suffixed by the process_id. It can be used to load the results in a separate db."
"\n			the data is : trial_nbr;query_name;process_id;start_timestamp(microsecond since epoch);"
"\n			elapsed_time (microsecs);row_count;line in bind file"
"\n	stop filename= name of the file that will be checked regularly. If it exists, the program will exit."
"\n	save mystats=  Y/y. Makes the program save the value of the statistics that changed between start and end of sql execution"
"\n	use dbms_sqltune0=Y/y: tells the porogram to use dbms_sqltune0.sqltext_to_id to get the sql_id, otherwise, it will use a C routine to do so."
"\n	                       use this flag if the user does have exec privs on dbms_sqltune0 and you find issues with the computed id"
"\n	                       As the C routine was only tested on an x86 system, it may not work on sparc, ibm...systems"
"\n	log file=	the name of the log file, can contain a %%d. %%d will be replaced by the process id"
"\n	max time=	If >0 then the following query will be executed several times, until the indicated value, in seconds, expires."
"\n	exec count=	How many times a query should be executed, defaults to 1"
"\n	compare trial nbr=	Compare current trial to this one. P/p means the previous one"
"\n	ramp up time=	  Time, in seconds that will be used to start the full load, default is 0, that is all started at once"
"\n			  this should be used with 'max time' and/or 'exec count' to simulate a given number of processes"
"\n	check for quit every= When fetching rows from a query, the process will not check if asked to quit after every fetch, as this would take lots of"
"\n			valuable time, and contribute a lot to the total elapsed time. So, you can specify this parameter"
"\n			to tell the process to check if asked to quit after that many rows are fetched. Use this if there are queries that "
"\n			may return millions or billions of rows, and you want to be able to stop them cleanly before the fetches are finished"
"\n	sql=		The sql statement to be used to be executed. "
"\n			The sql can be on several lines, and ends with a line begining with 'end sql',';' or '/' or at the end of the file "
"\n			if the word after the 'sql=' is 'file', then it points to the name of a file containing statements."
"\n			The file_name can be preceded by a number like this 'xxx:file_name'. xxx will be the number of processes"
"\n			used to execute the SQL statements in the file, if there's more than one. Up to xxx processes will participate,"
"\n			unless all are busy. If there is more than one process, i.e. xxx>1, every process will execute all the SQL in the file."
"\n			Otherwise, every statement in the file will be sent to the first idle process, until all are finished"
"\n			The SQL and should be terminated by a line containing either a ';' or a '/' (or have the last line of the "
"\n			query end with a ';' with no spaces after). You can have non select statements there. If you put a pl/sql blocks"
"\n			if should begin with a 'begin' or 'declare' words, which is normal, and the last line should be a '/' by itself, like in sql*plus scripts"
"\n			if you put table=... after the sql=, then you can specify a sql statement to read the sql code from any table you have"
"\n			for example, it can be like this: sql=table=select sql_text,sql_id from dba_sqlset_statements where sqlset_name='....' order by ..."
"\n			The SQL should return 2 columns, the first one should be the sql_statement to execute (the column is taken to be a clob), "
"\n			the second will be used as an identifier of the statement, added to the query name "
"\n			you spoecify in the parfile. The select statement can be preceded by a number (e.g. 2:select ...') "
"\n			The number will be taken to indicate how many processes to start for this sql"
"\n			like the 'file=...' case, if more than one process is specified, then each one will execute all the statements from the table"
"\n			otherwise, the statements will be read and each one executed by the first idle process."
"\n	setup script=	Any SQL or PL/SQL script to be executed (not a SELECT). It can be on several lines, and ends with a line"
"\n	                begining with 'end setup', '/' or ';' "
"\n	you can have as many 'setup script' and ('sql=', 'file=') tuples as you want."
"\n	setup script is usually used to set nls_date_format, optimizer related params (e.g. parallel degree, ...). "
"\n	It can also be used to set module_name,or any other params for the session."
"\n	The program will NOT commit after it's execution, so if need be, do a commit inside the setup script."
"\n	The program will read the parameter file and execute the SQL as they are read, in the order of appearance. "
"\n	This means that you must specify all required params before the sql and not after it."
"\n	The setup script is executed when any process starts working after the script is read.\n", program_name,program_name,program_name);
	printf("you can also set a debug flag as follows (bit mask) (export debug=... before running rwpbench, you can also position )"
"\n an env var debug_file_name to make the system write debug messages to a file, one per process):"
"\n	bit 1  (%d) is just informational message about execution (e.g. what sql is being executed, .....)"
"\n	bit 2  (%d) debug machine-to-machine sockect operations"
"\n	bit 3  (%d) debug printing and inserting into the db of exec stats when using  bind values"
"\n	bit 4  (%d) is for debugging bind vars operations"
"\n	bit 5  (%d) is for debugging the send params operation"
"\n	bit 6  (%d) is for debugging get_idle_child,wait_for_all_to_finish"
"\n	bit 7  (%d) is for debugging get_ip_and_port"
"\n	bit 8  (%d) is for process_output_csv and process_sql"
"\n	bit 9  (%d) is for get_master_message"
"\n	bit 10 (%d) is to debug get_next_sql"
"\n	bit 11 (%d) is to debug processing_thread"
"\n	bit 12 (%d) is to debug get_v_data & sqlmon"
"\n	bit 13 (%d) is for fork_proc"
"\n	bit 14 (%d) is for start_processes & setup_master"
"\n	bit 15 (%d) is for oracle_connect\n", 1<<1,1<<2,1<<3,1<<4,1<<5,1<<6,1<<7,1<<8,1<<9,1<<10,1<<11,1<<12,1<<13,1<<14,1<<15);
		printf("Author:		Ghassan Salem, Oracle Corp.\n");
		return 0;
	}
	perf_db_uname[0]='\0';
	i_am_master=1;
	master_ip[0]='\0';
	c_bind_file_separator='|';
	int nbr_of_processes=1;
	*sqlmon_type='\0';
	username[0]='\0';
	separate_process_sqlid=0;
	for (i=1;i<argc;i++){
		//printf("par %d =%s\n",i,argv[i]);
		if (!strncasecmp(argv[i], "parfile=", 8)){
				cptr = (argv[i]) + 8;
				strncpy(parfilename, cptr,MAX_FILENAME_LEN);
				if ((parfile = fopen(cptr, "r")) == NULL) {
					printf("Please specify a correct filename as a parameter file\n");
					return (-1);
				}
		} else if (!strncasecmp(argv[i], "userid=", 7)){
				cptr = (argv[i]) + 7;
				strncpy(username, cptr, 128);
		} else if (!strncasecmp(argv[i], "out_csv=", 8)){
				cptr = (argv[i]) + 8;
				strncpy(out_csv_fname, cptr, 512);
				out_csv=fopen(out_csv_fname,"w");
		} else if (!strncasecmp(argv[i], "master_ip=", 10)){
				cptr = (argv[i]) + 10;
				strncpy(master_ip, cptr, 30);
				i_am_master=check_if_master(master_ip);
		} else if(!strncasecmp(argv[i], "master_port=", 12)){
				cptr = (argv[i]) + 12;
				master_port=atoi(cptr);
		} else if(!strncasecmp(argv[i], "sep_process_sqlid=", 18)){
				cptr = (argv[i]) + 18;
				if (*cptr=='Y'||*cptr=='y') separate_process_sqlid=1;
		} else if(!strncasecmp(argv[i], "nbr_of_processes=", 17)){
				cptr = (argv[i]) + 17;
				nbr_of_processes=degree=atoi(cptr);
		} else if(!strncasecmp(argv[i], "number_of_machines=", 19)){
				cptr = (argv[i]) + 19;
				nbr_clients=atoi(cptr);
		}
	}
	if (nbr_of_processes==0 && i_am_master==1) {
		printf("Please specify the number of processes (nbr_of_processes=...)\n");
		exit(EXIT_FAILURE);
	}
	sockets_listf=(int *)malloc(sizeof(degree)*degree);
	if (getenv("debug")) {
		//printf("debug=%s\n",getenv("debug"));
		debug = (int) strtol(getenv("debug"), cptr1, 10);
		//printf("debug=%s\n",getenv("debug"));
		//printf("%d\n",debug);
		my_print("debug mode=%d\n", debug);
		my_print("debug flag can be set as follows (bit mask)"
	"\nbit 1  (%d) is just informational message about execution (e.g. what sql is being executed, .....)"
	"\nbit 2  (%d) debug machine-to-machine sockect operations"
	"\nbit 3  (%d) debug printing and inserting into the db of exec stats when using  bind values"
	"\nbit 4  (%d) is for debugging bind vars operations"
	"\nbit 5  (%d) is for debugging the send params operation"
	"\nbit 6  (%d) is for debugging get_idle_child"
	"\nbit 7  (%d) is for debugging get_ip_and_port"
	"\nbit 8  (%d) is for process_output_csv"
	"\nbit 9  (%d) is for get_master_message"
	"\nbit 10 (%d) is to debug get_next_sql"
	"\nbit 11 (%d) is to debug processing_thread"
	"\nbit 12 (%d) is to debug get_v_data & sqlmon"
	"\nbit 13 (%d) is for fork_proc"
	"\nbit 14 (%d) is for start_processes & setup_master"
	"\nbit 15 (%d) is for oracle_connect\n", 1<<1,1<<2,1<<3,1<<4,1<<5,1<<6,1<<7,1<<8,1<<9,1<<10,1<<11,1<<12,1<<13,1<<14,1<<15);
		if (getenv("debug_file_name")) 
			strcpy(debug_file_name,getenv("debug_file_name"));
	}
	comp_trial_nbr=0;
	if (!i_am_master){ //I'm not the master, so no parfile to read, just open the socket to the master and wait for instructions
		if ((master_socket=open_socket_to_master(master_ip,master_port))<0){
			printf("could not connect to specified master, if it is not yet started, please do so and restart\n");
			return (-1);
		}
		while(1){ // will loop waiting for a message from the master
			// The message should be to start a given number of processes. Once this is done, we just quit.
			switch(get_master_message(master_socket, 10000000)){
			// any message type !=1 is an error so we ignore it.
				case 1: start_processes(username,degree, master_ip, master_port);
					printf("Started %d processes. Will exit but they remain in the background\n",degree);
					return(0);
			}
		}
	}
	else {
		int is_multi_machine=1;
		strncpy(admin_user,username,255);
		if (master_ip[0]=='\0') {// we're in a single machine config
			// so we'll get the ip to use, and pick a port number
			if (get_ip_and_port(master_ip,&master_port, &sqlid_port)<0) {
				printf("cannot get ip and port for communication\n");
				exit;
			}
			is_multi_machine=0;
		}
		setup_master(master_ip,master_port,nbr_clients, degree,username, is_multi_machine);
		/* EXEC SQL CONNECT :admin_user at main_db ; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )10;
  sqlstm.offset = (unsigned int  )4695;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)admin_user;
  sqlstm.sqhstl[0] = (unsigned long )256;
  sqlstm.sqhsts[0] = (         int  )256;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlstm.sqlcmax = (unsigned int )100;
  sqlstm.sqlcmin = (unsigned int )2;
  sqlstm.sqlcincr = (unsigned int )1;
  sqlstm.sqlctimeout = (unsigned int )0;
  sqlstm.sqlcnowait = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto connect_error;
}


		if (sqlca.sqlcode!=0) {
			my_print("Cannot connect to the db, error=%d, please specify a good user", sqlca.sqlcode);
			return (-1);
		}

		argument = cptr;
		log_file_name[0] = '\0';
		query_name[0] = '\0';
		*setup_script = '\0';
		file_name[0] = '\0';
		finished=0;
		strcpy(username1, username);
		socket_host_ip[0] = '\0';
		while (!feof(parfile) && argument != NULL) {
			argument = fgets(line, MAX_LINE_SIZE, parfile);
			if (argument != NULL) {
				if (argument[strlen(line) - 1] == '\n')
					argument[strlen(line) - 1] = '\0';
				if (!strncasecmp(argument, "file=", 5)) {
					cptr = argument + 5;
					strncpy(file_name, cptr, MAX_FILENAME_LEN);
				} else if (!strncasecmp (argument, "ramp up time=", 13)) {
					cptr = argument + 13;
					ramp_up_time = (long)atoi(cptr)*1000000;
					ramp_up_time_remain = ramp_up_time;
					if (!silent)
						printf("ramp_up_time=%ld\n",
						       ramp_up_time);
				} else if (!strncasecmp(argument, "max time=", 9)) {
					cptr = argument + 9;
					max_time = (long)atoi(cptr) * 1000000;
					exec_count = 9999999;
				} else if (!strncasecmp (argument, "flush results=", 14)) {
					cptr = argument + 14;
					flush_results_every = atoi(cptr);
				} else if (!strncasecmp (argument, "binds from sqlset=", 18)) {
					cptr = argument + 18;
					if (*cptr=='Y'||*cptr=='y')
						binds_from_sqlset = 1;
				} else if (!strncasecmp (argument, "query name=", 11)) {
					cptr = argument + 11;
					strncpy(query_name, cptr, 50);
				} else if (!strncasecmp(argument, "sql=", 4)) {// The most important part: we found a sql 'statement' instruction
					cptr = argument + 4;
					strcpy(dyn_statement, cptr);
					if (!strncasecmp (dyn_statement, "file=", 5)) {// The statement(s) come(s) from a file, so let's find out how to execute it
						// the syntax is like this: sql=file=[xxx:]file_name
						// xxx, if present means that we'll be using xxx processes to execute the statement(s) from the file, if not defined, then 1
						cptr = dyn_statement + 5;
						if (debug&debug_level) my_print("got file %s and %s\n",dyn_statement,cptr);
						char intermc[500];//=malloc(strlen(cptr));
						strcpy(intermc,cptr);
						strcpy(dyn_statement,intermc);
						//strcpy(dyn_statement, cptr);
						exec_all_in_file = 0;
						if (debug&debug_level) my_print("before free intermc %s\n",dyn_statement);
						//free(intermc);
						if (debug&debug_level) my_print("copied cptr to dyn_statement %s\n",dyn_statement);
						if (strchr(dyn_statement, ':') == NULL)
							nbr_processes = 1; // there are no specific instructions, so we use just 1 process
						else { // Check if there's an 'A' at the start, and position exec_all_in_file accordingly
							exec_all_in_file = 1;
							char   *prc = strchr(dyn_statement, ':');
							char *strr=malloc(strlen(dyn_statement)+1);
							*prc = '\0';
							if (debug&debug_level) my_print("got nbr_processes=%d and now prc=%s will copy it to dyn_statement\n",nbr_processes,prc);
							nbr_processes = (int) strtol(dyn_statement, (char **) NULL, 10);
							prc++;
							if (debug&debug_level) my_print("got nbr_processes=%d and now prc=%s will copy it to dyn_statement\n",nbr_processes,prc);
							strcpy(strr, prc);
							if (debug&debug_level) my_print("after strcpy prc=%s and dyn_statement=%s\n",prc,strr);
							strcpy(dyn_statement,strr);
							free(strr);
						}
						series_of_queries = 1; // means that we're taking statements from a file
						if (debug&debug_level) my_print("exec_all_in_file set to %d, and file is %s nbr_processes=%d s_o_q=%d\n",exec_all_in_file,dyn_statement,nbr_processes,series_of_queries);
					} else if (!strncasecmp (dyn_statement, "table=", 6)) { // it's a table, not a file
						// syntax is same as for 'file' above, except that the 'A' indicator is not supported
						cptr = dyn_statement + 6;
						strcpy(dyn_statement, cptr);
						exec_all_in_file = 0;
						if (strchr(dyn_statement, ':') == NULL)
							nbr_processes = 1;
						else {
							char   *prc = strchr (dyn_statement, ':');
							*prc = '\0';
							nbr_processes = (int) strtol (dyn_statement, (char **) NULL, 10);
							prc++;
							strcpy(dyn_statement, prc);
							exec_all_in_file=2;
							if (debug&debug_level) my_print("got sql=%s\n",dyn_statement);
						}
						series_of_queries = 2; // tell the process we're taking the statements from a table
					} else if (!strncasecmp (dyn_statement, "sqlset=", 7)) { // it's a sqlset, neither a table nor a file
						// syntax is same as for 'file' above, except that the 'A' indicator is not supported
						cptr = dyn_statement + 7;
						strcpy(dyn_statement, cptr);
						exec_all_in_file = 0;
						if (strchr(dyn_statement, ':') == NULL)
							nbr_processes = 1;
						else {
							char   *prc = strchr (dyn_statement, ':');
							*prc = '\0';
							nbr_processes = (int) strtol (dyn_statement, (char **) NULL, 10);
							prc++;
							strcpy(dyn_statement, prc);
							exec_all_in_file=2;
						}
						strcpy(bind_sqlsetname,dyn_statement);
						sprintf(dyn_statement,"select sql_text, sql_id from dba_sqlset_statements where sqlset_owner||'.'||sqlset_name=upper('%s') order by first_load_time asc",
						bind_sqlsetname);
						series_of_queries = 2; // tell the process we're taking the statements from a sqlset
					} else { // if we're here, it means we just have a single sql statement in the parfile itself
						// so we read it into dyn_statement
						int sql_start_line;
						strcat(dyn_statement, "\n");
						linenbr = 1;
						series_of_queries=0;
						get_next_sql(parfile,
							     dyn_statement, line,
							     &linenbr, &sql_start_line);
						strip_initial_comment(dyn_statement);
					}
					if (series_of_queries == 2||series_of_queries==3) {
						/* we'll be reading statements from a table or a sqlset (the main diff is that from a sqlset, dyn_statement here has this format [owner.]sqlset_name,
						   so we will loop to see if we have the requested number of processes free to tell them to start processing data from the table
						   if we don't have the requested number of processes, we'll wait until someone is free and we'll tell it to work on the table
						   if the SQL from the table are done, then there'll be no more work for the newly joining processes and they will return very quickly */
						int     pr_n;
						if (exec_all_in_file==0) {
							// we'll read the statements from the table
							// and send each one to a process until all statements are done
							if (debug&debug_level) my_print("after connect, username=%s ret_code=%d\n",username,sqlca.sqlcode);
							OCIClobLocator *SQLstmt;
							char ch_read_sql[256], chrowid[32], *query_name1;
							/* EXEC SQL at main_db ALLOCATE :SQLstmt; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 13;
       sqlstm.arrsiz = 44;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )4733;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)&SQLstmt;
       sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqphsv = sqlstm.sqhstv;
       sqlstm.sqphsl = sqlstm.sqhstl;
       sqlstm.sqphss = sqlstm.sqhsts;
       sqlstm.sqpind = sqlstm.sqindv;
       sqlstm.sqpins = sqlstm.sqinds;
       sqlstm.sqparm = sqlstm.sqharm;
       sqlstm.sqparc = sqlstm.sqharc;
       sqlstm.sqpadto = sqlstm.sqadto;
       sqlstm.sqptdso = sqlstm.sqtdso;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) goto connect_error;
}


							if (debug&debug_level) my_print("after connect, username=%s ret_code=%d\n",username,sqlca.sqlcode);
							int yet_more_rows = 0, Reduced_size, VOffset, VStmtSize;
							query_name1=(char *) malloc(strlen(query_name)+1);
							strcpy(query_name1,query_name);
							
							/* exec sql at main_db declare  get_queriess statement ; */ 

							/* exec sql at main_db PREPARE get_queriess from :dyn_statement; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 13;
       sqlstm.arrsiz = 44;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )4759;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)dyn_statement;
       sqlstm.sqhstl[0] = (unsigned long )257000;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqphsv = sqlstm.sqhstv;
       sqlstm.sqphsl = sqlstm.sqhstl;
       sqlstm.sqphss = sqlstm.sqhsts;
       sqlstm.sqpind = sqlstm.sqindv;
       sqlstm.sqpins = sqlstm.sqinds;
       sqlstm.sqparm = sqlstm.sqharm;
       sqlstm.sqparc = sqlstm.sqharc;
       sqlstm.sqpadto = sqlstm.sqadto;
       sqlstm.sqptdso = sqlstm.sqtdso;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) goto connect_error;
}


							if (debug&debug_level) my_print("after prepare stmt=%s\n",ch_read_sql);
							/* exec sql at main_db declare get_sqls cursor for get_queriess; */ 

							if (debug&debug_level)
								my_print("declared cursor\n");
							/* exec sql open get_sqls; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 13;
       sqlstm.arrsiz = 44;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )4785;
       sqlstm.selerr = (unsigned short)100;
       sqlstm.sqlpfmem = (unsigned int  )0;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqcmod = (unsigned int )0;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) goto connect_error;
}


							series_of_queries=0;
							if (debug&debug_level)
								my_print("opened cursor\n");
							while (yet_more_rows == 0) {
								/* exec sql fetch get_sqls
									into :SQLstmt, :chrowid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )4807;
        sqlstm.selerr = (unsigned short)100;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&SQLstmt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)chrowid;
        sqlstm.sqhstl[1] = (unsigned long )32;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto connect_error;
}


								if (debug&debug_level)
									my_print("fetch cursor sqlca.sqlcode=%d\n",sqlca.sqlcode);
								yet_more_rows = sqlca.sqlcode;
								strcpy(dyn_statement,"");
								if (yet_more_rows==0) {
									sprintf(query_name, "%s : =%s",
										query_name1, chrowid);
									/* exec sql at main_db lob describe :SQLstmt get length into :VStmtSize; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 13;
         sqlstm.arrsiz = 44;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )4837;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqhstv[0] = (unsigned char  *)&SQLstmt;
         sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&VStmtSize;
         sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)0;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqphss = sqlstm.sqhsts;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqpins = sqlstm.sqinds;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlstm.sqpadto = sqlstm.sqadto;
         sqlstm.sqptdso = sqlstm.sqtdso;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) goto connect_error;
}


									Reduced_size=10000;
									VOffset=1;
									/* varchar *VStmt=(varchar *)malloc(Reduced_size+4); */ 
varchar *VStmt
 = malloc((Reduced_size+4));

									VStmt->len=Reduced_size;
									/* EXEC SQL at main_db LOB READ :VStmtSize
										FROM :SQLstmt at :VOffset
										into :VStmt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 13;
         sqlstm.arrsiz = 44;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )4867;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqhstv[0] = (unsigned char  *)&VStmtSize;
         sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&SQLstmt;
         sqlstm.sqhstl[1] = (unsigned long )sizeof(void *);
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)0;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&VOffset;
         sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)0;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)VStmt;
         sqlstm.sqhstl[3] = (unsigned long )0;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)0;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqphss = sqlstm.sqhsts;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqpins = sqlstm.sqinds;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlstm.sqpadto = sqlstm.sqadto;
         sqlstm.sqptdso = sqlstm.sqtdso;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) goto connect_error;
}


									strncat(dyn_statement, VStmt->arr,
										VStmt->len);
									while (sqlca.sqlcode == 0) {
										/* EXEC SQL at main_db LOB
											READ :Reduced_size
											FROM :SQLstmt
											into :VStmt; */ 

{
          struct sqlexd sqlstm;
          sqlstm.sqlvsn = 13;
          sqlstm.arrsiz = 44;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.stmt = "";
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )4909;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)4352;
          sqlstm.occurs = (unsigned int  )0;
          sqlstm.sqhstv[0] = (unsigned char  *)&Reduced_size;
          sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
          sqlstm.sqhsts[0] = (         int  )0;
          sqlstm.sqindv[0] = (         short *)0;
          sqlstm.sqinds[0] = (         int  )0;
          sqlstm.sqharm[0] = (unsigned long )0;
          sqlstm.sqadto[0] = (unsigned short )0;
          sqlstm.sqtdso[0] = (unsigned short )0;
          sqlstm.sqhstv[1] = (unsigned char  *)&SQLstmt;
          sqlstm.sqhstl[1] = (unsigned long )sizeof(void *);
          sqlstm.sqhsts[1] = (         int  )0;
          sqlstm.sqindv[1] = (         short *)0;
          sqlstm.sqinds[1] = (         int  )0;
          sqlstm.sqharm[1] = (unsigned long )0;
          sqlstm.sqadto[1] = (unsigned short )0;
          sqlstm.sqtdso[1] = (unsigned short )0;
          sqlstm.sqhstv[3] = (unsigned char  *)VStmt;
          sqlstm.sqhstl[3] = (unsigned long )0;
          sqlstm.sqhsts[3] = (         int  )0;
          sqlstm.sqindv[3] = (         short *)0;
          sqlstm.sqinds[3] = (         int  )0;
          sqlstm.sqharm[3] = (unsigned long )0;
          sqlstm.sqadto[3] = (unsigned short )0;
          sqlstm.sqtdso[3] = (unsigned short )0;
          sqlstm.sqphsv = sqlstm.sqhstv;
          sqlstm.sqphsl = sqlstm.sqhstl;
          sqlstm.sqphss = sqlstm.sqhsts;
          sqlstm.sqpind = sqlstm.sqindv;
          sqlstm.sqpins = sqlstm.sqinds;
          sqlstm.sqparm = sqlstm.sqharm;
          sqlstm.sqparc = sqlstm.sqharc;
          sqlstm.sqpadto = sqlstm.sqadto;
          sqlstm.sqptdso = sqlstm.sqtdso;
          sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
          if (sqlca.sqlcode < 0) goto connect_error;
}


										strncat(dyn_statement,
											VStmt->arr,
											VStmt->len);
										if (debug&debug_level)
											my_print("Got %d of statement\n", Reduced_size);
									}
									free(VStmt);
									ret_code = get_idle_child ( degree,&finished,&prc_id,username);
									if (ret_code < 0) {
										my_print("There was a problem with the main pipe, exiting\n");
										return 1;
									}
									send_params(prc_id);
									if (ramp_up_time_remain > 0) {
										usleep(ramp_up_time/ nbr_of_processes);
										ramp_up_time_remain -= ramp_up_time / nbr_of_processes;
									}
									if (asked_to_quit()) yet_more_rows=1403;
								}
							}
							/* exec sql close get_sqls; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 13;
       sqlstm.arrsiz = 44;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )4951;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) goto connect_error;
}


							free(query_name1);
							/* exec sql at main_db free :SQLstmt; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 13;
       sqlstm.arrsiz = 44;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )4973;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)&SQLstmt;
       sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqphsv = sqlstm.sqhstv;
       sqlstm.sqphsl = sqlstm.sqhstl;
       sqlstm.sqphss = sqlstm.sqhsts;
       sqlstm.sqpind = sqlstm.sqindv;
       sqlstm.sqpins = sqlstm.sqinds;
       sqlstm.sqparm = sqlstm.sqharm;
       sqlstm.sqparc = sqlstm.sqharc;
       sqlstm.sqpadto = sqlstm.sqadto;
       sqlstm.sqptdso = sqlstm.sqtdso;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) goto connect_error;
}


							/* exec sql at main_db commit work; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 13;
       sqlstm.arrsiz = 44;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )4999;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) goto connect_error;
}


						} else { // will send the table_name to all requested processes
							// and each one will execute all the statements in the table
							for (pr_n = 0;
							     pr_n < nbr_processes;
							     pr_n++) {
								ret_code = get_idle_child( degree,&finished,&prc_id,username);
								if (ret_code < 0) {
									my_print("There was a problem with the main pipe, exiting\n");
									return 1;
								}
								send_params
									(prc_id);
									if (ramp_up_time_remain > 0) {
										usleep(ramp_up_time / nbr_of_processes);
										ramp_up_time_remain -= ramp_up_time / ramp_up_time_remain;
									}
							}
						}
					} else if (series_of_queries == 1) {	/* we'll be reading statements from a a file, so
										   if we have just 1 process, or all requested processes must execute all the queries from the file
										   we assign the requested number of processes, if there are so many free processes */
						int     pr_n;

						if (exec_all_in_file == 0) {
							/* we will read the statements from the file, whose name is in dyn_statement, and assign each one to a process,
							   until all the queries are finished */
							FILE   *sqlf;
							if ((sqlf =
							     fopen(dyn_statement, "r")) == NULL) {
								printf("Cannot open sqlfile %s\n", dyn_statement);
								return 1;
							}
							series_of_queries = 0;
							linenbr = 1;
							char   *query_name_s;
							query_name_s = (char *)malloc(strlen (query_name) + 1);
							strcpy(query_name_s, query_name);
							while (!feof(sqlf)) {
								int start_sql_line;
								sprintf(query_name,
									"%.180s : (line %d)",
									query_name_s,
									linenbr);
								dyn_statement[0] = '\0';
								get_next_sql(sqlf, dyn_statement, line, &linenbr, &start_sql_line);
								strip_initial_comment(dyn_statement);
							        if (debug&debug_level) my_print("got sql=%s\n",dyn_statement);
								if (dyn_statement[0] != '\0') {
									ret_code = get_idle_child( degree,&finished,&prc_id,username);
									if (ret_code < 0) {
										my_print("There was a problem with the socket, exiting\n");
										return 1;
									}
									if (debug&debug_level) my_print("sending file %s to first available process\n",dyn_statement);
									send_params
										(prc_id);
									if (ramp_up_time_remain > 0) {
										usleep(ramp_up_time / nbr_of_processes);
										ramp_up_time_remain -= ramp_up_time / ramp_up_time_remain;
									}
								}
							}
							free(query_name_s);
						} else
							for (pr_n = 0;
							     pr_n < nbr_processes;
							     pr_n++) {
							        if (debug&debug_level) my_print("sending file %s to first available process\n",dyn_statement);
								ret_code = get_idle_child( degree,&finished,&prc_id,username);
								if (ret_code < 0) {
									my_print("There was a problem with the main pipe, exiting\n");
									return 1;
								}
								send_params
									(prc_id);
									if (ramp_up_time_remain > 0) {
										usleep(ramp_up_time / nbr_of_processes);
										ramp_up_time_remain -= ramp_up_time / ramp_up_time_remain;
									}
							}
					} else {	/* there's just one statement so we assigne it to the first available process */
						ret_code = get_idle_child ( degree,&finished,&prc_id,username);
						if (ret_code < 0) {
							my_print("There was a problem with the main pipe, exiting\n");
							return 1;
						}
						send_params(prc_id);
								if (ramp_up_time_remain > 0) {
									usleep(ramp_up_time / nbr_of_processes);
									ramp_up_time_remain -= ramp_up_time / ramp_up_time_remain;
								}
					}
					query_name[0] = '\0';
					bind_file_name[0] = '\0';
					log_file_name[0]='\0';
					file_name[0]='\0';
				} else if (!strncasecmp
					   (argument, "setup script=", 13)) {
					cptr = argument + 13;
					strcpy(setup_script, cptr);
					strcat(setup_script, "\n");
					if (debug&debug_level) my_print("got setup script=%s",setup_script);
					while (!feof(parfile) && argument != NULL
					       && strncasecmp(argument, "end setup", 9)
					       && (*argument != '/'
						   || (*argument == '/'
						       && strlen(argument) > 3))
					       && (*argument != ';')) {
						argument =fgets(line, MAX_LINE_SIZE, parfile);
					//if (debug&debug_level) my_print("got setup script=%s",setup_script);
					if (debug&debug_level) my_print("got argument=%s",argument);
						if (argument != NULL
						    && strncasecmp(argument,
								   "end setup", 9)
						    && (*argument != '/')
						    && (*argument != ';'))
							strcat(setup_script, argument);
					}
				} else if (!strncasecmp (argument, "ADD MONITOR HINT=", 17)) {
					cptr = argument + 17;
					if (*cptr == 'Y' || *cptr == 'y')
						strcpy(v_add_monitor_hint, " monitor ");
				} else if (!strncasecmp(argument, "SQLSET=", 7)) {
					cptr = argument + 7;
					sqlset_save = 1;
					strncpy(sqlset_name, cptr, 30);
				} else if (!strncasecmp(argument, "log file=", 9)) {
					cptr = argument + 9;
					strncpy(log_file_name, cptr, MAX_FILENAME_LEN);
				} else if (!strncasecmp(argument, "compare trial nbr=", 18)) {
					cptr = argument + 18;
					if (*cptr=='P'||*cptr=='p') comp_trial_nbr=-1;
					else comp_trial_nbr=atoi(cptr);
				} else if (!strncasecmp
					   (argument, "awr snapshots=", 14)) {
					cptr = argument + 14;
					if (!(*cptr == 'N' || *cptr == 'n')) {
						awr_create = 1;
						char **endptr;
						awr_period=strtol(cptr, endptr,10);
						if (awr_period>0) ret_code=gettimeofday(&awr_time,NULL);
						/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

						/* exec sql at main_db select
							dbms_workload_repository.create_snapshot
							into :begin_snap_id from
							dual; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 13;
      sqlstm.arrsiz = 44;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select dbms_workload_repository . create_snapshot into \
:b0 from dual ";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )5021;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.sqlpfmem = (unsigned int  )0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&begin_snap_id;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


						printf("Just created snapshot id %d, sqlca.sqlcode=%d\n", begin_snap_id,sqlca.sqlcode);
					}
				} else if (!strncasecmp (argument, "awr reports=", 12)) {
					cptr = argument + 12;
					strncpy(awr_instances, cptr, 1023);
				} else if (!strncasecmp(argument, "flush sp=", 9)) {
					cptr = argument + 9;
					if (*cptr == 'Y' || *cptr == 'y') {
						/* flush shared pool */
						/* EXEC SQL WHENEVER SQLERROR
							CONTINUE; */ 

							/* exec sql at main_db execute immediate
								'alter system flush shared_pool'; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 13;
       sqlstm.arrsiz = 44;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "alter system flush shared_pool";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )5047;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


							if (sqlca.sqlcode == 0)
								printf("Just flushed the shared pool\n");
					}
				} else if (!strncasecmp(argument, "flush bc=", 9)) {
					cptr = argument + 9;
					if (*cptr == 'Y' || *cptr == 'y') {
						/* flush shared pool */
						/* EXEC SQL WHENEVER SQLERROR
							CONTINUE; */ 

							/* exec sql at main_db execute immediate
								'alter system flush buffer_cache'; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 13;
       sqlstm.arrsiz = 44;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "alter system flush buffer_cache";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )5069;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


							if (sqlca.sqlcode == 0)
								printf("Just flushed the buffer cache\n");
					}
				} else if (!strncasecmp (argument, "trial nbr=", 10)) {
					cptr = argument + 10;
					if (perf_db_uname[0]=='\0') strcpy(perf_db_uname,username);
					check_create_tracking_tables(perf_db_uname);
					if (*cptr == 'N' || *cptr == 'n') {
						/* get last trial_nbr and increment it */
						/* EXEC SQL WHENEVER SQLERROR
							CONTINUE; */ 

						sqlca.sqlcode=0;
						if (strcmp(perf_db_uname,username)!=0) {
								/* EXEC SQL CONNECT :perf_db_uname at perf_db; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )10;
        sqlstm.offset = (unsigned int  )5091;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)perf_db_uname;
        sqlstm.sqhstl[0] = (unsigned long )256;
        sqlstm.sqhsts[0] = (         int  )256;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlstm.sqlcmax = (unsigned int )100;
        sqlstm.sqlcmin = (unsigned int )2;
        sqlstm.sqlcincr = (unsigned int )1;
        sqlstm.sqlctimeout = (unsigned int )0;
        sqlstm.sqlcnowait = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


							if (sqlca.sqlcode==0) {
								/* exec sql at perf_db select nvl(max(trial_nbr),0) + 1
								into :trial_nbr from runs_desc; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select nvl ( max ( trial_nbr ) , 0 ) + 1 into :b0 fro\
m runs_desc ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5129;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&trial_nbr;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


								/* exec sql at perf_db commit work release; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5155;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


								my_print("log off from %s",perf_db_uname);
							} else my_print("Could not connect to perf db as %s to get trial_nbr\n",perf_db_uname);
						} else {
								/* exec sql at main_db
								select nvl(max(trial_nbr),0) + 1
								into :trial_nbr 
								from runs_desc; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 44;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select nvl ( max ( trial_nbr ) , 0 ) + 1 into :b0 fro\
m runs_desc ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5177;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&trial_nbr;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


						}
					 } else
						trial_nbr = atoi(cptr);
					if (!silent)
						printf("Trial nbr= %d\n",
						       trial_nbr);
				} else if (!strncasecmp(argument, "SILENT=", 7)) {
					cptr = argument + 7;
					if (*cptr == '\0' || *cptr == 'N'
					    || *cptr == 'n') {
						silent = 0;
					} else
						silent = 1;
				} else if (!strncasecmp (argument, "bind file=", 10)) {
					cptr = argument + 10;
					strncpy(bind_file_name, cptr, MAX_FILENAME_LEN);
				} else if (!strncasecmp (argument, "THINK TIME MIN=", 15)) {
					cptr = argument + 15;
					think_time_min =
						(int)strtod(cptr, NULL) * 1000000;
				} else if (!strncasecmp (argument, "THINK TIME MAX=", 15)) {
					cptr = argument + 15;
					think_time_max = (int)strtod(cptr, NULL) * 1000000;
				} else if (!strncasecmp (argument, "PRINT PLAN STATS=", 17)) {
					cptr = argument + 17;
					if (*cptr == '\0' || *cptr == 'N' || *cptr == 'n') {
						print_plan = 0;
					} else
						print_plan = 1;
				} else if (!strncasecmp (argument, "sqlmonitor=", 11)) {
					cptr = argument + 11;
					if (*cptr == '\0' || *cptr == 'N' || *cptr == 'n') {
						save_sqlmon = 0;
					} else {
						char *col=strchr(cptr,':');
						if (is_numeric(cptr)!=0) {
							save_sqlmon = (int)atoi(cptr);
							strcpy(sqlmon_type,"ACTIVE");
						} else {
							save_sqlmon=1;
							if (col==NULL)strncpy(sqlmon_type,cptr,20);
							else {
								*col='\0';
								strncpy(sqlmon_type,cptr,20);
								save_sqlmon=(int)atoi(col+1);
							}
						}
					}
				} else if (!strncasecmp (argument, "bind file separator=", 20)) {
					cptr = argument + 20;
					c_bind_file_separator=*cptr;
				} else if (!strncasecmp (argument, "rows to fetch=", 14)) {
					cptr = argument + 14;
					max_rows = (int) atoi(cptr);
				} else if (!strncasecmp (argument, "exec count=", 11)) {
					cptr = argument + 11;
					exec_count = atoi(cptr);
				} else if (!strncasecmp (argument, "print my stats=", 15)) {
					cptr = argument + 15;
					if (*cptr == 'Y' || *cptr == 'y') {
						print_my_stats = 1;
					} else
						print_my_stats = 0;
				} else if (!strncasecmp (argument, "print pga stats=", 16)) {
					cptr = argument + 16;
					if (*cptr == 'Y' || *cptr == 'y') {
						print_pga_stats = 1;
					} else
						print_pga_stats = 0;
				} else if (!strncasecmp (argument, "bind results to db=", 19)) {
					cptr = argument + 19;
					if (*cptr == 'Y' || *cptr == 'y') {
						bind_results_to_db = 1;
					} else
						bind_results_to_db = 0;
				} else if (!strncasecmp (argument, "bind results to db username=", 28)) {
					cptr = argument + 28;
					strcpy(perf_db_uname,cptr);
					strcpy(db_name,"perf_db");
				} else if (!strncasecmp (argument, "bind send results to host=", 26)) {
					cptr = argument + 26;
					strncpy(send_results_host, cptr, 256);
					if (!get_host_ip()) {
						socket_is_opened = 0;
						printf("Can't get the ip for host %s\n Results will not be sent over the network\n", send_results_host);
						exit;
					}
				} else if (!strncasecmp (argument, "check for quit every=", 21)) {
					cptr = argument + 21;
					check_for_quit_every = atoi(cptr);
				} else if (!strncasecmp (argument, "bind send results to port=", 26)) {
					cptr = argument + 26;
					socket_port_nbr = atoi(cptr);
				} else if (!strncasecmp (argument, "rows to spool=", 14)) {
					cptr = argument + 14;
					rows_to_spool = atoi(cptr);
				} else if (!strncasecmp (argument, "user name=", 10)) {
					cptr = argument + 10;
					strncpy(username1, cptr, 255);
				} else if (!strncasecmp (argument, "debug file name=", 16)) {
					cptr = argument + 16;
					strncpy(debug_file_name, cptr, MAX_FILENAME_LEN);
				} else if (!strncasecmp (argument, "release px wa=", 14)) {
					cptr = argument + 14;
					if (*cptr=='Y'||*cptr=='y') release_px_slaves=1;
				} else if (!strncasecmp (argument, "use dbms_sqltune0=", 18)) {
					cptr = argument + 18;
					if (*cptr=='Y'||*cptr=='y') use_dbms_sqltune0=1;
				} else if (!strncasecmp (argument, "save mystats=", 13)) {
					cptr = argument + 13;
					if (*cptr=='Y'||*cptr=='y') save_mystats=1;
				} else if (!strncasecmp (argument, "exec stats file=", 16)) {
					cptr = argument + 16;
					strncpy(exec_stats_file_name, cptr, MAX_FILENAME_LEN);
				} else if (!strncasecmp (argument, "run description=", 16)) {
					cptr = argument + 16;
					strncpy(run_desc, cptr, 100);
				} else if (!strncasecmp (argument, "stop filename=", 14)) {
					cptr = argument + 14;
					strncpy(stop_file_name, cptr, MAX_FILENAME_LEN);
				}
			}
			if (asked_to_quit()){
				got_to_quit=1;
				break;
			}
			if (awr_period>0) { // check if we are awr_period seconds away from the last snapshot taken
				ret_code=gettimeofday(&ctime,NULL);
				if ((ctime.tv_sec-awr_time.tv_sec)> awr_period) { // we are more than the specified amount of seconds away, so we take a snapshot
					/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

					/* exec sql at main_db select
						dbms_workload_repository.create_snapshot
						into :end_snap_id from
						dual; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 13;
     sqlstm.arrsiz = 44;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "select dbms_workload_repository . create_snapshot into :\
b0 from dual ";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )5203;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.sqlpfmem = (unsigned int  )0;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqhstv[0] = (unsigned char  *)&end_snap_id;
     sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqphss = sqlstm.sqhsts;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqpins = sqlstm.sqinds;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlstm.sqpadto = sqlstm.sqadto;
     sqlstm.sqptdso = sqlstm.sqtdso;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


					printf("Just created another snapshot id %d\n", end_snap_id);
					awr_time.tv_sec=ctime.tv_sec;
				}
			}
		}
	}
	// send exit message to all forked processes
	if (debug_file!=NULL) fclose(debug_file);
	if (out_csv!=NULL) fclose(out_csv);
	
	if (parfile!=NULL) fclose(parfile);
	if (pincfile!=NULL) fclose(pincfile);
	if (sqlf!=NULL) fclose(sqlf);
	// waiting for all children to finish the last processing they are doing
	if (got_to_quit==1)
		for (i = 0; i < nbr_of_processes; i++) {                
			printf("sent exit message to %d\n",i);
			send_msg_to_master(sockets_listf[i],"exit=\n");
		}
	ret_code=wait_for_all_to_finish(nbr_of_processes,username);
	for (i = 0; got_to_quit==0&&i < nbr_of_processes; i++) {
		if (process_busy[i]!=2){
			send_msg_to_master(sockets_listf[i],"exit=\n");
			printf("sent exit message to %d\n",i);
		}
	}
	sleep(2); /* sleeping 2 sec to allow all processes to exit*/
	if (trial_nbr > 0) {
		if (perf_db_uname[0]=='\0') strcpy(perf_db_uname,username);
		print_results(trial_nbr, perf_db_uname);
	}
	if (awr_create > 0)
		handle_awrs(username, begin_snap_id, awr_instances,
			    trial_nbr);
	free(sockets_listf);
	/* exec sql at main_db commit work release; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 44;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5229;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


//	if (sqlid_proc!=-1) kill(sqlid_proc,SIGKILL);
	return 0;

      connect_error:
	printf("\n\n%.70s\n", sqlca.sqlerrm.sqlerrmc);
	return -1;
}
