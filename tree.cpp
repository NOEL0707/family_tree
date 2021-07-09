
#include<stdio.h>
/*NAME:P NOEL VINCENT
ROLL NO:1903127*/
class list;
/*THIS A CLASS OF NODE WHICH IS A PART OF A TREE EACH NODE CONTAINS NODE POINTER CALLED PARENT,A LIST POINTER CHILDREN,A NEXT POINTER*/
class node{
private:
    int ele;
    class node* parent;
    class list* children;
    class node* next;
friend class list;
friend class FamilyTree;
};
/*A class Linked List containing head pointer*/
class list{
public:
    class node* head;
    int length;
public:
    list();
    void add(node* x);
friend class FamilyTree;
};
/*constructor for list which takes head as null*/
list::list(){
    //printf("\nhello\n");
    head=NULL;
    length=0;
}
/*add funtion which adds ina list at front*/
void list::add(node* x){
    //printf("\nhello");
    //printf("%d\n",x->ele);
    class node* temp=head;
    //printf("%d\n",x->ele);
    head = new node;
    head = x;
    head->next = temp;
    length++;
}
/*class tree WHICH HAS ONLY ROOT NODE AND HA INSERTCHILD,SEARCH AND RELATIONSHIP FUNCTIONS.*/
class FamilyTree
{
public:
    class node* root;
public:
    FamilyTree(int x);
    //~tree();
    node* search(node* initial,int x);
    void insertChild(int x,int y);
    void relationship(int x,int y);
};
//CONSTRUCTOR
FamilyTree::FamilyTree(int x){
    //root=new node();
    //printf("hello tree constructor");
    root->ele=x;
    root->parent=NULL;
    //root->children=NULL;
    root->next=NULL;
}
/*Search function
Input:root node,and number you want to search
Output:returns the node containing the neede integer*/ 
node* FamilyTree::search(node* initial,int x)
{   
    class node* z;
    if (initial->ele==x){return initial;/*printf("root");*/}
    if (initial->children==NULL){ return NULL;/*printf("children");*/}
    initial=initial->children->head;
    while (initial!=NULL)
    {
        z=search(initial,x);
        if (z!=NULL){return z;}
        initial=initial->next;
        //printf("while");
    }
    return NULL;
}
/*input:takes a parent and child as input
output:adds a child to parent*/
void FamilyTree::insertChild(int x,int y)
{   //printf("INSIDE INSERT");
    node* par=search(root,x);//searches parent
    if (par==NULL){printf("NO SUCH PARENT\n");}
    else{
        //creates new node and points it to parent.
        class node* temp;
        temp=new node();
        temp->ele=y;
        temp->parent=par;
        temp->children=NULL;
        temp->next=NULL;
        //children list is null creates new list else adds.
        if (par->children==NULL){par->children=new list();/*printf("\nin if\n");*/}
        par->children->add(temp);
        printf("added\n");
    }
}
/*Input:two integers
output:prints relationship except nephew or niece relationship*/
void FamilyTree::relationship(int x,int y){
    int i=0;
    class node* check=search(root,y);
    //printf("%d\n",check->ele);
    class node* check1=search(root,x);
    if (check==NULL || check1==NULL)
    {
        printf("Not Related\n");
        return;
    }
    if ( check->parent!=NULL && check->parent->ele==x)
    {
        printf("%d is a parent of %d\n",x,y);
        return ;
    }
    if (check->parent!=NULL)
    {
        if(check->parent->parent!=NULL){
            class node* z=check->parent->parent;
            if (z->ele==x && i==0)
            {
                printf("grand parent of %d is %d\n",y,z->ele);
                return;
            }
            while (z!=root)
            {   

                if (z->ele==x && i==1)
                {
                    printf("great grand parent of %d is %d\n",y,z->ele);
                    i=i+1;
                    return;
                }
                if (z->ele==x && i==2)
                {
                    printf("great great grand parent of %d is %d\n",y,z->ele);
                    i=i+1;
                    return;
                }
                if (z->ele==x && i>2)
                {
                    printf("%d-great grand parent of %d is %d\n",i,y,z->ele);
                    i=i+1;
                    return;
                }
                i=i+1;
                z=z->parent;
            }
            if (z->ele==root->ele && z->ele== x && i>0)
            {   
                if (i==1)
                {
                    printf("great grand parent of %d is %d\n",y,z->ele);
                    i=i+1;
                    return;
                }
                if (i==2)
                {
                    printf("great great grand parent of %d is %d\n",y,z->ele);
                    i=i+1;
                    return;
                }
                else
                {
                    printf("%d-great grand parent of %d is %d\n",i,y,z->ele);
                    i=i+1;
                    return;
                }
                /*printf("%d great grand parent of %d is %d\n",i,y,z->ele);
                return;*/
            }
        }
        //return;
    }
    /*the below while loop prints grand children etc..*/
    int count=-1;
        class node* n=check1;
        while(n!=NULL){
            if (n->ele==y) {
                if (count==0)
                    printf("%d is child of %d\n",x,y);
                if (count==1)
                    printf("%d is grand child of %d\n",x,y);
                if (count==2)
                    printf("%d is great grand child of %d\n",x,y);
                if (count==3)
                    printf("%d is great great grand child of %d\n",x,y);
                if(count>3)
					printf("%d-great grand child of %d is %d\n",count-1,x,y);
				return;
			}
            count++;
            n=n->parent;
        }
    if (check1->parent->ele==y)
    {
        printf("%d is a child of %d\n",x,y);
        return;
    }
    if (check->parent->ele==check1->parent->ele)
    {
        printf("%d is a sibling of %d\n",x,y);
        return;
    }
    if (check->parent->parent->ele==check1->parent->ele)
    {
        printf("%d is aunt/uncle of %d\n",x,y);
        return;
    }
    if (check1->parent!=NULL && check->parent!=NULL)
    {
        int ar[1000];
        int len=0;
        int len1=0;
        int z=0;
        int i,p;
        int count=0;
        int cou=0;
        int ar1[1000];
            class node* k=check->parent;
            class node* j=check1->parent;
            class node* s=check1->parent;
            //printf("ele=%d\n",j->ele);
            //this while loops adds all elements(parent,their parents------till root) above y into a list
            while (k!=NULL)
            {
                ar1[len1]=k->ele;
                //printf("ar1=%d\n",ar1[len1]);
                len1=len1+1;
                k=k->parent;
                //printf("ar1len=%d\n",len1);
            }
            //this while loops adds all elements above y into a list
            while (j!=NULL)
            {
                ar[len]=j->ele;
                //printf("ar=%d\n",ar[len]);
                len=len+1;
                j=j->parent;
                //printf("arlen=%d\n",len);
            }
            /*this two if conditions counts number of elements that are same in the two list*/
            if (len1>=len){z=len1-len;
            for (i = 0; i < len1; i++)
            {
                for ( p = 0; p < len; p++)
                {
                    if(ar1[i]==ar[p]){
                        count=count+1;
                    }
                }
                
            }
            }
            if (len>len1){z=len-len1;
            for (i = 0; i < len; i++)
            {
                for ( p = 0; p < len1; p++)
                {
                    if(ar[i]==ar1[p]){
                        count=count+1;
                    }
                }
            }
            }
            //printf("cou=%d\n",count);
            //if x's parent is in the array of y's parent, their parent list--- then it should be aunt/uncle
            for ( i = 0; i < len1; i++)
            {   //printf("%d,%d\n",ar1[i],i);
                if (s->ele==ar1[i])
                {   //printf("%d",i);
                    cou=cou+1;
                    if (i==2)
                    {
                        printf("great aunt/uncle of %d is %d\n",y,x);
                        return;
                    }
                    if (i==3)
                    {
                        printf("great grand aunt/uncle of %d is %d\n",y,x);
                        return;
                    }
                    if (i==4)
                    {
                        printf("great great grand aunt/uncle of %d is %d\n",y,x);
                        return;
                    }
                    else
                    {
                        printf("%d-great grand aunt/uncle of %d is %d\n",i-1,y,x);
                        return;
                    }
                    // printf("\n cou=%d\n",cou);
                    continue;
                }
                //printf("\n cou=%d\n",cou);
         
            }
            //depending on length of two rows we can find cousin niece/nephew according to the condition defined below.
            if (len-count<=0 || len1-count<=0 )
            {
                class node* o=check1->parent;
                int ar3[1000];
                int len3=0;int p=0;int co=0;
                while (o!=NULL)
                        {
                            ar3[len3]=o->ele;
                            //printf("ar1=%d\n",ar1[len1]);
                            len3=len3+1;
                            o=o->parent;
                            //printf("ar1len=%d\n",len1);
                        }
                for ( p = 0; p < len3; p++)
                {
                    if(check->parent->ele==ar3[p]){
                        break;
                    }
                    co=co+1;
                }
                if (co==0)
                {
                    printf("sibling of %d is %d\n",y,x);
                    return;
                }
                if (co==1)
                {
                    printf("niece/nephew of %d is %d\n",y,x);
                    return;
                }
                if (co==2)
                {
                    printf("grand niece/nephew of %d is %d\n",y,x);
                    return;
                }
                if(co==3)
                {
                    printf("great grand niece/nephew of %d is %d\n",y,x);
                    return;
                }
                if(co==4)
                {
                    printf(" great great grand niece/nephew of %d is %d\n",y,x);
                    return;
                }
                else
                {
                    printf("%d-great niece/nephew of %d is %d\n",co-2,y,x);
                    return;
                }
            }
           
            if (cou!=1 && len1>len)
            {
                printf("%d is %d-cousin %d-removed of %d\n",x,len-count,z,y);
                return;
            }
            if (cou!=1 && len>len1)
            {
                printf("%d is %d-cousin %d-removed of %d\n",x,len1-count,z,y);
                return;
            }
            if (cou!=1 && z==0)
            {
                printf("%d is %d-cousin of %d\n",x,len1-count,y);
                return;
            }
    }
  
}
int main(){
class FamilyTree ft(100);
    ft.insertChild(100,2);
    ft.insertChild(100,6);
    ft.insertChild(100,1112);
    ft.insertChild(2,5);
    ft.insertChild(2,3);
    ft.insertChild(2,7);
    ft.insertChild(6,9);
    ft.insertChild(1112,112);
    ft.insertChild(1112,4);
    ft.insertChild(1112,4);
    ft.insertChild(5,76);
    ft.insertChild(7,48);
    ft.insertChild(3,99);
    ft.insertChild(112,56);
    ft.insertChild(112,65);
    ft.insertChild(4,22);
    ft.insertChild(4,25);
    ft.insertChild(76,1);
    ft.insertChild(76,199);
    ft.insertChild(199,227);
    ft.insertChild(227,245);
    ft.insertChild(245,178);
    ft.insertChild(48,106);
    ft.insertChild(48,11);
    ft.insertChild(99,104);
    ft.insertChild(99,111);
    ft.insertChild(99,110);
    ft.relationship(100,110);
    ft.relationship(6,3);
    ft.relationship(1112,65);
    ft.relationship(4,48);
    ft.relationship(3,178);
    ft.relationship(1112,178);
    ft.relationship(100,178);
    ft.relationship(56,65);
    ft.relationship(25,106);
    ft.relationship(1,4);
    ft.relationship(22,227);
    ft.relationship(227,178);
    ft.relationship(2,106);
    ft.relationship(100,111);
    ft.relationship(2,245);
    ft.relationship(2,104);
    ft.relationship(100,227);
    ft.relationship(100,106);
    ft.relationship(100,11);
    ft.relationship(1000,11);
    ft.relationship(48,5);
   
}  
