clear all;
clc
%parametros del problema
n = 40;
knn = 3;
nh = 1000;
incremento=0.15;
Q = 800;
tic
%escenario para el problema
[cds dists  tau] =crearMapa2(n, knn);

caminos = zeros(nh, n);
costos = zeros(nh,1);
mejor = inf;
mejorIndice = 0;


for(generaciones=1:1)

	
	for(ii=1:nh)

		pos = int32(rand * (n-1) + 1);
		camino = [pos];

		%bandera de visitados
		visitados = zeros(1,n);
		visitados(pos)  = 1;

		%se buscan las siguientes posiciones a visitar.
		for(i=2:n)

			%visitados
			proximaVisita = visitar(  ...
				dists(pos,:), tau(pos, :), visitados);

			pos = proximaVisita;
			visitados(pos) = 1;
			camino = [camino pos];			
			
		end
		caminos(ii, :) = camino;  
		costos(ii) = funcionObjetivo(camino, dists, n) ;

		if(costos(ii) < mejor)
			mejor = costos(ii); 
			mejorIndice = ii;
			plotMap(dists, n, cds);
			
			plotsol(camino, cds);
			pause(1);
		end
	end

	[val, indmin] = min(costos);

	plotMap(dists, n, cds);
	plotsol(caminos(indmin, :), cds, mejor);

	tau = tau * (1+incremento);

	[vals indx ] = sort(costos);


	for(ii=1:nh/4)
		indice = indx(ii);
		printf('cambiando %d con costo %.3f\n',indice, costos(indice) );	
		camino = caminos(indice, :);
		for(j=1:n-1)
			tau(camino(j), camino(j+1)) = ...
			 tau(camino(j), camino(j+1))*( costos(indice)/ Q);
		end
		tau(camino(n), camino(1)) = tau(camino(n), camino(1)) *( costos(indice)/ Q);
	end
	tau

end
toc
