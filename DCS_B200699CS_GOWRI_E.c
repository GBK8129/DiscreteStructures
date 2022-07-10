#include<stdio.h>
#include<stdlib.h>
int C[10000];
int VertexStack[10000][2];
int Inter[10000][2];
int top=-1;
void Push(int A,int B)
{
    top++;
    VertexStack[top][0]=A;
    VertexStack[top][1]=B;
}
void Pop()
{
    top--;
}
void Eulerian(int A[][2],int c,int m) //Recursively removes each vertex to check the condition
{
    if(c==0)
    {Push(A[0][0],A[0][1]);}
      int junk=-2;
    if(c<m-1)
    {
        for(int j=1;j<m;j++)
        {
            if(A[0][0]==A[j][0])
            {
                //printf("%d %d\n",A[j][0],A[j][1]);
                Push(A[j][0],A[j][1]);
                A[j][0]=A[0][1]; 
                C[top]=A[0][0];
                
                A[0][0]=A[j][0];
                A[0][1]=A[j][1];
                A[j][0]=junk;
                A[j][1]=junk;
                //printf("%d %d\n",A[i][0],A[i][1]);
                //printf("%d %d\n",A[j][0],A[j][1]);
                //i++;
                //Eulerian(A,i,n,m);
            }
           else if(A[0][0]==A[j][1])
            {
                Push(A[j][0],A[j][1]);
                A[j][1]=A[0][1]; 
                C[top]=A[0][0];
               
                A[0][0]=A[j][0];
                A[0][1]=A[j][1];
                A[j][0]=junk;
                A[j][1]=junk;
                //printf("%d %d\n",A[i][0],A[i][1]);
                //printf("%d %d\n",A[j][0],A[j][1]);
                //i++;
                //Eulerian(A,i,n,m);
            }
            else if(A[0][1]==A[j][0])
            {
                //printf("%d %d\n",A[j][0],A[j][1]);
                Push(A[j][0],A[j][1]);
                A[j][0]=A[0][0];
                C[top]=A[0][1]; 
                
                A[0][0]=A[j][0];
                A[0][1]=A[j][1];
                A[j][0]=junk;
                A[j][1]=junk;
                //printf("%d %d\n",A[i][0],A[i][1]);
                //printf("%d %d\n",A[j][0],A[j][1]);
                //i++;
                //Eulerian(A,i,n,m);
            }
            else if(A[0][1]==A[j][1])
            {
                Push(A[j][0],A[j][1]);
                A[j][1]=A[0][0]; 
                C[top]=A[0][1];
                
                A[0][0]=A[j][0];
                A[0][1]=A[j][1];
                A[j][0]=junk;
                A[j][1]=junk;
                //printf("Mhmm%d %d\n",A[i][0],A[i][1]);
                //printf("Lol%d %d\n",A[j][0],A[j][1]);
                //i++;
                //Eulerian(A,i,n,m);
            }
            Inter[top][0]=A[0][0]; Inter[top][1]=A[0][1];
        }
    }
    else 
    {return;}
    c++; 
    Eulerian(A,c,m);

}
int EulerChecker(int A[][2],int m)
{
    Eulerian(A,0,m);
    
    /*for(int j=0;j<m;j++)
    {printf("%d %d\n",A[j][0],A[j][1]);}*/
    int i=m-1; int count=0; int true=0;
    for(int k=0;k<m;k++)
    {
        if(A[k][0]==(-2) && A[k][1]==(-2))
        {count++;}
    }
    if(count==(m-1))
    {true=1;}
    
    if(A[0][0]==A[0][1] && true==1)
    {return 1;}
    else
    {return 0;}
}
void ReEulerian(int A[][2],int m,int i) //Recursively Builds back the Graph if Eulerian
{
    if(i>m-2)
    {return;}
    if(Inter[top-1][0]==Inter[top][0])
    {
        A[i][0]=Inter[top][1];
        A[i][1]=Inter[top-1][1];
    }
    else if(Inter[top-1][1]==Inter[top][0])
    {
       A[i][0]=Inter[top][1];
       A[i][1]=Inter[top-1][0];
    }
    else if(Inter[top-1][0]==Inter[top][1])
    {
       A[i][0]=Inter[top][0];
       A[i][1]=Inter[top-1][1];
    }
    else if(Inter[top-1][1]==Inter[top][1])
    {
       A[i][0]=Inter[top][0];
       A[i][1]=Inter[top-1][0];
    }
    Pop();
    i++;
    ReEulerian(A,m,i);
}

void EulerianPrint(int A[][2],int m) //Forms the Path
{
     int i; int C;
     /*struct Vertex *P=NULL;
     P=(struct Vertex*)malloc(m*sizeof(struct Vertex));
     
     P->X=A[0][0];
     P->Y=A[0][1];
     P->Pre=NULL;
     P->Nex=NULL;*/
     printf("%d %d\n",A[0][0],A[0][1]);
     C=A[0][1];
     A[0][0]=-2;
     A[0][1]=-2;
     int j=0;
     while(j<m)
     {
     for(i=1;i<m;i++)
     {
         /*while(P->Nex!=NULL)
         {printf("UFF\n");
             P=P->Nex;
         }*/
         if(A[i][0]==C && A[i][0]!=(-2))
         {
             /*struct Vertex *temp=NULL;
             temp->X=C;
             temp->Y=A[i][1];*/
             printf("%d %d\n",A[i][0],A[i][1]);
             C=A[i][1];
             A[i][0]=-2;
             A[i][1]=-2;
             /*temp->Nex=NULL;
             
             temp->Pre=P;
             P->Nex=temp;*/
         }
         else if(A[i][1]==C && A[i][1]!=(-2))
         {
             /*struct Vertex *temp=NULL;
             temp->X=C;
             temp->Y=A[i][0];*/
             printf("%d %d\n",A[i][1],A[i][0]);
             C=A[i][0];
             A[i][0]=-2;
             A[i][1]=-2;
             /*temp->Nex=NULL;
             temp->Pre=P;
             P->Nex=temp; */
         }
     }
     j++;
     }
    //Print(P,m);
}
int main()
{
     int n; int m; scanf("%d",&n);scanf("%d",&m);
    int A[m][2],B[m][2];
    int i;
    //int C[m-1];
    struct Vertex *P=NULL;
    //
    for(i=0;i<m;i++)
    {scanf("%d %d",&A[i][0],&A[i][1]);}
    /*for(i=0;i<m;i++)
    { 
      if(P==NULL)
      {
          P->V[0][0]=A[i][0];
          P->V[0][1]=A[i][1];
          P->Nex=NULL;
          P->Pre=NULL;
      }
      else
      {
          while(P!=NULL)
          { 
              printf("SIVU\n");
              if(P->Nex==NULL) {
              P->Nex->Pre=P;
              P->Nex->V[0][0]=A[i][0];
              P->Nex->V[0][1]=A[i][1];
              break; }
              P=P->Nex;
          }
         
      }

    }*/
    /*for(int j=0;j<m;j++)
    {printf("%d %d\n",A[j][0],A[j][1]);}*/
    for(i=0;i<m;i++)
    {B[i][0]=A[i][0]; B[i][1]=A[i][1];}
    int ret;
    ret=EulerChecker(A,m);
    /*for(i=0;i<m-1;i++)
    {
        printf("%d %d\n",A[i][0],A[i][1]);
    }*/
    /*for(i=0;i<m-1;i++)
    {
        printf("%d ",C[i]);
    }
    printf("\n");*/

    if(ret==1)
    {
       
       /*for(i=0;i<=top;i++)
       {
           printf("%d %d Eject: %d\n",VertexStack[i][0],VertexStack[i][1],C[i]);
       }*/
       ReEulerian(A,m,0);
       A[m-2][0]=Inter[top+1][1];
       A[m-2][1]=C[1];
       //Pop();
       A[m-1][0]=C[1];
       A[m-1][1]=Inter[top+1][0];
       /*printf("After :\n");
       for(i=0;i<m;i++)
    {
        printf("%d %d\n",A[i][0],A[i][1]);
    } */
       EulerianPrint(A,m);
    }
    else if(ret==0)
    {
        printf("Not Eulerian");
        return 0;
    }
}