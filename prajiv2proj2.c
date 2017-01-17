#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack_struct                                                         //Creating a structure
{    char *items;
    int size;
    int top;

}StackStruct;                                                                       //Structure Object

void stk_create(StackStruct *s){                                                    //Stack Creating Function
    
    s->items = malloc(sizeof(struct stack_struct));
    s->size=2;
    s->top = -1;  // stack initially empty

   
}

void grow(StackStruct* s,int debug)                                                 //Fuction which helps stack grow
{

        char* temp = (char *) malloc ( sizeof(char) * (s->size + 2) );

            for (int  i=0 ; i<s->size ;i++ )
                     temp[i] = s->items[i];
            if(debug==0)
            {
            printf("\nInitial size=%d\n",s->size);
            printf("\nNumber of Values Copied=%d\n",s->size);
            printf("\nFinal size=%d\n",s->size+2);
            }   
              free (s->items);
                s->items = temp;
                  s->size = s->size + 2;

}

void stk_push(StackStruct *s, char val,int debug)                                   //Fuction that helps to push element inside the stack
{
    if(s->top+1 >= s->size)
        grow(s,debug);   
    s->top++;
    s->items[s->top] = val;
}

int stk_pop(StackStruct *s)                                                         //Fuction that helps to pop element inside the stack
{

     s->top--; 
 return 0;
}


int stk_is_empty(StackStruct* s){                                                   //Fuction that checks if the stack is empty
   
   if(s->top == -1)
       return 1;
   else
       return 0;
}

char topFun(StackStruct* s)                                                         //Fuction that gives the top value of the stack
{
      return s->items[s->top];
}

int reset(StackStruct *s)                                                           //Fuction that sets the stack to initial position
{    
stk_create(s);
return 0;
}




void stk_print(StackStruct s) {                                                     //Fuction that prints the elements inside the stack
char topVar=topFun(&s);
    if(s.top==-1)    
printf("\nThis String is Balanced\n\n");
else
    {
    printf("\nThis String is not Balanced\n\n");
    if(topVar=='{')    
            printf("Expecting }\n");
    if(topVar=='}')
            printf("Missing {\n");
    if(topVar=='<')
            printf("Expecting >\n");
    if(topVar=='>')
            printf("Missing <\n");
    if(topVar=='[')
            printf("Expecting ]\n");
    if(topVar==']')
            printf("Missing [\n");
    if(topVar=='(')
            printf("Expecting )\n");
    if(topVar==')')
            printf("Missing (\n");
    }
}




int main(int argc,char* argv[])                                                     //main function 
{
            int b;                                                                  //b stores the size
            StackStruct sptr;
            char debug[2]="-d";
            int strcomp=1;
            if(argv[1])
                {strcomp = strcmp(argv[1],debug);
                if(strcomp==0)
                printf("\n\nDEBUG MODE\n");
                }



            if(!argv[1] || (strcomp==0))
                { 
                     stk_create(&sptr);
                     for(int i=0;i!=-1;)
                    {    
                         printf("\n\nEnter String or Press q or Q to quit");
                         char st[300];
                         fgets(st,300,stdin);
                         b=0;
                         for(int x=0;st[x]!='\0';x++)
                            {
                            b++;
                            if(st[x]=='q'||st[x]=='Q')
                            exit(0);
                            }
                        b=b-1;
                        for(int x=0;x<b;x++)
                            {if(((sptr.items[sptr.top]=='{')&&(st[x]=='}'))||((sptr.items[sptr.top]=='[')&&(st[x]==']'))||((sptr.items[sptr.top]=='(')&&(st[x]==')'))||((sptr.items[sptr.top]=='<')&&(st[x]=='>')))
                            { 
                            if(argv[1] && (strcomp==0))
                            printf("\nThe Value being poped is %c\n",sptr.items[sptr.top]);
                            stk_pop(&sptr);
                            }    
                            else 
                            {
                            if((st[x]=='{')||(st[x]=='}')||(st[x]=='(')||(st[x]==')')||(st[x]=='[')||(st[x]==']')||(st[x]=='<')||(st[x]=='>'))
                                 {stk_push(&sptr,st[x],strcomp);
                                 if(argv[1] && (strcomp==0))
                                 printf("\nThe Value being pushed is %c\n",st[x]);
                                 }        
                            }

                            }
                            stk_print(sptr);
                            reset(&sptr);
                    }               
                }
            else
                if((strcomp!=0))
                printf("\nUnknown Flag Variable\n\n");

}
