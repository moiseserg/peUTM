function [ciudades, distancias, tau] = crearMapa(n, knn)
    %knn = k-nearest neighbors
    
    ciudades= int32(rand(2, n)*100);
    plot(ciudades(1,:), ciudades(2,:), '*b');
    
    distancias = zeros(n);
    for(i=1:n)
        for(j=1+i:n)
            distancias(i, j)= sqrt(  double(ciudades(1,i)-ciudades(1,j))^2 +double(ciudades(2,i)-ciudades(2,j))^2 );
            distancias(j, i)= distancias(i, j);
        end
    end
     
    for(i=1:n)
        [ord indx ] = sort( distancias(i,:));
        for(j=2+knn:n)
            distancias(i,indx(j))=0;
        end
    end
    
    figure(1);
    axis([0 100 0 100]);
    for(i=1: n)
       for(j=1:n)
           if(distancias(i,j)>0)
               plot(  ciudades( 1, [i,j]), ciudades( 2, [i,j]), '*-'); 
               hold on;
           end
       end
    end
    
   % hold off;
    

    for(i=1: n)
       for(j=1:n)
           if(distancias(i,j)~=0)
               distancias(j,i) = distancias(i,j);
           end
       end
     end 

     for(i=1: n)
       for(j=1:n)
           if(distancias(i,j)==0)
               distancias(i,j) = 10000;
           end
       end
     end 


     tmp = sum(sum(distancias < 10000));
     tau= double(distancias < 10000)/tmp;
          
               
    
    
    
    

