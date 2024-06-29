# Hotel descanso garantido

<h4>Trabalho das diciplinas Algoritimo e estrutura de dados I e Fundamentos da engenharia se software</h4>
<hr>

<h3>Objetivo</h3>

<p>O objetivo do sistema feito para o Hotel Descanso Garantido é ser um facilitador. Antes, diversos problemas ocorriam com o uso de planilhas do Excel e cadernos. Na hora de fazer o controle de estadias, clientes e funcionários, havia problemas de organização, além de ocorrer frequentemente a reserva de um mesmo quarto para mais de um cliente. O novo sistema visa resolver esses problemas, ajudando a melhorar nos seguintes pontos:</p>

<ul>
<li>O sistema centralizará todas as informações em um único lugar, eliminando a necessidade de múltiplas planilhas e cadernos, garantindo assim maior organização.</li>
<li>Evitará conflitos de reservas, pois com funcionalidades de gerenciamento de reservas, o sistema evitará que um mesmo quarto seja reservado para mais de um cliente ao mesmo tempo.</li>
<li>Facilitará a atualização: A equipe do hotel terá acesso rápido e fácil às informações atualizadas de estadias, clientes e funcionários, permitindo uma gestão mais ágil e informada.</li>
<li>Melhorará a fidelização e satisfação do cliente: Isso será possível através de um serviço mais organizado e eficiente, reforçando a reputação do Hotel Descanso Garantido.</li>
</ul>

<hr>

<h3>Funcionalidades</h3>

<p>Buscando solicionar os problemas apresentados pelo Hotel descanso garantido, as funcionalidades implatadas foram as seguintes:</p>

### Funcionalidades Principais:
1. **Fazer uma Reserva (`case 1`)**:
   - Solicita dados do cliente (nome, telefone, endereço).
   - Gera um código aleatório para o cliente.
   - Registra as datas de entrada e saída da estadia.
   - Calcula o número de diárias com base nas datas fornecidas.
   - Registra a quantidade de hóspedes.
   - Incrementa o número de clientes e estadias.

2. **Ver Reservas Cadastradas (`case 2`)**:
   - Lista todas as reservas cadastradas, mostrando detalhes como nome do cliente, o código, telefone, datas de entrada e saída, número de diárias, número do quarto, quantidade de hóspedes e valor da diária.

3. **Apagar Reserva (`case 3`)**:
   - Permite ao usuário selecionar uma reserva para apagar.
   - Libera o quarto que estava ocupado pela reserva apagada.
   - Remove a reserva da lista.

4. **Cadastrar Funcionário (`case 4`)**:
   - Solicita informações do funcionário como nome, telefone, cargo e salário.
   - Gera um código aleatório para o funcionário.
   - Incrementa o número de funcionários cadastrados.

5. **Ver Funcionários Cadastrados (`case 5`)**:
   - Lista todos os funcionários cadastrados, exibindo nome, telefone, cargo, salário e código.

6. **Verificar Status dos Quartos (`case 6`)**:
   - Mostra o status de cada quarto do hotel, indicando se está ocupado ou desocupado, além de exibir a quantidade de hóspedes que podem ser acomodados e o valor da diária.

7. **Gravar Dados em Arquivo estadias.txt (`case 7`)**:
   - Salva todas as estadias (reservas), clientes e funcionários cadastrados em um arquivo de texto chamado estadias.txt.

8. **Ler e Imprimir Dados do Arquivo estadias.txt(`case 8`)**:
   -Lê e imprime na tela os dados salvos anteriormente no arquivo estadias.txt.

9. **Encerra o programa(`case 9`)**:
   -Adicione uma mensagem indicando que o programa está sendo encerrado.
   -Utilize break; para sair do loop do-while principal, encerrando assim a execução do programa.

### Observações:

- **Gerenciamento de Quartos**: O sistema controla se os quartos estão ocupados ou desocupados. Ao fazer uma reserva, o quarto escolhido é marcado como ocupado até que a reserva seja apagada.
  
- **Cálculo de Diárias**: O sistema utiliza funções da biblioteca `time.h` para calcular o número de diárias com base nas datas de entrada e saída fornecidas pelo usuário.

- **Randomização de Códigos**: Tanto para clientes quanto para funcionários, códigos são gerados aleatoriamente para identificação única.

### Estruturas Utilizadas:

1. **Cliente (`struct cliente`)**:
   - Armazena informações como nome, endereço, telefone e código do cliente.

2. **Funcionário (`struct funcionario`)**:
   - Contém informações como nome, telefone, cargo, salário e código do funcionário.

3. **Estadia (`struct estadia`)**:
   - Registra informações relacionadas à estadia do cliente, incluindo datas de entrada e saída, número de diárias, número do quarto e código do cliente.

4. **Quarto (`struct quarto`)**:
   - Mantém dados como número do quarto, quantidade de hóspedes que podem ser acomodados, valor da diária, status (ocupado ou não) e se está ocupado.

<hr>

### Bibliotecas Utilizadas:

O programa utiliza algumas bibliotecas padrão da linguagem C para diferentes funcionalidades:
<ul>
<li>stdio.h: Utilizada para operações de entrada e saída, como printf e scanf.</li>
<li>stdlib.h: Oferece funções para alocação de memória dinâmica (malloc, free) e geração de números aleatórios (rand, srand).</li>
<li>string.h: Fornece funções para manipulação de strings, como strcpy e strcat.</li>
<li>time.h: Utilizada para operações relacionadas ao tempo, como a conversão de datas e geração de timestamps.</li>

</ul>
Essas bibliotecas são essenciais para diferentes partes do programa, desde a manipulação de dados de entrada e saída até o gerenciamento de datas, memória e números aleatórios.

<hr>

### Telas:

   -**Menu**:
   
![image](https://github.com/sofiavasconcelosms/Hotel-descanso-garantido/assets/161332457/b4ab2810-3086-49c2-aeaf-1c34e1cfe292)


   -**1: Fazer uma resrva Reserva**:

![image](https://github.com/sofiavasconcelosms/Hotel-descanso-garantido/assets/161332457/56fa2bdc-91af-4d1c-bfde-31d61294e937)


   -**2: Ver reservas cadastradas**:

![image](https://github.com/sofiavasconcelosms/Hotel-descanso-garantido/assets/161332457/cb9a6290-231c-4776-8cef-040a775e7a0b)


   -**3: Apagar reserva**:

![image](https://github.com/sofiavasconcelosms/Hotel-descanso-garantido/assets/161332457/670f97e6-1d9b-4e40-8aa2-823ad50fd390)

   -**4: Cadastrar funcionario**:

![image](https://github.com/sofiavasconcelosms/Hotel-descanso-garantido/assets/161332457/42b44e74-ac3c-4b8b-b338-a97fc53b15af)

   -**5:Ver funcionarios cadastrados**:

![image](https://github.com/sofiavasconcelosms/Hotel-descanso-garantido/assets/161332457/2ced9d07-9567-408e-b33e-ff78782ee3c0)

   -**6:Verificar status do quartos**:

![image](https://github.com/sofiavasconcelosms/Hotel-descanso-garantido/assets/161332457/cde21c2f-968c-4ec7-97ce-a99e0d431561)    ![image](https://github.com/sofiavasconcelosms/Hotel-descanso-garantido/assets/161332457/0d4ed3bc-baf7-485c-82c4-6cf768fede3f)

   -**7: Gravar dados em arquivo estadias.txt**:

![image](https://github.com/sofiavasconcelosms/Hotel-descanso-garantido/assets/161332457/86183275-337c-40f3-ac12-5ed67ec4ff3f)

   -**8: Ler e imprimir dados do arquivo estadias.txt**:

![image](https://github.com/sofiavasconcelosms/Hotel-descanso-garantido/assets/161332457/e591f980-389f-441a-ae75-4fbc9d61c829)


   -**9: Sair**:

![image](https://github.com/sofiavasconcelosms/Hotel-descanso-garantido/assets/161332457/09852543-f31a-467e-a555-3713a6690a83)














