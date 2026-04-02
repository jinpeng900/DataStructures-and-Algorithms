#include <iostream> 


struct node
{
  int exp ; 
  int coef ; 
  struct node *next;  
};

typedef  struct node * PNODE ;


PNODE createPoly()
{
    PNODE head = (PNODE)malloc(sizeof(struct node));
    head->next = NULL;
    PNODE tail = head;
    while (1)
    {
      int exp;
      int coef;
      scanf("%d %d" , &coef , &exp);
      if (coef == 0)
      {
        break;
      }
      PNODE newnode = (PNODE)malloc(sizeof(struct node));
      newnode->coef = coef;
      newnode->exp = exp;
      newnode->next = NULL;

      tail->next = newnode;
      tail = newnode;
    }

    return head;
} 

PNODE addPoly(PNODE polyAddLeft , PNODE polyAddRight)
{
    // 实现两个多项式相加并返回结果多项式头指针的函数
    PNODE result = (PNODE)malloc(sizeof(struct node));
    result->next = NULL;
    PNODE tail = result;

    PNODE pl = polyAddLeft->next;
    PNODE pr = polyAddRight->next;
    
    while (pl && pr)
    {
      PNODE newnode = (PNODE)malloc(sizeof(struct node));
      newnode->next = NULL;
      if (pl->exp < pr->exp)
      {
        newnode->exp = pl->exp;
        newnode->coef = pl->coef;
        pl = pl->next;
      }
      else if (pl->exp > pr->exp)
      {
        newnode->exp = pr->exp;
        newnode->coef = pr->coef;
        pr = pr->next;
      }
      else
      {
        int sum = pl->coef + pr->coef;
        if (sum == 0)
        {
          free(newnode);
          pl = pl->next;
          pr = pr->next;
          continue;
        }
        else
        {
          newnode->coef = sum;
          newnode->exp = pl->exp;
          pl = pl->next;
          pr = pr->next;
        }
      }
      tail->next = newnode;
      tail = newnode;
    }

    while(pl)
    {
      PNODE newnode = (PNODE)malloc(sizeof(struct node));
      newnode->coef = pl->coef;
      newnode->exp = pl->exp;
      tail->next = newnode;
      tail = newnode;
      pl = pl->next;
    }

    while(pr)
    {
      PNODE newnode = (PNODE)malloc(sizeof(struct node));
      newnode->coef = pr->coef;
      newnode->exp = pr->exp;
      tail->next = newnode;
      tail = newnode;
      pr = pr->next;
    }
    return result;
}  
  
 void printPoly(PNODE poly)
 {
 	
    PNODE curr = poly->next;
    if (curr == NULL)
    {
      printf("0");
      return;
    }
    while (curr)
    {
      if (curr->coef > 0 && curr != poly->next)
      {
        printf("+");
      }
      else if (curr->coef < 0)
      {
        printf("-");
      }

      printf("%dx^%d " , (curr->coef > 0 ) ? curr->coef : -curr->coef , curr->exp);
      curr = curr->next;
    }
    
}  

void destroyPoly(PNODE poly)
{
//释放存储多项式的链表空间
  PNODE curr = poly;
  while(curr)
  {
    PNODE temp = curr;
    free(temp);
    curr = curr->next;
  }
}




int main()
{
  PNODE p = createPoly();
  printPoly(p);
  return 0;
}