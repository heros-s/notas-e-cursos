/*
	atividade 1 de algoritmos (1.0)
	
	imagine que a disciplina de algoritmos possui estudantes do curso de BSI e do curso de ADS
	o professor precisa lancar as notas de todos os estudantes, mas gerar estatisticas separadas para cada curso
	se o estudante tirar mais que 7.0 ele eh aprovado, se tirar menos que 3.0 ele eh reprovado, caso contrario fica de final
	implemente um programa em que o usuario possa inserir uma quantidade qualquer de notas
	o programa deve comecar exibindo uma mensagem de boas-vindas e explicando o que o usuario deve fazer
	ao inserir cada nota o usuario devera informar tambem o curso do estudante
	nao eh permitido inserir primeiro os de um curso e depois do outro, as notas devem poder ser inseridas em qualquer ordem
	apos todas as notas terem sido inseridas, o programa deve informar:
		- qual a media geral de cada curso
		- quantos estudantes de cada curso foram reprovados
		- quantos estudantes de cada curso ficaram de final
		- quantos estudantes de cada curso foram aprovados
		- qual o percentual total de alunos aprovados
		- qual curso teve mais notas acima de 9.0
		- quantos estudantes tiraram zero
	por fim o programa deve perguntar se o usuario quer repetir o processo, caso sim voltar ao inicio, caso nao deve se despedir e encerrar
*/

  //Alunos : Heros Dinão
  //Curso : BSI

#include <stdio.h>
#include <stdlib.h>

int main() {
    int repetir;

    do {
        float notasDigitadas = 0, notasEstudantesADS = 0, notasEstudantesBSI = 0, mediaBSI = 0, mediaADS = 0, percentualTotal = 0;
        int alunosTotais = 0, cursoEscolha = 0, aprovadosTotais = 0, aprovadosBSI = 0, aprovadosADS = 0, reprovadosBSI = 0, reprovadosADS = 0, finalBSI = 0, finalADS = 0, BSI9 = 0, ADS9 = 0, zero = 0;

        printf("\nBem-vindo ao calculador de notas master! Insira o curso e, em seguida, a nota do estudante!");

        while (1) {
            printf("\nInsira o curso do estudante (1 para ADS, 2 para BSI, 0 para encerrar): ");
            scanf("%d", &cursoEscolha);

            if (cursoEscolha == 1 || cursoEscolha == 2) {
                alunosTotais++;
                printf("\nInsira a nota do estudante: ");
                scanf("%f", &notasDigitadas);

                if (notasDigitadas < 3) {
                    if (cursoEscolha == 1) {
                        reprovadosADS++;
                    } else {
                        reprovadosBSI++;
                    }
                    if (notasDigitadas == 0) {
                        zero++;
                    }
                } else if (notasDigitadas >= 3 && notasDigitadas < 7) {
                    if (cursoEscolha == 1) {
                        finalADS++;
                    } else {
                        finalBSI++;
                    }
                } else if (notasDigitadas >= 7) {
                    if (cursoEscolha == 1) {
                        aprovadosADS++;
                    } else {
                        aprovadosBSI++;
                    }
                    aprovadosTotais++;

                    if (notasDigitadas >= 9) {
                        if (cursoEscolha == 1) {
                            ADS9++;
                        } else {
                            BSI9++;
                        }
                    }
                }

                if (cursoEscolha == 1) {
                    notasEstudantesADS += notasDigitadas;
                } else {
                    notasEstudantesBSI += notasDigitadas;
                }
            } else if (cursoEscolha == 0) {
                break;
            } else {
                printf("Opcao de curso invalida. Tente novamente.\n");
            }
        }

        if (alunosTotais > 0) {
            mediaADS = notasEstudantesADS / alunosTotais;
            mediaBSI = notasEstudantesBSI / alunosTotais;
            percentualTotal = ((float)aprovadosTotais / alunosTotais) * 100.0;

            printf("\nA media geral do curso de ADS eh: %.2f, e BSI eh: %.2f", mediaADS, mediaBSI);

            printf("\n%i estudantes de ADS reprovaram e %i estudantes de BSI reprovaram", reprovadosADS, reprovadosBSI);
            printf("\n%i estudantes de ADS ficaram de prova final, e %i estudantes de BSI ficaram de prova final", finalADS, finalBSI);
            printf("\n%i estudantes de ADS passaram, e %i estudantes de BSI passaram", aprovadosADS, aprovadosBSI);

            printf("\nO percentual de alunos aprovados eh: %.2f%%", percentualTotal);

            if (BSI9 > ADS9) {
                printf("\nO curso que teve mais alunos que tiraram acima de 9 eh BSI, com %i alunos.", BSI9);
            } else if (ADS9 > BSI9) {
                printf("\nO curso que teve mais alunos que tiraram acima de 9 eh ADS, com %i alunos.", ADS9);
            } else {
                printf("\nOs dois cursos empataram em notas acima de 9.");
            }

            printf("\nO numero de estudantes que tiraram zero eh: %i", zero);
        } else {
            printf("\nNenhum dado foi inserido.");
        }

        printf("\nDigite 0 para encerrar ou qualquer outro numero para repetir o processo: ");
        scanf("%d", &repetir);
    } while (repetir != 0);

    return 0;
}