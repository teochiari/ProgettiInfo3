import scala.collection.mutable.Queue
import scala.collection.mutable.ListBuffer


trait getterDati {
  def getCosto: Int
  def getTempoStampa: Int
}

abstract class CartaFotografica extends getterDati {
  val costo:Int
  val tempoStampa:Int
}

class FotoSingola extends CartaFotografica {
  val costo = 1
  val tempoStampa = 2
  def getCosto = this.costo
  def getTempoStampa = this.tempoStampa
}

class QuattroFoto extends CartaFotografica {
  val costo = 3
  val tempoStampa = 6
  def getCosto = this.costo
  def getTempoStampa = this.tempoStampa
}

class SeiFoto extends CartaFotografica {
  val costo = 4
  val tempoStampa = 8
  def getCosto = this.costo
  def getTempoStampa = this.tempoStampa
}

class TimelapseFoto() extends CartaFotografica {
  val costo = 6
  val tempoStampa = 12
  def getCosto = this.costo
  def getTempoStampa = this.tempoStampa
}

class CabinaFototessere {
  val tempoMassimo = 50
    def aggiungiCarta(c: FotoSingola) = CabinaFototessere.carta(0) += c
    def aggiungiCarta(c: QuattroFoto) = CabinaFototessere.carta(1) += c
    def aggiungiCarta(c: SeiFoto) = CabinaFototessere.carta(2) += c
    def aggiungiCarta(c: TimelapseFoto) = CabinaFototessere.carta(3) += c
    
    def stampaSelezione(codice:Int) = {
      if(CabinaFototessere.carta(codice-1).length==0) {
        println("Prodotto Esaurito")
      }
      else {
        var carta = CabinaFototessere.carta(codice-1).dequeue()
        if(CabinaFototessere.credito<carta.getCosto) {
          println("Non hai abbstanza credito, aggiungine altro premendo 7")
          CabinaFototessere.carta(codice-1) += carta
        }
        else{
          aggiungiTempo(carta.getTempoStampa)
          togliCredito(carta.costo)
        println("Erogazione prodotto")
        }
      }
      stampaDisponibilitàCarta
    }
    
    def stampaDisponibilitàCarta = {
      println("Disponibilità")
      println("Singola  4__Foto  6__Foto  Timelapse")
      CabinaFototessere.carta.map(x => print(x.length+"        "))
      println("")
    }
    
    def ricaricaCarta(num:Int)={
      val fotoSingola = new FotoSingola()
      val QuattroFoto = new QuattroFoto()
      val seiFoto = new SeiFoto()
      val timelapseFoto = new TimelapseFoto()
      for(i<- 1 to num){
        aggiungiCarta(fotoSingola)
        aggiungiCarta(QuattroFoto)
        aggiungiCarta(seiFoto)
        aggiungiCarta(timelapseFoto)
      }
    }
    
    def greetings = {
      println("Tempo di Utilizzo: "+getTempo)
      println("Uscita dalla cabina, grazie")
    }
    
    def aggiungiCredito(credito:Int)={
      CabinaFototessere.credito += credito
    }
    
    def togliCredito(credito:Int)={
      CabinaFototessere.credito -= credito
    }
    
    def aggiungiTempo(tempo:Int)={
      CabinaFototessere.tempo += tempo
    }
    
    def stampaCredito = {
      println("Credito: "+CabinaFototessere.credito+" ")
    }
    
    def stampaTempo = {
      println("Tempo: "+CabinaFototessere.tempo+" ")
    }
    
    def inserisciCredito = {
      println("Quanto credito vuoi aggiungere?[Solo numeri]")
      val credito = scala.io.StdIn.readLine()
      var creditoInt:Int = 0
      if(credito!="") creditoInt = credito.toInt
      aggiungiCredito(creditoInt)
    }
    
    def getTempo = {
      CabinaFototessere.tempo
    }
}
object CabinaFototessere {
  private var carta = Array[Queue[CartaFotografica]](Queue[CartaFotografica](), Queue[CartaFotografica](), Queue[CartaFotografica](), Queue[CartaFotografica]())
  private var tempo = 0
  private var credito = 0
}

object test {
   def main(args: Array[String]){
     var cabinaOpen = true
     //println("Ciao Matteo")
     val cabina = new CabinaFototessere()
     cabina.ricaricaCarta(1)
     //cabina.stampaDisponibilitàCarta
     while(cabinaOpen && cabina.getTempo<=cabina.tempoMassimo){
       println("Quale tipo di fortografia desideri? (Inserire il codice relativo)")
       println("1:  Foto Singola")
       println("2:  4 Foto")
       println("3:  6 Foto")
       println("4:  Timelapse Foto")
       println("7:  Inserisci Credito")
       println("8:  Ricarica Carta")
       println("9:  Esci dalla Cabina")
       cabina.stampaDisponibilitàCarta
       cabina.stampaTempo
       cabina.stampaCredito
       val codice = scala.io.StdIn.readLine()
       var codiceInt:Int = 0
       if(codice!="") codiceInt = codice.toInt
       if(codiceInt==8) cabina.ricaricaCarta(1)
       if(codiceInt==7) cabina.inserisciCredito
       else if(codiceInt==9) cabinaOpen = false
       else if(codiceInt<=4 && codiceInt>=1) cabina.stampaSelezione(codiceInt)
     }
     cabina.greetings
   }
}