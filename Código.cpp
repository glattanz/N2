 /*Nome: Gabrielle Lattanzi
Professor:Sergio Netto
N2 - Prog II
Matrícula: 2001230019
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct residencia{

	int cod, r, t, moradores, inter, rd;
	float cbot, cmes, cmor;
	char codigo[10], reg[10], regiao[10], tp[10], tipo[20], interesse[20], rede[10];
		
};

residencia resp4;

float positivo, negativo;

void preencher(residencia*r, int n){
	
	
	for(int i=0; i<n; i++)
	{
		r[i].cod = 230019 + (rand()% 105);
		r[i].r = 1 + (rand() % 3);
	
	if(r[i].r == 1){
		sprintf(r[i].reg,"A");
		sprintf(r[i].regiao,"Aroeira");
	}
	else if(r[i].r == 2){
		sprintf(r[i].reg,"V");
		sprintf(r[i].regiao,"Visconde");
	}
	else if(r[i].r == 3){
		sprintf(r[i].reg,"M");
		sprintf(r[i].regiao,"Miramar");
	}
	
	r[i].t = rand()% 2;
	
	if(r[i].t == 0){
		sprintf(r[i].tp,"C");
		sprintf(r[i].tipo,"Casa\t");
	}
	else if(r[i].t == 1){
		sprintf(r[i].tp,"A");
		sprintf(r[i].tipo,"Apartamento");
	}
	
	//Código
	sprintf(r[i].codigo,"%d%s%s", r[i].cod, r[i].reg, r[i].tp);
	
	r[i].moradores = 1 + (rand()% 6);
	
	r[i].inter = rand()% 3;
	
	if(r[i].inter == 0){
		sprintf(r[i].interesse,"Indiferente");
	}
	else if(r[i].inter == 1){
		sprintf(r[i].interesse,"Positivo");
	}
	else if(r[i].inter == 2){
		sprintf(r[i].interesse,"Negativo");
	}
	
	r[i].rd = rand()% 2;
	
	if(r[i].rd == 0){
		sprintf(r[i].rede,"Sim");
	}
	else if(r[i].rd == 1){
		sprintf(r[i].rede,"Não");
	}
	
	r[i].cbot = 6 + (rand()% 24);
	
	r[i].cmes = r[i].cbot / 12;
	
	r[i].cmor = r[i].cmes / r[i].moradores;
	}
	
}

void imprimir(residencia*r, int n, float r3, float r5){
	
	printf("Código\t Região\t\tTipo\t  Moradores\tInteresse\tRede\tConMês\tConMor\n");
	
	for(int i=0; i<n; i++)
	{
		printf("%s %s\t%s\t%d\t%s\t%s\t%.2f\t%.2f\n", r[i].codigo, r[i].regiao, r[i].tipo, r[i].moradores, r[i].interesse, r[i].rede, r[i].cmes, r[i].cmor);
	}
	
	printf("\n============================================================\n");
	
	printf("\nQuestão 3: O consumo médio dos pesquisados com interesse positivo: %.2f", r3);

	printf("\n============================================================\n");

	
	printf("\nQuestão 4: O pesquisado de menor consumo:\n");
	printf("%s %s\t%s\t%d\t%s\t%s\t%.2f\t%.2f", resp4.codigo, resp4.regiao, resp4.tipo, resp4.moradores, resp4.interesse, resp4.rede, resp4.cmes, resp4.cmor);
	
	
	printf("\n============================================================\n");
	
	printf("\nQuestão 5: Percentual de pesquisados indiferentes a implantação: %.2f%%", r5);

	printf("\n============================================================\n");

	printf("\nQuestão 6:\nO percentual de pesquisados negativos que tem rede instalada: %.2f%%\nO percentual de pesquisados positivo que não tem rede instalada: %.2f%%", negativo, positivo);
	
}

float q3(residencia*r, int n){
	
	int positivo;
	float consumo;
	
	for(int i=0; i<n; i++)
	{
		if(r[i].inter == 1){
		positivo++;
		consumo += r[i].cmes;
		}
	}
	
	float resp3 = consumo/positivo;
	
	return(resp3);
}

void q4(residencia*r, int n){
	float menor=100;
	
	for(int i=0;i<n;i++){
		if(r[i].cmes<menor){
			menor=r[i].cmes;
			resp4=r[i];
		}
	}
}

float q5(residencia*r, int n){
	
	float indiferente;
	
	for(int i=0; i<n; i++)
	{
		if(r[i].inter == 0)
		{
		indiferente++;
		}
	}
	
	float resp5 = (indiferente/n)*100;
	
	return(resp5);
}

void q6(residencia*r, int n){
	
	float neg, pos;
	
	for(int i=0; i<n; i++)
	{
		if(r[i].inter == 2 && r[i].rd == 0)
		{
			neg++;
		}
		
		
		
		if(r[i].inter == 1 && r[i].rd == 1)
		{
			pos++;
		}
	}
	

	negativo = (neg / n) * 100;
	positivo = (pos / n) * 100;
}



void arquivo(residencia*r, int n, float r3, float r5){
	FILE *arquivo;
	arquivo = fopen("arquivo_N2.txt", "w");
fprintf(arquivo, "Código\t Região\t\tTipo\t  Moradores\tInteresse\tRede\tConMês\tConMor\n");
	
	for(int i=0; i<n; i++)
	{
		fprintf(arquivo, "%s %s\t%s\t%d\t%s\t%s\t%.2f\t%.2f\n", r[i].codigo, r[i].regiao, r[i].tipo, r[i].moradores, r[i].interesse, r[i].rede, r[i].cmes, r[i].cmor);
	}
	
	fprintf(arquivo, "\n============================================================\n");
	
	fprintf(arquivo, "\nQuestão 3: O consumo médio dos pesquisados com interesse positivo: %.2f", r3);

	fprintf(arquivo, "\n============================================================\n");

	fprintf(arquivo, "\nQuestão 4: O pesquisado de menor consumo:\n");
	fprintf(arquivo, "%s %s\t%s\t%d\t%s\t%s\t%.2f\t%.2f\n", resp4.codigo, resp4.regiao, resp4.tipo, resp4.moradores, resp4.interesse, resp4.rede, resp4.cmes, resp4.cmor);
	
	fprintf(arquivo, "\n============================================================\n");
	
	fprintf(arquivo, "\nQuestão 5: Percentual de pesquisados indiferentes a implantação: %f", r5);

	fprintf(arquivo, "\n============================================================\n");

	fprintf(arquivo, "\nQuestão 6:\nO percentual de pesquisados negativos que tem rede instalada: %.2f\nO percentual de pesquisados  positivo que não tem rede instalada: %.2f", negativo, positivo);


	fclose(arquivo);
	printf("\n\nO arquivo foi criado com sucesso!\n");
	
	
}

int main(){
	
	srand(time(NULL));
	fflush(stdin);
	setlocale(LC_ALL, "Portuguese");
	
	residencia r[105];
	
	preencher(r, 105);
	float r3 = q3(r,105);
	q4(r,105);
	float r5 = q5(r,105);
	q6(r,105);
	imprimir(r, 105, r3, r5);
	arquivo(r, 105, r3, r5);
	
	
}
