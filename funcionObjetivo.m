function  z = funcionObjetivo(x, dists, tam)
     % x =vector de la permutacion
     % dists = matriz de distancias
     % tam = numero de elemenos en x
    z = 0;
    for(i=1: tam-1)
           z = z + dists( x(i), x(i+1)  );
    end
    z = z+dists( x(tam), x(1));
