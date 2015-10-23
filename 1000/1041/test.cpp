// 1041.Pushing Boxes
// 每次推动最大次数 <= 总长度-箱子数
// 题目默认推动箱子时，推动路线上如果已被箱子顶住，则不继续推动 

#include <algorithm>
#include <stdio.h>
#include <string>
  
using namespace std;

struct Box{
    int x,y;    
};

Box box[11];
int row,column,num;

int maxRowStep();               // 沿行方向，最多可以移动多少步 
int maxColumnStep();            // 沿列方向，最多可以移动多少步 

bool comp_up( const Box& b1, const Box& b2 ){
    if( b1.y != b2.y ) return b1.y < b2.y;
    else return b1.x > b2.x;
}

bool comp_down( const Box& b1, const Box& b2 ){
    if( b1.y != b2.y ) return b1.y < b2.y;
    else return b1.x < b2.x;
}

bool comp_left( const Box& b1, const Box& b2 ){
    if( b1.x != b2.x ) return b1.x < b2.x;
    else return b1.y > b2.y;
}

bool comp_right( const Box& b1, const Box& b2 ){
    if( b1.x != b2.x ) return b1.x < b2.x;
    else return b1.y < b2.y;
}

void move_up( int step );
void move_down( int step );
void move_right( int step );
void move_left( int step );

int main () {
    //freopen("D:\\input.txt","r",stdin); 
    int x,y,step,cnt = 1;
    char op[5]; 
    
    while( scanf("%d%d",&row,&column) && row != 0){
        
        scanf("%d",&num);
        for( int i = 0; i < num; ++i ){
            Box b;
            scanf("%d%d",&b.x,&b.y);
            box[i] = b;         
        }
    
        scanf("%s",op);
        string str = op;
        
        while( str != "done" ){           
            if( str == "up" ){
                scanf("%d",&step);
                move_up(step);
            }else if( str == "down" ){
                scanf("%d",&step);
                move_down(step);
            }else if( str == "right" ){
                scanf("%d",&step);
                move_right(step);
            }else if( str == "left" ){
                scanf("%d",&step);
                move_left(step);
            }
            scanf("%s",op);
            str = op;
        }     
        
        sort( box,box+num,comp_right );
        printf("Data set %d ends with boxes at locations ",cnt++);
        for( int i = 0; i < num - 1; ++i ){
            printf("(%d,%d) ", box[i].x, box[i].y );
        }
        printf("(%d,%d).\n", box[num-1].x, box[num-1].y ); 
    }    
            
    return 0;  
}  

// 沿行方向，最多可以移动多少步 
int maxRowStep(){
    int maxs = 0;  
    
    // 遍历每一行得到同行中箱子个数最大值 
    for( int i = 0; i < row; ++i ){
        int nb = 0;
        for( int j = 0; j < num; ++j ){ 
            if( box[j].x == i ) 
                nb++;
        }    
        if( nb > maxs ) maxs = nb;    
    }
    return column - maxs;
}

// 沿列方向，最多可以移动多少步 
int maxColumnStep(){
    int maxs = 0;  
    
    // 遍历每一列得到同行中箱子个数最大值 
    for( int i = 0; i < column; ++i ){
        int nb = 0;
        for( int j = 0; j < num; ++j ){ 
            if( box[j].y == i ) 
                nb++;
        }    
        if( nb > maxs ) maxs = nb;    
    }
    return row - maxs;  
}

void move_up( int step ){
    
    // 取期望步长与实际步长的较小值
    // 若实际步长较小则移动，若实际步长较小则只可以移动实际步数 
    int actual_step = min( maxColumnStep(), step );
    sort(box,box+num,comp_up); 
    
    int x,y = -1;   // y = -1 代表第一列，之前没有列与之一列 
    for( int i = 0; i < num; ++i ){
        if( box[i].y != y ){    // 若 当前列 与 之前列 不为一列，则记录实际移动最大处 
            x = row - actual_step - 1;
            y = box[i].y;    
        }else{                  // 若为一列 则记录前一个箱子位置的更靠墙的一个位置 
            x--;    
        }
        
        if( box[i].x > x )      // 移动箱子 
            box[i].x = x;    
    }  
}

void move_down( int step ){
    
    int actual_step = min( maxColumnStep(), step );
    sort(box,box+num,comp_down); 
    
    int x,y = -1;
    for( int i = 0; i < num; ++i ){
        if( box[i].y != y ){
            x = actual_step;
            y = box[i].y;    
        }else{
            x++;    
        }
        
        if( box[i].x < x )
            box[i].x = x;
    } 
}

void move_left( int step ){
    
    int actual_step = min( maxRowStep(), step );
    sort(box,box+num,comp_left); 
    
    int x = -1,y;
    for( int i = 0; i < num; ++i ){     
        if( box[i].x != x ){
            y = column - actual_step - 1;
            x = box[i].x;    
        }else{
            y--;    
        }
        
        if( box[i].y > y )
            box[i].y = y;    
    } 
}

void move_right( int step ){
    
    int actual_step = min( maxRowStep(), step );
    sort(box,box+num,comp_right); 
    
    int x = -1,y;
    for( int i = 0; i < num; ++i ){
        if( box[i].x != x ){
            y = actual_step;
            x = box[i].x;    
        }else{
            y++;    
        }
        
        if( box[i].y < y )
            box[i].y = y;   
    } 
}