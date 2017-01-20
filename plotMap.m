function plotMap(distancias, n, ciudades)

	figure(1);
	hold off
    axis([0 100 0 100]);
    
    for(i=1: n)
       for(j=1:n)
           if(distancias(i,j) ~= 10000)
               plot(  ciudades( 1, [i,j]), ... 
                  ciudades( 2, [i,j]), '*-'); 
               hold on;
           end
       end
    end