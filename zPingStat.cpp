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
    
    r135
*/

int main(int argc, char *argv[])
{
    int main_table[2][8];
    int latency_table[3][8];
    float loss[8];
    int build=135;
    int REDRAW,i;
    for(i=0; i<8; i++)
    {  main_table[0][i]=0;
    latency_table[0][i]=0;
                loss[i]=0;
    }
    for(i=0; i<8; i++)
    {  main_table[1][i]=0;
    latency_table[1][i]=0;
    }
    for(i=0; i<8; i++)
    latency_table[2][i]=0;

/*
         main_table             |                latency_table
-----------------------------   |    ------------------------------------
|             |  0   |   1  |   |    |             |  0   |  1   |   2  |
-----------------------------   |    ------------------------------------
|             | ALL  | MISS |   |    |             | MAX  | MIN  | AVG  |
|----------------------------   |    |-----------------------------------
|0 | All time |      |      |   |    |0 | All time |      |      |      |
|---------------------------|   |    |----------------------------------|
|1 | 7day     |      |      |   |    |1 | 7day     |      |      |      |
|---------------------------|   |    |----------------------------------|
|2 | 24hour   |      |      |   |    |2 | 24hour   |      |      |      |
|---------------------------|   |    |----------------------------------|
|3 | 10hour   |      |      |   |    |3 | 10hour   |      |      |      |
|---------------------------|   |    |----------------------------------|
|4 | 1hour    |      |      |   |    |4 | 1hour    |      |      |      |
|---------------------------|   |    |----------------------------------|
|5 | 30min    |      |      |   |    |5 | 30min    |      |      |      |
|---------------------------|   |    |----------------------------------|
|6 | 10min    |      |      |   |    |6 | 10min    |      |      |      |
|---------------------------|   |    |----------------------------------|
|7 | 1min     |      |      |   |    |7 | 1min     |      |      |      |
-----------------------------   |    ------------------------------------
*/

//ARGV check
int ip,iptrue,failtime,failtimetrue,help,ping_check;
ip=iptrue=failtime=failtimetrue=help=ping_check=0;

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
          else if (strcmp(argv[i],"/?") == 0)
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
    printf("zPingStat r135  /  Stat for: %s\n", argv[ip]);
    printf("\n");
printf("           .-----------------------------------------------------,\n");
printf("           | Sent    | Miss    | loss    | max   | min   | avg   |\n");
printf(".----------|-----------------------------------------------------|\n");
printf("| All time | %7d | %7d | %6.2f%% | %3dms | %3dms | %3dms |\n", main_table[0][0],main_table[1][0],loss[0],latency_table[0][0],latency_table[1][0],latency_table[2][0]);
printf("|----------|-------------------|---------|-----------------------|\n");
printf("| 7day     | %7d | %7d | %6.2f%% | %3dms | %3dms | %3dms |\n", main_table[0][1],main_table[1][1],loss[1],latency_table[0][1],latency_table[1][1],latency_table[2][1]);
printf("|----------|-------------------|---------|-----------------------|\n");
printf("| 24hour   | %7d | %7d | %6.2f%% | %3dms | %3dms | %3dms |\n", main_table[0][2],main_table[1][2],loss[2],latency_table[0][2],latency_table[1][2],latency_table[2][2]);
printf("|----------|-------------------|---------|-----------------------|\n");
printf("| 10hour   | %7d | %7d | %6.2f%% | %3dms | %3dms | %3dms |\n", main_table[0][3],main_table[1][3],loss[3],latency_table[0][3],latency_table[1][3],latency_table[2][3]);
printf("|----------|-------------------|---------|-----------------------|\n");
printf("| 1hour    | %7d | %7d | %6.2f%% | %3dms | %3dms | %3dms |\n", main_table[0][4],main_table[1][4],loss[4],latency_table[0][4],latency_table[1][4],latency_table[2][4]);
printf("|----------|-------------------|---------|-----------------------|\n");
printf("| 30min    | %7d | %7d | %6.2f%% | %3dms | %3dms | %3dms |\n", main_table[0][5],main_table[1][5],loss[5],latency_table[0][5],latency_table[1][5],latency_table[2][5]);
printf("|----------|-------------------|---------|-----------------------|\n");
printf("| 10min    | %7d | %7d | %6.2f%% | %3dms | %3dms | %3dms |\n", main_table[0][6],main_table[1][6],loss[6],latency_table[0][6],latency_table[1][6],latency_table[2][6]);
printf("|----------|-------------------|---------|-----------------------|\n");
printf("| 1min     | %7d | %7d | %6.2f%% | %3dms | %3dms | %3dms |\n", main_table[0][7],main_table[1][7],loss[7],latency_table[0][7],latency_table[1][7],latency_table[2][7]);
printf("`----------------------------------------------------------------'\n");
    printf("\n");
printf("* Statistic update every %d query.\n",interval);

// Reset block Start
    if (main_table[0][1]==604800)
        main_table[0][1]=main_table[1][1]=0;
    if (main_table[0][2]==86400)
        main_table[0][2]=main_table[1][2]=0;
    if (main_table[0][3]==36000)
        main_table[0][3]=main_table[1][3]=0;
    if (main_table[0][4]==3600)
        main_table[0][4]=main_table[1][4]=0;
    if (main_table[0][5]==1800)
        main_table[0][5]=main_table[1][5]=0;
    if (main_table[0][6]==600)
        main_table[0][6]=main_table[1][6]=0;
    if (main_table[0][7]==60)
        main_table[0][7]=main_table[1][7]=0;

//REDRAWtable:
  REDRAWtable:
if (REDRAW==interval)
   goto getPercentage;

//  doPing:
    ping_check=system(doping.c_str());

//  Sleep
Sleep(1000);

//  Counter
REDRAW=++REDRAW;

// CHECK
if (ping_check == 0)
     for(i=0; i<8; i++)
         main_table[0][i]=++main_table[0][i];
else
     for(i=0; i<8; i++)
     {   main_table[1][i]=++main_table[1][i];
         main_table[0][i]=++main_table[0][i];
     }

goto REDRAWtable;

//getPercentage:
  getPercentage:
for(i=0; i<8; i++)
loss[i]=main_table[1][i]*100.0/main_table[0][i];

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
               printf(" -ip           / ip or domain\n");
               printf("\n");
               printf(" -t            / time to marked ping request as fail. Default is - 5000ms\n");
               printf("\n");
               printf(" -help or /?   / to show this message\n");
               printf("\n");
               printf("------------------\n");
               printf("| zLab  -  2011  |\n");
               printf("------------------\n");
               getch();
               exit(1);
}
