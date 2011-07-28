#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;
#define interval 12

// IP or Domain name ping statistic generator

/*
    zPingStat
    zLab - 2011
    cc-by-nc-sa
    
    r115
*/

int main(int argc, char *argv[])
{
    int REDRAW,ip,ping_check,i,failtime,help,iptrue,failtimetrue;
    int build=115;

// ALL VAR
          int all_all,all_miss,all_good,all_min,all_max,all_avg;
// 24h VAR
          int h24_all,h24_miss,h24_good,h24_min,h24_max,h24_avg;
// 10h VAR
          int h10_all,h10_miss,h10_good,h10_min,h10_max,h10_avg;
// 1h  VAR
          int h1_all,h1_miss,h1_good,h1_min,h1_max,h1_avg;
// 30m VAR
          int m30_all,m30_miss,m30_good,m30_min,m30_max,m30_avg;
// m10 VAR
          int m10_all,m10_miss,m10_good,m10_min,m10_max,m10_avg;
// m1  VAR    
          int m1_all,m1_miss,m1_good,m1_min,m1_max,m1_avg;
// percentage
          int all_miss_prcnt,h24_miss_prcnt,h10_miss_prcnt,h1_miss_prcnt,m30_miss_prcnt,m10_miss_prcnt,m1_miss_prcnt;
          int all_good_prcnt,h24_good_prcnt,h10_good_prcnt,h1_good_prcnt,m30_good_prcnt,m10_good_prcnt,m1_good_prcnt;
//ZERO
//        x=...=...=0
          all_all=all_miss=all_good=all_min=all_max=all_avg=h24_all=h24_miss=h24_good=h24_min=h24_max=h24_avg=h10_all=h10_miss=h10_good=h10_min=h10_max=h10_avg=h1_all=h1_miss=h1_good=h1_min=h1_max=h1_avg=m30_all=m30_miss=m30_good=m30_min=m30_max=m30_avg=m10_all=m10_miss=m10_good=m10_min=m10_max=m10_avg=m1_all=m1_miss=m1_good=m1_min=m1_max=m1_avg=0;
          all_miss_prcnt=h24_miss_prcnt=h10_miss_prcnt=h1_miss_prcnt=m30_miss_prcnt=m10_miss_prcnt=m1_miss_prcnt=0;
          all_good_prcnt=h24_good_prcnt=h10_good_prcnt=h1_good_prcnt=m30_good_prcnt=m10_good_prcnt=m1_good_prcnt=0;

//ARGV check
ip=i=failtime=help=iptrue=failtimetrue=0;

for(int i =0;i<argc;i++)
    {     if (strcmp(argv[i],"-ip") == 0)
          {
               ip=i+1;
               iptrue=1;
               }
          else if (strcmp(argv[i],"-t") == 0)
          {
               failtime=i+1;
               failtimetrue=1;
               }
          else if (strcmp(argv[i],"-help") == 0)
          help=1;
          }

if (iptrue == 0)
help=1;

//initVAR
    string doping        =("ping");
    string timeout       =("-w");
    string ftime         =argv[failtime];
    string ftimenone     =("5000");
    string repeat        =("-n 1");
    string domain        =argv[ip];
    string nolog         =("> nul");
    doping.append(" ");
    doping.append(timeout);
    doping.append(" ");
if (failtimetrue == 0)
    doping.append(ftimenone);
else
    doping.append(ftime);
    doping.append(" ");
    doping.append(repeat);
    doping.append(" ");
    doping.append(domain);
    doping.append(" ");
    doping.append(nolog);
if (help == 1)
goto printHELP;

//printTABLE:
  printTABLE:
system("cls");
REDRAW=0;
    printf(".-----------------------------------------------------------------.\n");
if (failtimetrue == 1)
    printf("|  zPingStat     | IP : %15s   |    <%4sms Latency    |\n", argv[ip],argv[failtime]);
else
    printf("|  zPingStat     | IP : %15s   |    <5000ms Latency    |\n", argv[ip]);
    printf("|----------------|------------------------|-----------------------|\n");
    printf("|Type:           | Summary  | Miss | Good |  min  |  max  |  avg  |\n");
    printf("|----------------|----------|------|------|-------|-------|-------|\n");
    printf("|All time        | %8d | %3d%% | %3d%% | %3dms | %3dms | %3dms |\n",all_all,all_miss_prcnt,all_good_prcnt,all_min,all_max,all_avg);
    printf("|----------------|----------|------|------|-------|-------|-------|\n");
    printf("|24 hour (86400) | %8d | %3d%% | %3d%% | %3dms | %3dms | %3dms |\n",h24_all,h24_miss_prcnt,h24_good_prcnt,h24_min,h24_max,h24_avg);
    printf("|----------------|----------|------|------|-------|-------|-------|\n");
    printf("|10 hour (36000) | %8d | %3d%% | %3d%% | %3dms | %3dms | %3dms |\n",h10_all,h10_miss_prcnt,h10_good_prcnt,h10_min,h10_max,h10_avg);
    printf("|----------------|----------|------|------|-------|-------|-------|\n");
    printf("|1  hour (3600)  | %8d | %3d%% | %3d%% | %3dms | %3dms | %3dms |\n",h1_all,h1_miss_prcnt,h1_good_prcnt,h1_min,h1_max,h1_avg);
    printf("|----------------|----------|------|------|-------|-------|-------|\n");
    printf("|30 min  (1800)  | %8d | %3d%% | %3d%% | %3dms | %3dms | %3dms |\n",m30_all,m30_miss_prcnt,m30_good_prcnt,m30_min,m30_max,m30_avg);
    printf("|----------------|----------|------|------|-------|-------|-------|\n");
    printf("|10 min  (600)   | %8d | %3d%% | %3d%% | %3dms | %3dms | %3dms |\n",m10_all,m10_miss_prcnt,m10_good_prcnt,m10_min,m10_max,m10_avg);
    printf("|----------------|----------|------|------|-------|-------|-------|\n");
    printf("|1  min  (60)    | %8d | %3d%% | %3d%% | %3dms | %3dms | %3dms |\n",m1_all,m1_miss_prcnt,m1_good_prcnt,m1_min,m1_max,m1_avg);
    printf("`-----------------------------------------------------------------'\n");
    printf("\n");
    printf("* Statistic update every %d query.\n",interval);
    printf("* Latency statistic not calculated at this time.\n");

// Reset block Start
      // h24_reset
         if (h24_all==86400)
                            h24_all=h24_miss=h24_good=h24_min=h24_max=h24_avg=0;
      // h10_reset
         if (h10_all==36000)
                            h10_all=h10_miss=h10_good=h10_min=h10_max=h10_avg=0;
      // h1_reset
         if (h1_all==3600)
                            h1_all=h1_miss=h1_good=h1_min=h1_max=h1_avg=0;
      // m30_reset
         if (m30_all==1800)
                            m30_all=m30_miss=m30_good=m30_min=m30_max=m30_avg=0;
      // m10_reset
         if (m10_all==600)
                            m10_all=m10_miss=m10_good=m10_min=m10_max=m10_avg=0;
      // m1_reset
         if (m1_all==60)
                            m1_all=m1_miss=m1_good=m1_min=m1_max=m1_avg=0;
 
//REDRAWtable:
  REDRAWtable:
if (REDRAW==interval)
   goto getPercentage;
 
//  doPing:
    ping_check=system(doping.c_str());

//  Sleep
Sleep(1000);

//  Counter
all_all=++all_all;
h24_all=++h24_all;
h10_all=++h10_all;
 h1_all=++h1_all;
m30_all=++m30_all;
m10_all=++m10_all;
 m1_all=++m1_all;

REDRAW=++REDRAW;
 
if (ping_check == 0)
    goto SEC;
else
    goto unSEC;
 
goto printTABLE;
 
//SEC:
  SEC:
all_good=++all_good;
h24_good=++h24_good;
h10_good=++h10_good;
 h1_good=++h1_good;
m30_good=++m30_good;
m10_good=++m10_good;
 m1_good=++m1_good;

goto REDRAWtable;
 
//unSEC:
  unSEC:
all_miss=++all_miss;
h24_miss=++h24_miss;
h10_miss=++h10_miss;
 h1_miss=++h1_miss;
m30_miss=++m30_miss;
m10_miss=++m10_miss;
 m1_miss=++m1_miss;
 
goto REDRAWtable;
 
//getPercentage:
  getPercentage:
// miss percentage
all_miss_prcnt=all_miss*100/all_all;
h24_miss_prcnt=h24_miss*100/h24_all;
h10_miss_prcnt=h10_miss*100/h10_all;
h1_miss_prcnt=h1_miss*100/h1_all;
m30_miss_prcnt=m30_miss*100/m30_all;
m10_miss_prcnt=m10_miss*100/m10_all;
m1_miss_prcnt=m1_miss*100/m1_all;
// good percentage
all_good_prcnt=all_good*100/all_all;
h24_good_prcnt=h24_good*100/h24_all;
h10_good_prcnt=h10_good*100/h10_all;
h1_good_prcnt=h1_good*100/h1_all;
m30_good_prcnt=m30_good*100/m30_all;
m10_good_prcnt=m10_good*100/m10_all;
m1_good_prcnt=m1_good*100/m1_all;

//getLatency
//all_min
//all_max
//all_avg

goto printTABLE;

//printHELP:
  printHELP:
               printf("------------------\n");
               printf("| zPingStat r%3d |\n",build);
               printf("------------------\n");
               printf("\n");
               printf(" No IP or domain name found.\n");
               printf("\n");
               printf(" Need argument.\n");
               printf("\n");
               printf(" example:\n");
               printf(" ../zpingstat.exe -ip ya.ru -t 300\n");
               printf(" or\n");
               printf(" ../zpingstat.exe -ip 127.0.0.1\n");
               printf("\n");
               printf(" -ip   / ip or domain\n");
               printf("\n");
               printf(" -t    / time to marked ping request as fail. Default is - 5000ms\n");
               printf("\n");
               printf(" -help / to show this message\n");
               printf("\n");
               printf("------------------\n");
               printf("| zLab  -  2011  |\n");
               printf("------------------\n");
               getch();
               exit(1);
}
