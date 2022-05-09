#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> zaehler(11);


double poisson(double mu, int k){//Berechnet die Poissonwahrscheinlichkeit (mu^k)*exp(-mu)/k!
  double muk = pow(mu,k);
  double expmu = exp(-mu);
  double k_fak = tgamma(k+1);
  return muk*expmu/k_fak;
}

int Poissonverteilung_1ab(){
  int zahl;
  ofstream fout ("hist.txt");
  ifstream fin("datensumme.txt");

  for(int i = 0; i < 234; i++){//Liest aus Datensumme aus und zählt die jeweiligen Anzahlen der Ziffern 0-9
    fin >> zahl;
    zaehler[zahl] += 1;
  }
  for(int i = 0; i < zaehler.size(); i++){//Schriebt Inhalt des Vektors in hist.txt 
    //cout << zaehler[i] << endl;
    fout << i << " " << zaehler[i] << endl;
  }

  fin.close();
  fout.close();
}
int main(){
  Poissonverteilung_1ab();
  double mu = 3.11538;

  ofstream histpoi ("histpoi.txt");

  for (int i = 0; i < zaehler.size(); i++){
    histpoi << i << " " << zaehler[i] << " " << 234*poisson(mu,i) << endl;
    
  }
  histpoi.close();
}
  