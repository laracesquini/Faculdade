#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>

unsigned int taxa_amostragem;
//---------------------------------------
int main(int i,char* n[])
{
void analisa_dados_brutos(double*,int);
short converte2de8para1de16(unsigned char, unsigned char);
double modulo(double num);
FILE* fr;

if(((fr=fopen(n[1],"rb"))!=NULL))
        {
        struct
                {
                unsigned char riff[4];
                unsigned int len;
                } riff_header;
        fread(&riff_header,sizeof(riff_header),1,fr);
        std::cout<<"\nArquivo do tipo: "<<riff_header.riff[0]<<riff_header.riff[1]<<riff_header.riff[2]<<riff_header.riff[3];
        std::cout<<"\nTamanho excluindo header: "<<riff_header.len;

        ///////////////////////////////////////////////////////////////////////////

        unsigned char wave[4];
        fread(&wave,sizeof(wave),1,fr); //////
        std::cout<<"\nSub-Tipo: "<<wave[0]<<wave[1]<<wave[2]<<wave[3];

        ///////////////////////////////////////////////////////////////////////////
        struct
                {
                unsigned char id[4];
                unsigned int len;
                } riff_chunk;
        fread(&riff_chunk,sizeof(riff_chunk),1,fr);
        std::cout<<"\nIdentificador: "<<riff_chunk.id[0]<<riff_chunk.id[1]<<riff_chunk.id[2]<<riff_chunk.id[3];
        std::cout<<"\nComprimento do chunk apos header: "<<riff_chunk.len;

        //////////////////////////////////////////////////////////////////////////////
        struct
                {
                unsigned short formattag;
                unsigned short numberofchannels;
                unsigned int samplingrate;
                unsigned int avgbytespersecond;
                unsigned short blockalign;
                }  wave_chunk;
        fread(&wave_chunk,sizeof(wave_chunk),1,fr);

//tratamento de uma excessao que costuma aparecer em alguns arquivos wav... O correto seriam 16 bytes, as vezes aparecem 18 ou mais...
	if(riff_chunk.len>16)
			{
			unsigned char excesso;
		    for(int i=0;i<riff_chunk.len-16;i++)
				fread(&excesso,sizeof(excesso),1,fr);
			}
	//fim do tratamento da excess?
        std::cout<<"\nCategoria do formato: "<<wave_chunk.formattag;
        std::cout<<"\nNumero de canais: "<<wave_chunk.numberofchannels;
        std::cout<<"\nTaxa de amostragem: "<<wave_chunk.samplingrate;
        std::cout<<"\nMedia do num. de bps: "<<wave_chunk.avgbytespersecond;
        std::cout<<"\nAlinhamento do bloco em bytes: "<<wave_chunk.blockalign;
        taxa_amostragem = wave_chunk.samplingrate;

        //////////////////////////////////////////////////////////////////////////////

        if(wave_chunk.formattag==1) //PCM
                {
                int resolucao=(wave_chunk.avgbytespersecond * 8)/(wave_chunk.numberofchannels * wave_chunk.samplingrate);// pq nao bitssample
                std::cout<<"\nResolucao: "<<resolucao;

                struct
                        {
                        unsigned char data[4];
                        unsigned int chunk_size;
                        } header_data_chunk;

                fread(&header_data_chunk,sizeof(header_data_chunk),1,fr);
                std::cout<<"\nIdentificacao: "<<header_data_chunk.data[0]<<header_data_chunk.data[1]<<header_data_chunk.data[2]<<header_data_chunk.data[3];
                std::cout<<"\nTamanho do chunk de dados: "<<header_data_chunk.chunk_size;
                std::cout<<"\nNumero de frames para amostrar: "<<header_data_chunk.chunk_size/wave_chunk.blockalign;

                int tamanho_da_janela=header_data_chunk.chunk_size/wave_chunk.blockalign;

                std::cout<<"\nTamanho da janela: "<<tamanho_da_janela;
                if((resolucao==8) && (wave_chunk.numberofchannels==1))
                        {
                         unsigned char waveformdata;
                         double* amostras_no_tempo = new double[tamanho_da_janela];
                         for(int i=0;i<tamanho_da_janela;i++)
                               {
                               fread(&waveformdata,sizeof(waveformdata),1,fr);
                               amostras_no_tempo[i]=(double)waveformdata;
                               }

						analisa_dados_brutos(&amostras_no_tempo[0],tamanho_da_janela);
                        }
                else if((resolucao==8) && (wave_chunk.numberofchannels==2))
                        {
                         unsigned char waveformdata_right;
                         unsigned char waveformdata_left;
                         double* amostras_no_tempo_left = new double[tamanho_da_janela];
                         double* amostras_no_tempo_right = new double[tamanho_da_janela];
                         for(int i=0;i<tamanho_da_janela;i++)
                               {
                               fread(&waveformdata_left,sizeof(waveformdata_left),1,fr);
                               fread(&waveformdata_right,sizeof(waveformdata_right),1,fr);
                        
                               amostras_no_tempo_right[i]=(double)waveformdata_right;
                               amostras_no_tempo_left[i]=(double)waveformdata_left;
                               }
			
						analisa_dados_brutos(&amostras_no_tempo_left[0],tamanho_da_janela);
						analisa_dados_brutos(&amostras_no_tempo_right[0],tamanho_da_janela);
                        }
                else if((resolucao==16) && (wave_chunk.numberofchannels==1))
                        {
                         unsigned char waveformdata_lsb, waveformdata_msb;
                         double* amostras_no_tempo = new double[tamanho_da_janela];
                         for(int i=0;i<tamanho_da_janela;i++)
                               {
                               fread(&waveformdata_lsb,sizeof(waveformdata_lsb),1,fr);
                               fread(&waveformdata_msb,sizeof(waveformdata_msb),1,fr);
                               amostras_no_tempo[i]=(double)converte2de8para1de16(waveformdata_lsb,waveformdata_msb);
                               }

						analisa_dados_brutos(&amostras_no_tempo[0],tamanho_da_janela);
                        }
                else if ((resolucao==16) && (wave_chunk.numberofchannels==2))
                        {
                         unsigned char waveformdata_lsb_left, waveformdata_lsb_right, waveformdata_msb_left, waveformdata_msb_right;
                         double* amostras_no_tempo_left = new double[tamanho_da_janela];
                         double* amostras_no_tempo_right = new double[tamanho_da_janela];
                         for(int i=0;i<tamanho_da_janela;i++)
                               {
                               fread(&waveformdata_lsb_left,sizeof(waveformdata_lsb_left),1,fr);
                               fread(&waveformdata_msb_left,sizeof(waveformdata_msb_left),1,fr);
                               fread(&waveformdata_lsb_right,sizeof(waveformdata_lsb_right),1,fr);
                               fread(&waveformdata_msb_right,sizeof(waveformdata_msb_right),1,fr);
                               amostras_no_tempo_left[i]=(double)converte2de8para1de16(waveformdata_lsb_left,waveformdata_msb_left);
                               amostras_no_tempo_right[i]=(double)converte2de8para1de16(waveformdata_lsb_right,waveformdata_msb_right);
                               }
			
						analisa_dados_brutos(&amostras_no_tempo_left[0],tamanho_da_janela);
						analisa_dados_brutos(&amostras_no_tempo_right[0],tamanho_da_janela);
                        }
                else
						std::cout<<"Resolucao ou nmero de canais invalido(s)";

                }
        else
                std::cout<<"FORA DO FORMATO PCM...";
        fclose(fr);
        }
else
        std::cout<<"Arquivo nao existe ou nao pode ser aberto";
std::cout<<"\n\n\n";
}
//--------------------------------------------------------
short converte2de8para1de16(unsigned char lsb, unsigned char msb)
{
return(((msb&0x80)>>7)*(32768) +
       ((msb&0x40)>>6)*(16384) +
       ((msb&0x20)>>5)*(8192) +
       ((msb&0x10)>>4)*(4096) +
       ((msb&0x08)>>3)*(2048) +
       ((msb&0x04)>>2)*(1024) +
       ((msb&0x02)>>1)*(512) +
       ((msb&0x01))*(256) +
       ((lsb&0x80)>>7)*(128) +
       ((lsb&0x40)>>6)*(64) +
       ((lsb&0x20)>>5)*(32) +
       ((lsb&0x10)>>4)*(16) +
       ((lsb&0x08)>>3)*(8) +
       ((lsb&0x04)>>2)*(4) +
       ((lsb&0x02)>>1)*(2) +
       (lsb&0x01));
}

//cálculo do módulo de um número
double modulo(double num)
{
        if(num > 0)
        return num;
        else
        return (-num);
}

void imprimir(double *vet, int m)
{
        int i;

        printf("\n");
        for(i = 0; i < m; i++)
        {
                printf("%d:%f, ", i, vet[i]);
        }
        printf("\n");
}

//normalização da amplitude do sinal - garante que todas as amostras estejam entre -1 e 1
void normalizacao_amplitude(double *s, int m)
{
        double maior;
        int i;

        //identificar o maior valor em módulo
        maior = modulo(s[0]);
        for(i = 0; i<m; i++)
        {
                if(modulo(s[i]) > maior)
                maior = modulo(s[i]);
        }
        //dividir todas as amotras pelo maior valor
        for(i=0; i<m; i++)
        {
                s[i] = s[i]/maior;
        }

        return;
}

//remoção da media do sinal ou frequência 0 hrtz (aquilo que não oscila) - apenas translada o sinal no eixo
void remocao_media(double *s, int m)
{
        double media = 0;
        int i;

        //calcular a media dos valores das amostras
        for(i=0; i<m; i++)
        {
                media = media + s[i];
        }
        media = media/m;

        //remover a média 
        for(i=0; i<m; i++)
        {
                s[i] = s[i] - media;
        }

        return; 
}

//remoção da irradiação labial - limpa o sinal
void remocao_irradiacao_labial(double *s, int m, double *x)
{
        int i;
        
        //aplicação de um filtro FIR com 2 coeficientes - altera levemente a forma de onda
        x[0] = s[1];
        for(i = 1; i<(m-1); i++)
        {
                x[i] = s[i] + (0.95*x[i-1]);
        }
        x[m] = s[1];

        return;
}

//autocorrelação do sinal - relação do sinal com ele mesmo considerando certo deslocamento. O sinal autocorrelacionado será simétrico, com os picos crescendo do começo até a metade.
void autocorrelacao(double *x, int m, double *y)
{
        int n, i;
        
        n = m + m - 1;

        for(i = 0; i < n; i++)
        {
                y[i] = 0;
                for(int k = 0; k < m; k++)
                {
                        if((i-k >= 0) && (i-k < m))
                        {
                                y[i] += x[i-k]*x[m-k-1];
                        }
                }
        }

        return;
}

//cálculo da frequência fundamental de vibração das cordas vocais ao longo do sinal.
double *frequencia_fundamental(double *y, int n, double a, double b, int *tam)
{
        int i, num_picos = 0, j = 0;

        //contagem dos picos
        for(i = 1; i < (n-1); i++)
        {
                if((y[i] > y[i-1]) && (y[i] > y[i+1]) && (y[i] > 0.95*(a*y[i] + b)))
                num_picos++;
        }

        //identificação de picos
        int posicao_picos[num_picos];
        
        for(i = 1; i < (n-1); i++)
        {
                if((y[i] > y[i-1]) && (y[i] > y[i+1]) && (y[i] > 0.95*(a*y[i] + b))) 
                {
                        posicao_picos[j] = i;
                        j++;
                }
        }

        //contagem das amostras entre picos e cálculo do POi(Período de Oscilação Inicial)
        double POi[num_picos - 1], aux[num_picos - 1];
        double *F0i;
        j = 0;

        for(i = 1; i < num_picos ; i++)
        {
                POi[j] = (double)(posicao_picos[i] - posicao_picos[i-1] - 1)/(double)taxa_amostragem;
                j++;
        }

        printf("POi:");
        imprimir(POi, num_picos - 1);

        //cálculo do F0i
        //F0i = (double *)malloc((num_picos - 1)*(sizeof(double))); //problema de alocação
        //F0i = new double[num_picos - 1];
        F0i = aux;
        *tam = (num_picos - 1);
        for(i = 0; i < (num_picos-1); i++)
        {
                F0i[i] = 1.0/POi[i];
        }

        printf("F0i:");
        imprimir(F0i, num_picos - 1);
        return F0i;     
}

//obtenção da média do sinal, considerando o F0i
double media(double *F0i, int tam)
{
        int i;
        double media, soma = 0.0;

        for(i = 0; i < 400; i++)
        soma = soma + F0i[i];
        
        media = soma/(double)tam;

        return media;
}

//obtenção da média geométrica do sinal, considerando o F0i
double media_geometrica(double *F0i, int tam)
{
        int i;
        long double mult = 1.0, media_g;

        for(i = 0; i < tam; i++)
        mult = mult*F0i[i];
        
        media_g = pow(mult, 1.0/tam);

        return media_g;
}

//obtenção do RMS(Root Mean Squared) do sinal, considerando o F0i
double RMS(double *F0i, int tam)
{
        int i;
        double soma = 0, media, rms;

        for(i = 0; i < tam; i++)
        soma = soma + pow(F0i[i], 2);

        media = soma/tam;
        rms = sqrt(media);

        return rms;     
}

//obtenção da dispersão do sinal, considerando o F0i
double dispersao(double *F0i, int tam, double media)
{
        int i;
        double dispersao, soma = 0;

        for(i = 0; i < tam; i++)
        soma = soma + pow((F0i[i] - media), 2);
        
        dispersao = soma/(tam-1);
        dispersao = sqrt(dispersao);

        return dispersao;
}

//obtenção do percentual de variabilidade do sinal, considerando o F0i
double percentual_variabilidade(double *F0i, int tam, double media)
{
        int i;
        double soma = 0, pv;

        for(i = 0; i < tam; i++)
        soma = soma + modulo((F0i[i] - media));
        
        pv = soma/tam;
        pv = pv/media;

        return pv;
}

//obtenção do coeficiente de consitência do sinal, considerando o F0i
double coeficiente_consistencia(double *F0i, int tam, double media)
{
        int i;
        double soma = 0, cc;

        for(i = 0; i < tam; i++)
        soma = soma + modulo((F0i[i] - media));
        
        cc = soma/tam;
        cc = media/cc;

        return cc;
}

void analisa_dados_brutos(double* s, int m) //sinal e seu tamanho
{
        int i, n; 
        double *x, *y;
        x = new double[m];
        y = new double[m + m -1];

        //PRÉ- PROCESSAMENTO
        //normalização da amplitude
        normalizacao_amplitude(&s[0], m);
       
        //remoção da frequência 0 hrtz
        remocao_media(&s[0], m);
        
        //remoção da irradiação labial, pré-ênfases
        remocao_irradiacao_labial(s, m, &x[0]);
        
        //Autocorrelação do sinal
        autocorrelacao(x, m, &y[0]);

        //Normalizar o sinal novamente
        n = m + m - 1;
        normalizacao_amplitude(&y[0], n);

        //identificação do menor e maior pico
        double ponto_1[2], ponto_2[2], coef_inclinacao, a, b;
        int flag = 0;
        i = 1;

        while(flag == 0)
        {
                if((y[i] > y[i-1]) && (y[i] > y[i+1]))
                {
                        ponto_1[0] = (double)i;
                        ponto_1[1] = y[i];
                        flag = 1;
                }
                i++;
        }

        //Encontrar a reta que ajudará na identificação dos picos
        int tam = n/2, tam_F0i;
        ponto_2[0] = (double)tam;
        ponto_2[1] = y[n/2];

        coef_inclinacao = (ponto_2[1] - ponto_1[1])/(ponto_2[0] - ponto_1[0]);
        a = coef_inclinacao;
        b = ponto_2[1] - (a*ponto_2[0]);

        double *F0i = frequencia_fundamental(y, n, a, b, &tam_F0i);
        delete [] y;
        
        //extração de características
        double c[7];

        c[0] = media(F0i, tam_F0i);
        c[1] = media_geometrica(F0i, tam_F0i);
        c[2] = RMS(F0i, tam_F0i);
        c[3] = dispersao(F0i, tam_F0i, c[0]);
        c[4] = c[3]/c[0]; //obtenção do coeficiente de variação
        c[5] = percentual_variabilidade(F0i, tam_F0i, c[0]);
        c[6] = coeficiente_consistencia(F0i, tam_F0i, c[0]);
        
        printf("\nC: ");
        for(i = 0; i< 7; i++)
        {
                printf("%.5f,", c[i]);
        }

        return;
}


//-------------------------------------------------------------
