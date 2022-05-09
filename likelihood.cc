#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


double poisson(double mu, int k){//Berechnet die Poissonwahrscheinlichkeit (mu^k)*exp(-mu)/k!
  double muk = pow(mu,k);
  double expmu = exp(-mu);
  double k_fak = tgamma(k+1);
  return muk*expmu/k_fak;
}

double prob(vector<int> daten, double mu){

  
}

int main() {
  ifstream fin("datensumme.txt");
  int k_i, zahl;
  vector<int> daten;
  for(int i = 0 ; i < 234 ; ++i) {
    fin >> zahl;
    daten.push_back(zahl);
  }
  fin.close();
}