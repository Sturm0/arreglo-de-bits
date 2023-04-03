#include <iostream>
/*
la idea de este programa es hacer una implementación eficiente de un arreglo de bits
utilizando operadores lógicos bit a bit
*/
typedef unsigned short int usi;
class arreglo_bits {
	private:
		//la actual representación del arreglo utiliza un tipo de dato de 16 bit
		usi& a = *(new usi);
	public:
		//constructor
		arreglo_bits() {
			a = 0;
		}
		inline usi mostrar_variable() {
			return a;
		}
		usi insertar_elemento(usi índice, usi elemento) {
			if (elemento) return a |= (elemento<<índice);
			return a ^= (1<<índice);
		}
		inline usi obtener_elemento(usi índice) {
			return 1&(a>>índice);
		}
		void mostrar_arreglo() {
			for (int i = 0; i < 16; i++) std::cout << obtener_elemento(i) << " ";
			std::cout << '\n';
		}
		~arreglo_bits() {
			delete &a;
		}
};
int main() {
	arreglo_bits mi_arreglo;
	mi_arreglo.insertar_elemento(2,1);
	std::cout << mi_arreglo.obtener_elemento(2) << std::endl;
	mi_arreglo.insertar_elemento(13,1);
	mi_arreglo.insertar_elemento(15,1);
	mi_arreglo.mostrar_arreglo();
	mi_arreglo.insertar_elemento(13,0);
	mi_arreglo.insertar_elemento(15,0);
	mi_arreglo.mostrar_arreglo();
}
