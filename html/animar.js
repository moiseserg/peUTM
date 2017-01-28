/**
 * Created by emmanuel on 27/01/17.
 */

function mover() {
    var elem = document.getElementById("animate");
    var pos = 0;


    var id = setInterval(frame, 5);
    function frame() {
        if (pos == 350) {
            clearInterval(id);
        } else {
            pos++;
            elem.style.top = pos + 'px';
            elem.style.left = pos + 'px';
        }
    }
}


function mover2() {
    var elem = document.getElementById("animate");
    var posx = 0;
    var posy = 350;
    var vely = 80;
    var gravedad = 9.8;
    var tiempo = 0;


    var id = setInterval(frame, 15);

    function frame() {
        if (posx >= 350 || posy>380) {
            clearInterval(id);
        } else
        {
            posx++;
            tiempo+=0.05;
            posy =350- Math.round(-0.5*gravedad*tiempo*tiempo + vely * tiempo);

            console.log('pos y ' + posy );
            elem.style.top = posy + 'px';
            elem.style.left = posx + 'px';
        }
    }
}

function  ponerFantasma() {
    var fant = document.getElementById('fantasma');
    var piza = document.getElementById("pizarra");

    var controlador = piza.getContext("2d");
    controlador.drawImage(fant,10,10);

}


function  moverFantasma() {
    var fant = document.getElementById('fantasma');
    var piza = document.getElementById("pizarra");

    var controlador = piza.getContext("2d");
    controlador.drawImage(fant,0,0, 32, 32, 100,100,32,32);


}




function  mover2Fantasma() {
    var fant = document.getElementById('fantasma');
    var piza = document.getElementById("pizarra");

    var controlador = piza.getContext("2d");
    controlador.drawImage(fant,0,0, 32, 32, 100,100,32,32);


    var id = setInterval(frame, 60);
    var  sy=0;


    function frame() {
        controlador.drawImage(fant,0,sy*32, 32, 32, 100,100,32,32);
        sy = (sy+1)%8;

    }


}




function  mover3Fantasma() {
    var fant = document.getElementById('fantasma');
    var piza = document.getElementById("pizarra");

    var controlador = piza.getContext("2d");
    controlador.drawImage(fant,0,0, 32, 32, 100,100,32,32);
    controlador.fillStyle="#ffffff";


    var id = setInterval(frame, 50);
    var  sy=0;
    var posx=100;
    var posy=100;
    var dirx=1;



    function frame() {
        controlador.fillRect(posx-4 , posy,38,32);
       // controlador.drawImage(fant,0,9*32, 32, 32, posx,posy,32,32);
        console.log('a pos x =' + posx + ' pos y ' +posy);

        // controlador.stroke();
        controlador.drawImage(fant,0,sy*32, 32, 32, posx,posy,32,32);
        console.log('b pos x =' + posx + ' pos y ' +posy);
        sy = (sy+1)%8;

        posx +=dirx*4  ;

        if(posx >= 350)
            dirx = -1;

        else if(posx<100)
            dirx = 1;

        console.log('c pos x =' + posx + ' pos y ' +posy);
    }


}