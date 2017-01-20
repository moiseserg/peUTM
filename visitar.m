function indice = visitar(dists, tau, visitados)

	n = numel(tau);

	productos = tau .* dists.*(1-visitados);
	[val indx ] = sort(productos);

	suma = sum( val ~= 0 ) ;

	ranking = suma ./ [1:n]  .* (val ~= 0);
	sumaRank = sum(ranking);

	if(sumaRank>0)

		acumulado = cumsum(ranking);

		moneda = rand * sumaRank;

		for(i=1:n)
			if(acumulado(i)>=moneda  )
				indice = i; 
				break;
			end
		end
		
		indice = indx(indice) ;
	else
		novisitados = [];
		for(i=1:n)
			if(visitados(i)==0)
				novisitados = [novisitados i];
			end
		end
		%novisitados
		numNoVis = numel(novisitados);
		indice = int32(rand * (numNoVis-1)+1);

		indice = indx(novisitados(indice)) ;
		
	end




	

