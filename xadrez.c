#include <stdio.h>

// Definindo constantes. 
// Boa prática: evita "magic numbers" espalhados pelo código e facilita mudanças futuras.
#define CIMA "Cima"
#define BAIXO "Baixo"
#define ESQUERDA "Esquerda"
#define DIREITA "Direita"

#define PASSOS_BISPO 5
#define PASSOS_TORRE 5
#define PASSOS_RAINHA 8
#define PASSOS_CAVALO 1

// --- Funções Auxiliares (Nível Mestre) ---

// Função recursiva: ela chama a si mesma até que 'casas' chegue a 0.
// Substitui o loop tradicional.
void moverTorreRecursivo(int casas) {
    if (casas > 0) {
        printf("%s\n", DIREITA);
        moverTorreRecursivo(casas - 1);
    }
}

// Mesma lógica recursiva, mas para a Rainha.
void moverRainhaRecursivo(int casas) {
    if (casas > 0) {
        printf("%s\n", ESQUERDA);
        moverRainhaRecursivo(casas - 1);
    }
}

// --- Funções dos Níveis ---

void nivelNovato() {
    printf("=== Nível Novato ===\n");

    // 1. Bispo: Diagonal Superior Direita.
    // Como a peça anda na diagonal, simulamos isso imprimindo Cima + Direita juntos.
    printf("-- Movimento do Bispo (while) --\n");
    int i = 0;
    while (i < PASSOS_BISPO) {
        printf("%s, %s\n", CIMA, DIREITA);
        i++;
    }

    // 2. Torre: Simplesmente direita.
    // O bom e velho 'for', ideal quando sabemos exatamente quantas vezes repetir.
    printf("-- Movimento da Torre (for) --\n");
    for (int j = 0; j < PASSOS_TORRE; j++) {
        printf("%s\n", DIREITA);
    }

    // 3. Rainha: Esquerda.
    // Usando 'do-while'. Ele executa o bloco e DEPOIS verifica.
    printf("-- Movimento da Rainha (do-while) --\n");
    int k = 0;
    do {
        printf("%s\n", ESQUERDA);
        k++;
    } while (k < PASSOS_RAINHA);
    
    printf("\n");
}

void nivelAventureiro() {
    printf("=== Nível Aventureiro ===\n");
    
    // Cavalo: Movimento em L (Baixo + Esquerda).
    // O desafio pede loops aninhados. Então, vamos usar um loop externo para controlar
    // a ação e loops internos para fazer as "pernas" do L.
    
    printf("-- Movimento do Cavalo (Loops Aninhados) --\n");

    for (int m = 0; m < PASSOS_CAVALO; m++) {
        
        // Loop interno 1: Faz a parte vertical do L (2 casas)
        int passos_vertical = 0;
        while (passos_vertical < 2) {
            printf("%s\n", BAIXO);
            passos_vertical++;
        }

        // Loop interno 2: Faz a parte horizontal do L (1 casa)
        int passos_horizontal = 0;
        while (passos_horizontal < 1) {
            printf("%s\n", ESQUERDA);
            passos_horizontal++;
        }
    }
    printf("\n");
}

void nivelMestre() {
    printf("=== Nível Mestre ===\n");

    // 1. Torre e Rainha agora usam as funções recursivas que criamos lá em cima.
    printf("-- Movimento da Torre (Recursivo) --\n");
    moverTorreRecursivo(PASSOS_TORRE);

    printf("-- Movimento da Rainha (Recursivo) --\n");
    moverRainhaRecursivo(PASSOS_RAINHA);

    // 2. Bispo: Requisito de loops aninhados.
    // Um pouco de "overkill" (exagero) para um movimento simples, mas cumpre o desafio.
    printf("-- Movimento do Bispo (Loops Aninhados) --\n");
    for(int i = 0; i < PASSOS_BISPO; i++) {
        
        // Loop só pra imprimir a direção vertical
        for(int v = 0; v < 1; v++) {
            printf("%s", CIMA);
        }
        
        printf(" e "); // Só pra ficar bonitinho na saída
        
        // Loop só pra imprimir a direção horizontal
        for(int h = 0; h < 1; h++) {
            printf("%s\n", DIREITA);
        }
    }

    // 3. Cavalo: O desafio final.
    // Movimento: L para cima à direita (2 Cima, 1 Direita).
    // Usamos variáveis múltiplas no for (v e h) e controle de fluxo com break/continue.
    printf("-- Movimento do Cavalo (Complexo: Break/Continue) --\n");
    
    // Inicializamos 'v' (vertical) e 'h' (horizontal) juntos.
    // A condição mantém o loop rodando até completar 3 passos no total.
    for (int v = 0, h = 0; v + h < 3; ) {
        
        // Prioridade para o movimento vertical (2 casas)
        if (v < 2) {
            printf("%s\n", CIMA);
            v++;
            // 'continue': Pula o resto do código e volta pro início do loop. 
            // Garante que não vai tentar andar pro lado na mesma iteração.
            continue; 
        }

        // Se já terminou o vertical, parte para o horizontal
        if (h < 1) {
            printf("%s\n", DIREITA);
            h++;
        }

        // Verificação de segurança: se completou o L, sai do loop imediatamente.
        if (v == 2 && h == 1) {
            break;
        }
    }
}

int main() {
    // Rodando tudo de uma vez
    nivelNovato();
    nivelAventureiro();
    nivelMestre();

    return 0;
}