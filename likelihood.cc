#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

double poisson(double mu, int k){//Berechnet die Poissonwahrscheinlichkeit (mu^k)*exp(-mu)/k!
  double muk = pow(mu,k);
  double expmu = exp(-mu);
  double k_fak = tgamma(k+1);
  return muk*expmu/k_fak;
}

double prob(vector<int> daten, double mu){//Berechnet die Likelihood der einzelnen Datensummen
  double L=1;
  for(int k : daten){
    L *= poisson(mu,k);
  }
  return L;
}

double prob_quot(vector<int> daten, double mu){
  double L = 1;
  double Q = 1;
  L = prob(daten, mu);
  for(int k : daten){
     Q *= poisson(k,k);
  }
  return L/Q;
  
}

int main() {
  const double mu = 3.11538;
  double n_dof = 233.00;
  ifstream fin("datensumme.txt");
  ofstream fout("likelihood.txt");
  ofstream fout2("nll.txt");
  ifstream fin2("nll.txt");
  ofstream fout3("deltanll.txt");
  int k_i, zahl;
  vector<int> daten;
  for(int i = 0 ; i < 234 ; ++i) {
    fin >> zahl;
    daten.push_back(zahl);
  }
  for(double i = 0; i <= 6; i += 0.01){
    fout << i << " " << prob(daten,i) << endl;
    fout2 << i << " " << -2*log(prob(daten,i)) << endl;
    fout3 << i << " " << -2*log(prob(daten,i))+2*log(prob(daten, mu)) << endl;
  }

  cout << -2*log(prob_quot(daten, mu)) << endl;//Ergebnis: 233.942
  double z = ((-2*log(prob_quot(daten, mu))-n_dof)/sqrt(2*n_dof));
  cout << z << endl;
  
  
  fin.close();
  fout.close();
  fout2.close();
  //cout << prob(daten,mu) << endl; 
}