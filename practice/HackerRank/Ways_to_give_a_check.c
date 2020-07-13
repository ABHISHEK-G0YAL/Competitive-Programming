// https://www.hackerrank.com/contests/w36/challenges/ways-to-give-a-check/problem

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int waysToGiveACheck(char board[8][8]) {
    // Complete this function
    int i,j,p[2]={0},k[2]={},x,y,ys;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(i==1 && board[i][j]=='P' && board[i-1][j]=='#'){
                p[0]=i-1;
                p[1]=j;
                board[i][j]='#';
            }
            if(board[i][j]=='k'){
                k[0]=i;
                k[1]=j;
            }
        }
    }
    x=k[0]-1;
    y=k[1]-p[1];
    if(x==0){
        if(y<0){
            y=k[1]+1;
            while(y<8){
                if(board[1][y]!='#'){
                    if(board[1][y]=='Q' || board[1][y]=='R')return 4;
                    break;
                }
                y++;
            }
        }
        else{
            y=k[1]-1;
            while(y>-1){
                if(board[1][y]!='#'){
                    if(board[1][y]=='Q' || board[1][y]=='R')return 4;
                    break;
                }
                y--;
            }

        }  
    }
    else if(x==abs(y))
        {
            if(y<0)ys=-1;else ys=1;
            x=k[0]-1;
            y=k[1]-ys;
            while(x>-1 && y>-1 && y<8){
                //printf("%d %d ",x,y);
                if(board[x][y]!='#'){
                    if(board[x][y]=='Q'|| board[x][y]=='B')return 4;
                    break;
                }
                x--;
                y-=ys;
            }
        }
    
    j=0;
    x=k[0]-p[0];
    y=k[1]-p[1];
    if(x==0){
        j+=2;
        if(y<0){
            while(y<-1){
                if(board[0][k[1]-y-1]!='#'){
                    j-=2;
                    break;
                }
                y++;
            }
        }
        else{
            while(y>1){
                if(board[0][k[1]-y+1]!='#'){
                    j-=2;
                    break;
                }
                y--;
            }

        }  
    }
    else if(y==0){
        j+=2;

        while(x>2){
            if(board[k[0]-x+2][k[1]]!='#'){
                j-=2;
                break;
            }
            x--;
        }
    }
    else if(x==abs(y)){
        j+=2;
        if(y<0)ys=-1;else ys=1;
        while(x>1){
            if(board[k[0]-x+1][k[1]-y+ys]!='#'){
                j-=2;
                break;
            }
            x--;
            y-=ys;
        }
    }
    else if((abs(x)==1 && abs(y)==2)|| (abs(x)==2 && abs(y)==1)){
        j++;
    }
    return j;
}

int main() {
    int t; 
    scanf("%i", &t);
    for(int a0 = 0; a0 < t; a0++){
        char ch,board[8][8];
        ch=getchar_unlocked();
        for (int board_i = 0; board_i < 8; board_i++) {
           for (int board_j = 0; board_j < 8; board_j++) {
               while(ch=='\n' || ch==' ')ch=getchar_unlocked();
                board[board_i][board_j]=ch;
               ch=getchar_unlocked();
           }
        }
        int result = waysToGiveACheck(board);
        printf("%d\n", result);
    }
    return 0;
}