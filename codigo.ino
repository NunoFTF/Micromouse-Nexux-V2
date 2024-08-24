


int flood[16][16] = {
                        {14,13,12,11,10,9,8,7,7,8,9,10,11,12,13,14},
                        {13,12,11,10,9,8,7,6,6,7,8,9,10,11,12,13},
                        {12,11,10,9,8,7,6,5,5,6,7,8,9,10,11,12},
                        {11,10,9,8,7,6,5,4,4,5,6,7,8,9,10,11},
                        {10,9,8,7,6,5,4,3,3,4,5,6,7,8,9,10},
                        {9,8,7,6,5,4,3,2,2,3,4,5,6,7,8,9},
                        {8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8},
                        {7,6,5,4,3,2,1,0,0,1,2,3,4,5,6,7},
                        {7,6,5,4,3,2,1,0,0,1,2,3,4,5,6,7},
                        {8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8},
                        {9,8,7,6,5,4,3,2,2,3,4,5,6,7,8,9},
                        {10,9,8,7,6,5,4,3,3,4,5,6,7,8,9,10},
                        {11,10,9,8,7,6,5,4,4,5,6,7,8,9,10,11},
                        {12,11,10,9,8,7,6,5,5,6,7,8,9,10,11,12},
                        {13,12,11,10,9,8,7,6,6,7,8,9,10,11,12,13},
                        {14,13,12,11,10,9,8,7,7,8,9,10,11,12,13,14}
}

int wall[16][16] = {
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
}


int orientupdt (int orient, int turn){

  if (turning== 1){

        orient-=1;

        if (orient==-1){
            orient=3;
        }
  }
  else if(turning== 2){
        orient+=1;

        if (orient==4){

            orient=0;
            }
  }
  else if (turning== 3){
        if (orient==0){
            orient=2;
            }
        else if (orient==1){
            orient=3;
            }
        else if (orient==2){
            orient=0;
            }
        else if (orient==3){
            orient=1;
            }
  }
  return(orient);

}
}

int coordupdt (int x, int y, int orient){

if(orient==0){
  y+=1;
}
if(orient==1){
  x+=1;
}
if(orient==2){
  y-=1;
}
if(orient==3){
  x-=1;
}

}

void wallupdt(int x, int y, int orient, bool l, bool r, bool f){

  if(l == True && r == True && f==True){

    if(orient ==0){
      wall[y][x]= 13;
    }
    else if(orient==1){
      wall[y][x]= 12;
    }
    else if(orient==2){
      wall[y][x]= 11;
    }
    else if(orient==3){
      wall[y][x]= 14;
    }

  }

  else if(l == True && r == True && f == False){

    if(orient==0 || orient ==2){
      wall[y][x]= 9;
    }
    else if(orient==1 || orient==3){
      wall[y][x]= 10;
    }
  }

  else if (l == True && r == false && f == True){

    if(orient==0){
      wall[y][x]= 8;
    }
    else if(orient==1){
      wall[y][x]= 7;
    }
    else if(orient==2){
      wall[y][x]= 6;
    }
    else if(orient==3){
      wall[y][x]= 5;
    }
  }

  else if(l == False || r == True || f == True){

    if(orient==0){
      wall[y][x]= 7;
    }
    else if(orient==1){
      wall[y][x]= 6;
    }
    else if(orient==2){
      wall[y][x]= 5;
    }
    else if(orient==3){
      wall[y][x]= 8;
    }
    
  }
    else if(l == False || r == False || f == True){

    if(orient==0){
      wall[y][x]= 2;
    }
    else if(orient==1){
      wall[y][x]= 3;
    }
    else if(orient==2){
      wall[y][x]= 4;
    }
    else if(orient==3){
      wall[y][x]= 1;
    }
    
  }
    else if(l == True || r == False || f == False){

    if(orient==0){
      wall[y][x]= 1;
    }
    else if(orient==1){
      wall[y][x]= 2;
    }
    else if(orient==2){
      wall[y][x]= 3;
    }
    else if(orient==3){
      wall[y][x]= 4;
    }
    
  }
    else if(l == False || r == True || f == False){

    if(orient==0){
      wall[y][x]= 3;
    }
    else if(orient==1){
      wall[y][x]= 4;
    }
    else if(orient==2){
      wall[y][x]= 1;
    }
    else if(orient==3){
      wall[y][x]= 2;
    }
    
  }
    else if(l == False || r == False || f == False){

      wall[y][x]= 15; 
  }

}

bool accessible(int x, int y, int x1, int y1){

  if(x==x1){

    if(y>y1){

      if(maze[y][x]==4 || maze[y][x]==5 || maze[y][x]==6 || maze[y][x]==10 || maze[y][x]==11 || maze[y][x]==12 || maze[y][x]==14 || maze[y1][x1]==2 || maze[y1][x1]==7 || maze[y1][x1]==8 || maze[y1][x1]==10 || maze[y1][x1]==12 || maze[y1][x1]==13 || maze[y1][x1]==14){
        return False;
      }
      else return True;
    }
    else{
      if(maze[y][x]==2 || maze[y][x]==7 || maze[y][x]==8 || maze[y][x]==10 || maze[y][x]==12 || maze[y][x]==13 || maze[y][x]==14 || maze[y1][x1]==4 || maze[y1][x1]==5 || maze[y1][x1]==6 || maze[y1][x1]==10 || maze[y1][x1]==11 || maze[y1][x1]==12 || maze[y1][x1]==14){
        return False;
      }
      else return True;
    }

  }
  else if(y==y1){
    if(x>x1){
       if(maze[y][x]==1 || maze[y][x]==5 || maze[y][x]==8 || maze[y][x]==9 || maze[y][x]==11 || maze[y][x]==13 || maze[y][x]==14 || maze[y1][x1]==3 || maze[y1][x1]==6 || maze[y1][x1]==7 || maze[y1][x1]==9 || maze[y1][x1]==11 || maze[y1][x1]==12 || maze[y1][x1]==13){
        return False;
      }
      else return True;     
    }
    else{
      if(maze[y][x]==3 || maze[y][x]==6 || maze[y][x]==7 || maze[y][x]==9 || maze[y][x]==11 || maze[y][x]==12 || maze[y][x]==13 || maze[y1][x1]==1 || maze[y1][x1]==5 || maze[y1][x1]==8 || maze[y1][x1]==9 || maze[y1][x1]==11 || maze[y1][x1]==13 || maze[y1][x1]==14){
        return False;
      }
      else return True;      
    }
  }
}

struct coordenadas getSurrounds(int x, int y){

struct coordenadas estrutura;

estrutura.a3 = x-1;
estrutura.y3 = y;
estrutura.a0 = x;
estrutura.y0 = y+1;
estrutura.a1 = x+1;
estrutura.y1 = y;
estrutura.a2 = x;
estrutura.y2 = y-1;

if(estrutura.a1 >= 16){
  estrutura.a1=-1;

}
if(estrutura.b0 >= 16){
  estrutura.b0=-1;
}

return estrutura;
}















