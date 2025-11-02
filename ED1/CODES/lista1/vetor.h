
typedef struct {
    float x, y, z;
}Vetor;

Vetor* cria(float x, float y, float z);
void libera(Vetor* vetor);
Vetor soma(Vetor vetor1, Vetor vetor2);
float prodInterno(Vetor vetor1, Vetor vetor2);
Vetor prodVet(Vetor vetor1, Vetor vetor2);
