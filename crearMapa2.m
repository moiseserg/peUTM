function [ciudades, distancias, tau] = crearMapa2(n, knn)
    %knn = k-nearest neighbors
    
    ciudades= int32(rand(2, n)*100)

    

    for(i=1:int32(n/4))
      ciudades(1,i)=0;      
    end

    for(i=int32(n/4):int32(n/2))
      ciudades(1,i)=100;      
    end

    for(i=int32(n/2):int32(3*n/4))
      ciudades(2,i)=0;      
    end

    for(i=int32(3*n/4):n)
      ciudades(2,i)=100;      
    end

    ciudades([1,2],1)=[0,0];
    ciudades([1,2],int32(3*n/4))=[0,100];
    ciudades([1,2],int32(2*n/4))=[100,0];
    ciudades([1,2],int32(1*n/4))=[100,100];

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
          
               
    
    
    
    

