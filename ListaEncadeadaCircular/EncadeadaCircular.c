//Baseado em solução de Lucas Beriba
#include "EncadeadaCircular.h"
#include <stdio.h>
#include <stdlib.h>

struct no {
  int id; 
  tNo* prox;
};

struct LSE {
  tNo* prim;
  int qtdNos;
  int isClassif, comRepet;
};

int busca(tLSE* pL, int id, tNo** pAnt);

tNo* criaNo(int id);

int lstSE_isClassif(tLSE* pL){
  return pL->isClassif;
}

int lstSE_comRepet(tLSE* pL){
  return pL->comRepet;
}

int lstSE_isVazia(tLSE* pL){
  return pL->qtdNos;
}

tLSE* lstSE_criaLista(int isClassif, int comRepet){
  tLSE* pL = (tLSE*) malloc(sizeof(tLSE));//cabeça
  
  if (pL){
  
    pL->qtdNos = 0;
    pL->isClassif = isClassif;
    pL->comRepet = comRepet;
    pL-> prim=criaNo(0);
    pL->prim->prox=pL->prim;
  }
  return pL;
}
int lstSE_inclui(tLSE* pL, int id){
  tNo *pNovo, *pAnt, *pAtual;
  int isClassif, comRepet, sit;

  isClassif = lstSE_isClassif(pL);
  comRepet = lstSE_comRepet(pL);

   if (!isClassif && comRepet){  
     pAnt=pL->prim;
     sit=0;
   }
  else{
    sit = busca(pL, id, &pAnt);
  }
  if (sit &&  !comRepet)
    return -1; //inclusão de existente em sem repetição
  pNovo = criaNo(id);
  pNovo->prox = pAnt->prox;
  pAnt->prox = pNovo;
  
  
  pL->qtdNos += 1;
  return 1;
  
}
void lstSE_imprime(tLSE* pL){
  tNo* p = pL->prim->prox;
  
  while (p!=pL->prim) {
    printf("\n%d ", p->id);
    p = p->prox;
  }

  puts("");
  
  return;
}

int lstSE_exclui(tLSE* pL, int id){
  tNo *pSuc = NULL, *pAnt = NULL, *pAtual = NULL,*p;
  int isClassif,comRepet, existe, qtdDel = 0;

  isClassif = lstSE_isClassif(pL);
  comRepet = lstSE_comRepet(pL);
  existe = busca(pL, id, &pAnt);
  //printf("\n %x %x",pAnt,pAnt->prox);
  
  if (existe==0)
    return -1; // exclusão de inexistente
  
  if (!comRepet){
      pAtual=pAnt->prox;
      pAnt->prox=pAtual->prox;
      free(pAtual);
      pL->qtdNos -= 1;
  }
  else{
    p=pAnt->prox;
    
    if (isClassif) {
         
      while(p!=pL->prim&&p->id == id){
          pSuc=p->prox;  
          free(p);
          qtdDel++;
          p=pSuc;
      }
      pAnt->prox=p;
        
    }
    else{
      
      while(p!=pL->prim){
        if (p->id==id){
          pSuc=p->prox;
          pAnt->prox=pSuc;
          free(p);
          qtdDel++;
          p=pSuc;
        }
        else{
          pAnt=p;
          p=p->prox;
        }
      }
    }
  }  
    
  
  return qtdDel;
  }

int busca(tLSE* pL, int id, tNo** pAnt){
  int isClassif = lstSE_isClassif(pL);
  int comRepet = lstSE_comRepet(pL);
  tNo *p,*pRast;
  pL->prim->id=id;
  if (isClassif){
    for (p = pL->prim->prox,pRast = pL->prim; p->id < id;pRast=p,p=p->prox);
 }
 else{
   for (p = pL->prim->prox,pRast = pL->prim; p->id != id;pRast=p,p=p->prox);
 }
  (*pAnt)=pRast;
  
  return (p!=pL->prim && p->id == id);
}


tNo* criaNo(int id){
  tNo* no = (tNo*) malloc(sizeof(tNo));

  no->id = id;
  no->prox = NULL;

  return no;
}
