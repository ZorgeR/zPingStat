#include <conio.h>
#include <stdio.h>
#include <windows.h>
/*
    zPingStat
    zLab - 2011
    cc-by-nc-sa
    
    r111
*/
 
int main()
{
    int  REDRAW;
    char ping_check,ip;

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
// ip
ip=0;

 
//printTABLE:
  printTABLE:
system("cls");
REDRAW=0;
 
    printf(".-----------------------------------------------------------------.\n");
    printf("|  zPingStat     | IP : %15d   |        Latency        |\n",ip);
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
    printf("`-----------------------------------------------------------------`\n");

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
if (REDRAW==12)
goto getPercentage;
 
//  doPing:
ping_check=system("ping -w 100 -n 1 ya.ru > nul");
 
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
 
if (ping_check == NULL)
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

goto printTABLE;

    getch();
}
