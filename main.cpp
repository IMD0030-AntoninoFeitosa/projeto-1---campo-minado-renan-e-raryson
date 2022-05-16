#include "Game.h"
#include "Record.hpp"
#include "colormod.h"
#include <array>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

using namespace std::chrono;
using std::setprecision;

Color::Modifier vermelho(Color::FG_RED);
Color::Modifier verde(Color::FG_GREEN);
Color::Modifier amarelo(Color::FG_YELLOW);
Color::Modifier azul(Color::FG_BLUE);
Color::Modifier magenta(Color::FG_MAGENTA);
Color::Modifier ciano(Color::FG_CYAN);
Color::Modifier cinza(Color::FG_GRAY);
Color::Modifier def(Color::FG_DEFAULT);

using std::setprecision;
const std::string CONFIG_FILE = "config.cfg";

void mostra_mapa2(std::vector<std::vector<char>> mA, int C, int L, int i,
                  int j) {
  if (j == C - 1) {
    if (mA[i][j] == 'P') // Bandeira
      std::cout << "| " << magenta << mA[i][j] << def << "|";

    if (mA[i][j] == '?') // Duvida
      std::cout << "| " << amarelo << mA[i][j] << def << "|";

    if (mA[i][j] == '*') // Bomba
      std::cout << "| " << vermelho << mA[i][j] << def << "|";

    if (mA[i][j] == '0' || mA[i][j] == ' ') // Normal
      std::cout << "| " << mA[i][j] << "|";

    if (mA[i][j] == '1') // Azul
      std::cout << "| " << azul << mA[i][j] << def << "|";

    if (mA[i][j] == '2') // Verde
      std::cout << "| " << verde << mA[i][j] << def << "|";

    if (mA[i][j] == '3') // Vermelho
      std::cout << "| " << vermelho << mA[i][j] << def << "|";

    if (mA[i][j] == '4') // Amarelo
      std::cout << "| " << amarelo << mA[i][j] << def << "|";

    if (mA[i][j] == '5') // Azul
      std::cout << "| " << azul << mA[i][j] << def << "|";

    if (mA[i][j] == '6') // Verde
      std::cout << "| " << verde << mA[i][j] << def << "|";

    if (mA[i][j] == '7') // Vermelho
      std::cout << "| " << vermelho << mA[i][j] << def << "|";

    if (mA[i][j] == '8') // Amarelo
      std::cout << "| " << amarelo << mA[i][j] << def << "|";

  } else {
    if (mA[i][j] == 'P') // Bandeira
      std::cout << "| " << magenta << mA[i][j] << def;

    if (mA[i][j] == '?') // Duvida
      std::cout << "| " << amarelo << mA[i][j] << def;

    if (mA[i][j] == '*') // Bomba
      std::cout << "| " << vermelho << mA[i][j] << def;

    if (mA[i][j] == '0' || mA[i][j] == ' ') // Normal
      std::cout << "| " << mA[i][j];

    if (mA[i][j] == '1') // Azul
      std::cout << "| " << azul << mA[i][j] << def;

    if (mA[i][j] == '2') // Verde
      std::cout << "| " << verde << mA[i][j] << def;

    if (mA[i][j] == '3') // Vermelho
      std::cout << "| " << vermelho << mA[i][j] << def;

    if (mA[i][j] == '4') // Amarelo
      std::cout << "| " << amarelo << mA[i][j] << def;

    if (mA[i][j] == '5') // Azul
      std::cout << "| " << azul << mA[i][j] << def;

    if (mA[i][j] == '6') // Verde
      std::cout << "| " << verde << mA[i][j] << def;

    if (mA[i][j] == '7') // Vermelho
      std::cout << "| " << vermelho << mA[i][j] << def;

    if (mA[i][j] == '8') // Amarelo
      std::cout << "| " << amarelo << mA[i][j] << def;
  }
}

void mostra_mapa(std::vector<std::vector<char>> mA, int C, int L) {
  int i, j;
  std::cout << "    ";
  for (j = 0; j < C; j++) {
    std::cout << " " << j;
  }
  for (i = 0; i < L; i++) {
    if (L > 9 && i < 10) {
      std::cout << "\n " << i << " -";
    } else {
      std::cout << "\n " << i
                << "-"; /// Impressão do mapa do jogo com traços e divisórias.
    }

    for (j = 0; j < C; j++) {
      if (j == C - 1) {
        if (j > 9) {
          mostra_mapa2(mA, C, L, i, j);
        } else {
          if (mA[i][j] == 'P') // Bandeira
            std::cout << "|" << magenta << mA[i][j] << def << "|";

          if (mA[i][j] == '?') // Duvida
            std::cout << "|" << amarelo << mA[i][j] << def << "|";

          if (mA[i][j] == '*') // Bomba
            std::cout << "|" << vermelho << mA[i][j] << def << "|";

          if (mA[i][j] == '0' || mA[i][j] == ' ') // Normal
            std::cout << "|" << mA[i][j] << "|";

          if (mA[i][j] == '1') // Azul
            std::cout << "|" << azul << mA[i][j] << def << "|";

          if (mA[i][j] == '2') // Verde
            std::cout << "|" << verde << mA[i][j] << def << "|";

          if (mA[i][j] == '3') // Vermelho
            std::cout << "|" << vermelho << mA[i][j] << def << "|";

          if (mA[i][j] == '4') // Amarelo
            std::cout << "|" << amarelo << mA[i][j] << def << "|";

          if (mA[i][j] == '5') // Azul
            std::cout << "|" << azul << mA[i][j] << def << "|";

          if (mA[i][j] == '6') // Verde
            std::cout << "|" << verde << mA[i][j] << def << "|";

          if (mA[i][j] == '7') // Vermelho
            std::cout << "|" << vermelho << mA[i][j] << def << "|";

          if (mA[i][j] == '8') // Amarelo
            std::cout << "|" << amarelo << mA[i][j] << def << "|";
        }
      } else {
        if (j > 9) {
          mostra_mapa2(mA, C, L, i, j);
        } else {
          if (mA[i][j] == 'P') // Bandeira
            std::cout << "|" << magenta << mA[i][j] << def;

          if (mA[i][j] == '?') // Duvida
            std::cout << "|" << amarelo << mA[i][j] << def;

          if (mA[i][j] == '*') // Bomba
            std::cout << "|" << vermelho << mA[i][j] << def;

          if (mA[i][j] == '0' || mA[i][j] == ' ') // Normal
            std::cout << "|" << mA[i][j];

          if (mA[i][j] == '1') // Azul
            std::cout << "|" << azul << mA[i][j] << def;

          if (mA[i][j] == '2') // Verde
            std::cout << "|" << verde << mA[i][j] << def;

          if (mA[i][j] == '3') // Vermelho
            std::cout << "|" << vermelho << mA[i][j] << def;

          if (mA[i][j] == '4') // Amarelo
            std::cout << "|" << amarelo << mA[i][j] << def;

          if (mA[i][j] == '5') // Azul
            std::cout << "|" << azul << mA[i][j] << def;

          if (mA[i][j] == '6') // Verde
            std::cout << "|" << verde << mA[i][j] << def;

          if (mA[i][j] == '7') // Vermelho
            std::cout << "|" << vermelho << mA[i][j] << def;

          if (mA[i][j] == '8') // Amarelo
            std::cout << "|" << amarelo << mA[i][j] << def;
        }
      }
    }
  }
  std::cout << std::endl;
}

void show_usage(void) {
  std::cout << "Uso: jogo [opções]" << std::endl;
  std::cout << "Opções:" << std::endl;
  std::cout << " -h ou --help                 Mostra estas informações."
            << std::endl;
  std::cout << " -r ou --records              Mostra os 10 melhores tempos."
            << std::endl;
  std::cout << " -d ou --difficulty <opção>   Muda a dificuldade para "
               "<opção>"
            << std::endl;
  std::cout << "                               -b ou --beginner" << std::endl;
  std::cout << "                               -i ou --intermediary"
            << std::endl;
  std::cout << "                               -a ou --advanced" << std::endl;
}

std::vector<std::vector<char>>
checarBombas(int L, int C, std::vector<std::vector<char>> mC, int i, int j) {
  if (i >= 0 && i < L && j >= 0 && j < C) { /// Verifica se a posição é válida.
    if (mC[i][j] != '*') /// Verifica se nessa posição tem bomba.
      mC[i][j]++;        /// Se não tem bomba, soma um número.
  }
  return mC;
}

std::vector<std::vector<char>> revelar(int L, int C,
                                       std::vector<std::vector<char>> mA,
                                       std::vector<std::vector<char>> mC,
                                       int lin, int col, int bandeira) {
  if (lin >= 0 && lin < L && col >= 0 &&
      col < C) {               /// Verifica se a posição é válida.
    if (mA[lin][col] == ' ') { /// Caso a posição seja vazia
      mA[lin][col] = mC[lin][col];
      if (mC[lin][col] == '0' &&
          bandeira == 0) { /// Caso o usuário jogue onde é 0.
        mA = revelar(L, C, mA, mC, lin - 1, col, bandeira); /// Cima
        mA = revelar(L, C, mA, mC, lin + 1, col, bandeira); /// Baixo
        mA = revelar(L, C, mA, mC, lin, col - 1, bandeira); /// Esquerda
        mA = revelar(L, C, mA, mC, lin, col + 1, bandeira); /// Direita

        mA = revelar(L, C, mA, mC, lin - 1, col - 1,
                     bandeira); /// Cima - Esquerda
        mA = revelar(L, C, mA, mC, lin - 1, col + 1,
                     bandeira); /// Cima - Direita
        mA = revelar(L, C, mA, mC, lin + 1, col - 1,
                     bandeira); /// Baixo - Esquerda
        mA = revelar(L, C, mA, mC, lin + 1, col + 1,
                     bandeira); /// Baixo - Direita
      } else if (mC[lin][col] != '0') {
        mA[lin][col] = mC[lin][col]; /// Deixa a posição visível.
      }
    }
  }
  return mA;
}

char start_game(Difficulty level, char jogar) {
  int L, C, B;
  if (level == Difficulty::beginner) {
    L = 10;
    C = 10;
    B = 10;
  }
  if (level == Difficulty::intermediary) {
    L = 15;
    C = 15;
    B = 40;
  }
  if (level == Difficulty::advanced) {
    L = 15;
    C = 30;
    B = 100;
  }
  int contJ = 0, contB = 0, i, j, lin, col, casas, vitoria = 0,
      bandeira = 0; /// Qtd de jogadas e bombas, linhas e colunas.
  bool gameover, numINV,
      jogINV; /// Fim de jogo, número inválido e jogada inválida.

  std::vector<std::vector<char>> mC(L, std::vector<char>(C));
  std::vector<std::vector<char>> mA(L, std::vector<char>(C));
  gameover = false; /// False, se gameover True o jogo acaba.
  numINV = false;   /// O jogo roda.
  jogINV = false; /// A jogada não é adequada com o número d linhas e colunas.

  std::chrono::time_point<std::chrono::system_clock> t1, t2;

  std::cout << "Bem vindo(os) ao CAMPO MINADO\n" << std::endl;

  srand(time(NULL)); /// Gera uma nova semente.

  if (L < 2 || C < 2 || B < 2) {
    jogINV = true; /// Jogada inválida, fora dos padrões de linhas e colunas.
    std::cout << "Jogada inválida. Verifique a quantidade de linhas e colunas."
              << std::endl;
  }
  if (jogINV == false) {
    for (i = 0; i < L; i++) {
      for (j = 0; j < C; j++) {
        mA[i][j] =
            ' '; /// Irá aparecer algo na casa jogada, na matriz apresentada.
        mC[i][j] = '0'; /// A matriz controladora irá simular que a casa jogada
                        /// está ocupada.
      }
    }
    srand(time(NULL));
    for (contB = 0; contB < B; contB++) { /// Distribuição das bombas no mapa.
      do {
        i = rand() % L;          /// Escolha a linha aleatória no mapa.
        j = rand() % C;          /// Escolha a coluna aleatória no mapa.
      } while (mC[i][j] == '*'); /// Onde tiver bomba irá aparecer um x ao ser
                                 /// explodido ou no final do jogo.
      mC[i][j] = '*';
    }

    // CHECAR BOMBAS
    for (i = 0; i < L; i++) {
      for (j = 0; j < C; j++) {
        if (mC[i][j] ==
            '*') { /// Vai checar cada posição para ver se tem bomba.
          mC = checarBombas(L, C, mC, i - 1, j); /// Cima
          mC = checarBombas(L, C, mC, i + 1, j); /// Baixo
          mC = checarBombas(L, C, mC, i, j - 1); /// Esquerda
          mC = checarBombas(L, C, mC, i, j + 1); /// Direita

          mC = checarBombas(L, C, mC, i - 1, j - 1); /// Cima - Esquerda
          mC = checarBombas(L, C, mC, i - 1, j + 1); /// Cima - Direita
          mC = checarBombas(L, C, mC, i + 1, j - 1); /// Baixo - Esquerda
          mC = checarBombas(L, C, mC, i + 1, j + 1); /// Baixo - Direita
        }
      }
    }
    auto t1 = std::chrono::system_clock::now();
    while (!gameover) {
      mostra_mapa(mA, C, L);

      /// MENU
      bool opcINV = true;

      char opc;
      std::cout << "\nEscolha uma opção:" << std::endl;
      std::cout << "B - Marcar bandeira" << std::endl;
      std::cout << "R - Revelar posição" << std::endl;
      // std::cout << "T - Melhores tempos" << std::endl;
      std::cout << "X - Reiniciar" << std::endl;
      do {
        std::cin >> opc;

        if (opc == 'B' || opc == 'b') { // MARCAR BANDEIRA
          do {
            numINV = false;
            opcINV = false;
            std::cout << "Coordenada da bandeira:"
                      << "\n"; /// O jogo solicita a jogada do usuário.
            std::cin >> lin;
            std::cin >> col;

            bandeira = 1;
            if (mA[lin][col] == 'P') { // [P] para [?]
              mA[lin][col] = '?';
            } else if (mA[lin][col] == '?') { // [?] para [ ]
              mA[lin][col] = ' ';
            } else if (mA[lin][col] == ' ') { // [ ] para [P]
              mA[lin][col] = 'P';
            } else {
              std::cout << "Número inválido.";
              numINV = true;
              bandeira = 0;
            }
          } while (numINV == true);
        } else if (opc == 'R' || opc == 'r') {
          do {
            numINV = false;
            opcINV = false;
            std::cout << "Informe uma coordenada:"
                      << "\n"; /// O jogo solicita a jogada do usuário.
            std::cin >> lin;
            std::cin >> col;

            if (lin >= L || lin < 0 || col >= C || col < 0) {
              std::cout << "Número inválido.\n";
              numINV = true;
            } else if (mA[lin][col] ==
                       mC[lin][col]) { /// Quando se joga na mesma casa 2 vezes
                                       /// a jogada é inválida.
              std::cout << "Jogada inválida.\n";
              numINV = true;
            } else {
              contJ++;
              if (contJ == 1) {
                t1 = std::chrono::system_clock::now();
              }
            }
          } while (numINV == true);
        } /*else if (opc == 'T' ||
                   opc == 't') { // hmm.. tá criando arquivo .txt e gravando os
                                 // dados respectivos no struct
          std::vector<Record> records;
          std::string FILE = "records.txt";

          Record r;
          r.name = "Issac Asimov";
          r.milliseconds = 10500;

          records.push_back(r);
          records.push_back({"John Von Neumann", 1500});
          records.push_back({"Ada Lovelace", 3000});
          records.push_back({"Ludmila Kuncheva", 5000});
          records.push_back({"Donald Knuth", 7000});
          records.push_back({"Edsger Dijkstra", 6000});

          std::cout << "Recordes" << records << std::endl;
          sort(records);

          std::cout << "Ordenados" << records << std::endl;

          write_records(records, FILE);
          read_records(records, FILE);

          std::cout << "Registrados" << records << std::endl;

          numINV = false;
          opcINV = false;
        }*/
        else if (opc == 'X' || opc == 'x') {
          opcINV = false;
        } else {
          std::cout << "Comando incorreto.\n" << std::endl;
          opcINV = true;
        }
      } while (opcINV == true);
      if (opc == 'X' || opc == 'x') {
        gameover = true;
      }

      /// REVELAR CASA
      if (opc == 'R' || opc == 'r') {
        mA = revelar(L, C, mA, mC, lin, col, bandeira);
      }

      /// PISANDO NA BOMBA
      if (mA[lin][col] == '*' &&
          bandeira == 0) { /// Caso o usuário jogue onde tem bomba.
        mostra_mapa(mC, C, L);
        gameover = true; /// Fim de jogo.
        std::cout << "Você foi explodido!"
                  << "\n"; /// O jogador acertou uma bomba.
      } else {
        bandeira = 0;
        /// VERIFICA FIM DE JOGO
        casas = 0;
        for (i = 0; i < L;
             i++) { /// Percorre mapa e verifica posições não-vazias
          for (j = 0; j < C; j++) {
            if (mA[i][j] != ' ') {
              casas++;
            }
            if (mA[i][j] == 'P' || mA[i][j] == '?') {
              casas--;
            }
            if (casas ==
                L * C - B) { /// Se casas igual a linha x colunas - bombas
              mostra_mapa(mC, C, L);
              vitoria = 1;
              gameover = true; /// O jogo acabou com vitória.
              std::cout << std::endl;
              std::cout << "Parabéns, você ganhou o jogo!"
                        << "\n";
            }
          }
        }
      }
    }
    std::string nome;
    double tempo;

    if (vitoria == 1) {

      t2 = std::chrono::system_clock::now();
      std::chrono::duration<double> elapsed;
      elapsed = t2 - t1;

      tempo = elapsed.count();
      std::cout << setprecision(4) << "Tempo: " << elapsed.count() << " segundos.";
      std::cout << "\nInforme o seu nome: " << std::endl;
      std::cin >> nome;

      std::vector<Record> records;
      std::string FILE = "records.txt";
      int tamanho = read_records(records, FILE);
      std::string vetornome[tamanho];
      double vetortempo[tamanho];
      int contador = 0;

      for (int i = 0; i < tamanho; i++) {
        if (i < contador + 1) {
          vetornome[i] = nome;
          vetortempo[i] = tempo * 1000;
          records.push_back({vetornome[i], vetortempo[i]});
        } else {
          contador++;
        }
      }
      /*std::cout << setprecision(0) << "Recordes" << records << std::endl;*/
      sort(records);
      write_records(records, FILE);

      /*std::cout << "Registrados" << records << std::endl;*/

      for (int i = 0; i < tamanho; i++) {
        read_records(records, FILE);
      }
    }
  }
  std::cout << "\nReiniciar?(S/N)" << std::endl;
  std::cin >> jogar;
  return jogar;
}

void store_difficulty(const std::string config_file, Difficulty level) {
  std::ofstream file;
  file.open(config_file.c_str(), std::ifstream::out);
  if (file.is_open()) {
    switch (level) {
    case Difficulty::beginner:
      file << 'b';
      break;
    case Difficulty::intermediary:
      file << 'i';
      break;
    case Difficulty::advanced:
      file << 'a';
      break;
    }
    file.close();
  }
}

Difficulty load_difficulty(const std::string config_file) {
  Difficulty level;
  std::ifstream file;
  file.open(config_file.c_str(), std::ifstream::in);
  if (file.is_open()) {
    char c;
    file >> c;
    switch (c) {
    case 'b':
      level = Difficulty::beginner;
      break;
    case 'i':
      level = Difficulty::intermediary;
      break;
    case 'a':
      level = Difficulty::advanced;
      break;
    }
    file.close();
  } else {
    store_difficulty(config_file, Difficulty::beginner);
    level = Difficulty::beginner;
  }
  return level;
}

int main(int argc, char **argv) {
  std::vector<Record> records;
  std::string FILE = "records.txt";
  srand(time(NULL)); /// Gera uma nova semente.

  if (argc > 1) {
    std::string arg = argv[1];
    if (arg == "-h" || arg == "--help") {
      show_usage();
    } else if (arg == "-d" || arg == "--difficulty") {

      if (argc > 2) {
        std::string newlevel = argv[2];
        if (newlevel == "-b" || newlevel == "--beginner") {
          store_difficulty(CONFIG_FILE, Difficulty::beginner);
        } else if (newlevel == "-i" || newlevel == "--intermediary") {
          store_difficulty(CONFIG_FILE, Difficulty::intermediary);
        } else if (newlevel == "-a" || newlevel == "--advanced") {
          store_difficulty(CONFIG_FILE, Difficulty::advanced);
        } else {
          std::cout << "Dificuldade inválida: " << newlevel << std::endl;
          show_usage();
        }
      } else {
        std::cout << "Esperava-se uma dificuldade para:: " << argv[1]
                  << std::endl;
        show_usage();
      }
    } else if (arg == "-r" || arg == "--records") {
      int tamanho = show_records(records, FILE);
      
      std::cout << "Records" << setprecision(4) << records << std::endl;

    } else {
      std::cout << "Argumento inválido: " << argv[1] << std::endl;
      show_usage();
    }
  } else {
    Difficulty level = load_difficulty(CONFIG_FILE);
    char jogar = 'S';
    do {
      jogar = start_game(level, jogar);
    } while (jogar == 'S' || jogar == 's');
  }
  return 0;
}