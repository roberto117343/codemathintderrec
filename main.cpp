/*
 * «Copyright 2017 Roberto Reinosa»
 * 
 * This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * */
 
#include <iostream>
#include <cmath>

using namespace std;

class calculo{
	
	public:
		
		double integral(double _inferior, double _superior){
			
			double y = 0;
			double x = 0;
	
			double inferior = _inferior;
			double superior = _superior;
	
			const double base = 0.00001;
	
			double area_Total = 0;
			
			for(double i = inferior; i < superior; i += 0.00001){
				
				x = i;
				
				y = funcion(x);
		
				area_Total += base * y;
	
			}
			
			return area_Total;
			
		}
		
		double derivada(double _x){
			
			double y1, y2;
			double x = _x;
			double m;
			
			const double intervalo = 0.00001;
			
			double x1, x2;
			
			x1 = x - intervalo;
			x2 = x + intervalo;
			
			y1 = funcion(x1);
			y2 = funcion(x2);
			
			m = (y2-y1)/(x2-x1);
			
			return m;
			
		}
		
		double rectificacion(double _inferior, double _superior){
			
			double inferior = _inferior;
			double superior = _superior;
			
			double x;
			double y1;
			double y2;
			
			double L = 0;
			
			for(double i = inferior; i <= superior ; i += 0.00001){

				x = i;
				y1 = funcion(x);
				y2 = funcion(x + 0.00001);
				
				L += sqrt(pow(0.00001, 2) + pow((y2-y1), 2));
				
			}
				
			return L;
		}
		
		void funcion_datos(double _inferior, double _superior){
			
			double inferior = _inferior;
			double superior = _superior;
			
			double x;
			double y;
			
			for(double i = inferior; i <= superior; i += 0.01){
				
				x = i;
				y = funcion(x);
				
				cout << x << " " << y << endl;
				
			}	
		}
		
	private:
		
		double inline funcion(double _x){
			
			double x = _x;
			
			double y = pow(x, 2.0); // Función

			return y;
		}
		
};

int main(){
	
	calculo micalculo;
	
	//cout << micalculo.integral(-2.0, 3.0) <<endl;
	
	//cout << micalculo.integral(0.0, 2.0) <<endl;
	
	//cout << micalculo.integral(0.0, 3.14159/4.0) <<endl;
	
	//micalculo.funcion_datos(0.0, 1.01);
		
	//cout << micalculo.rectificacion(5.0/9.0, 21.0/9.0) <<endl; 
		
	cout << micalculo.derivada(1.0) <<endl; 
		
	/*for(double i = -2.0; i <= 4.0; i+=0.01){ 
		
		cout << i << " " << micalculo.derivada(i) <<endl;
			
	}*/	
	
	cout << "\nIntroduce 1. Para Salir\n"<< endl;
	int pausa;
	
	while(pausa != 1){
		cin>>pausa;
	}
	
	return 0;
	
}
