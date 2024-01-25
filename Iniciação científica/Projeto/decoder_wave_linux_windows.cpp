#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
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
double modulo(double num)
{
        if(num > 0)
        return num;
        else
        return (-num);
}

void analisa_dados_brutos(double* s, int m) //sinal e seu tamanho
{
        int i; 
        double maior, media = 0, y[m];

        //PRÉ- PROCESSAMENTO
        //normalização da amplitude
        maior = modulo(s[0]);
        for(i = 0; i<m; i++)
        {
                if(modulo(s[i]) > maior)
                maior = modulo(s[i]);
        }
        for(i=0; i<m; i++)
        {
                s[i] = s[i]/maior;
        }

        //remoção da frequência 0 hrtz
        for(i=0; i<m; i++)
        {
                media = media + s[i];
        }
        media = media/m;

        for(i=0; i<m; i++)
        {
                s[i] = s[i] - media;
        }

        //remoção da irradiação labial, pré-ênfases
        for(i = 1; i<(m-1); i++)
        {
                y[i] = s[i] + (0.95*y[i-1]);
        }
        y[0] = s[1];
        y[m] = s[1];

}


//-------------------------------------------------------------
