/*
path C:\Program Files (x86)\java\jdk1.7.0\bin
cd c:\1
javac Count_flowers_java7_swing.java
java Count_flowers_java7_swing
javac -Xlint:unchecked *.java
jar cmf manif.txt  Count_flowers_java7_swing.jar *.class
*/
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class Count_flowers_java7_swing  {
 static int d = 120; //1 flower size
 static String s = "";
 static String s2 = "";
 static int answ=-1;
 static int phase=1;
 static int randt=0;
 static int[] arrc = new int[13];
 static int[] arrs = new int[13];
 static    JFrame jFrame = new JFrame("__ Count Flowers Java7 Swing by OlegTim __");
 static Sol2 field = new Sol2();

 static class Sol2 extends JPanel implements ActionListener {
  Sol2(){
   jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

   JLabel jlab = new JLabel();
   JMenuBar jmb = new JMenuBar();
   JMenu info = new JMenu("info");
   JMenuItem info_show = new JMenuItem("info_show");
   jmb.add(info);
   info_show.addActionListener(this);
   info.add(info_show);
   jFrame.add(jlab);
   jFrame.setJMenuBar(jmb);

   jFrame.addWindowListener(new java.awt.event.WindowAdapter() {
    @Override
    public void windowClosing(java.awt.event.WindowEvent windowEvent) {
     try{} catch (Exception e){}
     System.exit(0);
    }
   });

   jFrame.addKeyListener(new KeyAdapter() {
    public void keyPressed(KeyEvent e) {
     if (e.getKeyCode()==KeyEvent.VK_ESCAPE) {System.exit(0);}
     if (e.getKeyCode()==KeyEvent.VK_0) {answ=0; answf();}
     if (e.getKeyCode()==KeyEvent.VK_1) {answ=1; answf();}
     if (e.getKeyCode()==KeyEvent.VK_2) {answ=2; answf();}
     if (e.getKeyCode()==KeyEvent.VK_3) {answ=3; answf();}
     if (e.getKeyCode()==KeyEvent.VK_4) {answ=4; answf();}
     if (e.getKeyCode()==KeyEvent.VK_5) {answ=5; answf();}
     if (e.getKeyCode()==KeyEvent.VK_6) {answ=6; answf();}
     if (e.getKeyCode()==KeyEvent.VK_7) {answ=7; answf();}
     if (e.getKeyCode()==KeyEvent.VK_8) {answ=8; answf();}
     if (e.getKeyCode()==KeyEvent.VK_9) {answ=9; answf();}
    }});//key pressed end

   jFrame.setBounds(0,0,650,470);
   jFrame.setVisible(true);
  }

  public void drawf() {repaint();}

  @Override
  protected void paintComponent(Graphics g) {
   super.paintComponent(g);

Color   c = new Color(0, 0, 0);
int col = 0;
int shape = 0;
int colr = 0; int colg = 0; int colb = 0;
int x =0; int y=0;

   for (int i2 = 0; i2<4; i2++){
    for (int i = 0; i<4; i++){

     if (i+4*i2<13){
      col = arrc[i+4*i2];
      shape = arrs[i+4*i2];

      if (i+4*i2==12){
       x=4*d+d/5;y=0;
       c = new Color(155, 155, 155);
       g.setColor(c);
       g.fillRect(x-d/10, y, d+d/5, d*2);
      }

   switch (col){
    case 0: {colr=0; colg=0; colb=0; break;} //black for any color
    case 1: {colr=0; colg=255; colb=0; break;}
    case 2: {colr=0; colg=0; colb=255; break;}
    case 3: {colr=255; colg=255; colb=0; break;}
    case 4: {colr=0; colg=255; colb=255; break;}
    case 5: {colr=255; colg=0; colb=255; break;}
    case 6: {colr=255; colg=0; colb=0; break;}
    case 7:  {colr=255; colg=255; colb=255; break;}
   }
    c = new Color(colr, colg, colb);
   g.setColor(c);

   if (shape==0){ //for any shape
    g.fillRect(x, y, d, d);
   }
   if (shape==1){
    g.fillOval(x+5*d/16, y+2*d/16, 6*d/16,6*d/16);
    g.fillOval(x+5*d/16, y+8*d/16, 6*d/16,6*d/16);
    g.fillOval(x+2*d/16, y+5*d/16, 6*d/16,6*d/16);
    g.fillOval(x+8*d/16, y+5*d/16, 6*d/16,6*d/16);
   }
   if (shape==2){
    Polygon p = new Polygon();
    p.addPoint(x+6*d/16,y+d/2);
    p.addPoint( x+d/2 , y);
    p.addPoint(x+10*d/16, y+d/2);
    g.fillPolygon(p);
    Polygon p2 = new Polygon();
    p2.addPoint(x+6*d/16,y+d/2);
    p2.addPoint( x+d/16 , y+15*d/16);
    p2.addPoint(x+10*d/16, y+d/2);
    g.fillPolygon(p2);
    Polygon p3 = new Polygon();
    p3.addPoint(x+6*d/16,y+d/2 );
    p3.addPoint( x+15*d/16 , y+15*d/16 );
    p3.addPoint(x+10*d/16, y+d/2);
    g.fillPolygon(p3);
   }
   if (shape==3){
    g.fillOval(x+3*d/8, y, 2*d/8,d/2);
    g.fillOval(x+3*d/8, y+d/2, 2*d/8,d/2);
    g.fillOval(x, y+3*d/8, d/2,d/4);
    g.fillOval(x+d/2, y+3*d/8, d/2,d/4);
   }
   if (shape==4){
    g.fillOval(x, y, d, d);
   }

   c = new Color(215, 175, 150);
   g.setColor(c);
   g.fillOval(x+3*d/8, y+3*d/8, 2*d/8, 2*d/8);
     }
     x=x+d;
    }
    x=0; y=y+d;
   }

   g.setFont(new Font("Arial", Font.BOLD, 16));
   c = new Color(220, 220, 220);
   g.setColor(c);
   x=5;y= 3*d+d/5;
   g.drawString(s, x, y);
   y+=d/5;
   g.drawString(s2, x, y);

   if (phase!=1){
    x=4*d+d/5;y=d;
    Polygon p4 = new Polygon();
    if (phase==3) {c = new Color(255, 0, 0);
     p4.addPoint(x,y );
     p4.addPoint(x+d/5,y );
     p4.addPoint(x+d/2,y+d/2 );
     p4.addPoint(x+4*d/5,y );
     p4.addPoint(x+d,y );
     p4.addPoint(x+d/2,y+d/2 );
     p4.addPoint(x,y+d );
     p4.addPoint(x+d/5,y+d );
     p4.addPoint(x+d/2,y+d/2 );
     p4.addPoint(x+4*d/5,y+d );
     p4.addPoint(x+d,y+d );
    } else{
     c = new Color(0, 255, 0);
     p4.addPoint(x,y );
     p4.addPoint( x+d/2 , y+d/2 );
     p4.addPoint(x+d, y);
     p4.addPoint(x+d/2, y+d/4);
    }
    g.setColor(c);
    g.fillPolygon(p4);
   }
 }


  @Override
  public void actionPerformed(ActionEvent e) {
   String comstr = e.getActionCommand();
   if (comstr.equals("info_show")){
    JOptionPane.showMessageDialog(null,
            new String[] {"__ Count Flowers Java7 Swing by OlegTim __ "+System.lineSeparator()+System.lineSeparator()+
                    "Count the number of flowers by colour, shape or both."+System.lineSeparator()+
                    "Press any number button (0-9) to answer, check if it's right and continue."+System.lineSeparator()+
                    ""+System.lineSeparator()+
 "Tested at 650*470 pix; screen fits 4 columns and 3 rows of flowers and 2 text rows below."+System.lineSeparator()+
                    ""+System.lineSeparator()+
                    "Press <num> to answer; <Esc> to quit. "+System.lineSeparator()+
                    " Best wishes, OlegTim."},
            "Info",
            JOptionPane.PLAIN_MESSAGE);
   }
  }
 }

 static int isfieldfull(){
  int m=0;
  for (int i = 0; i<12; i++){if (arrc[i]==0){m++;}}
  return m;
 }

 static int countfl(){
  int m=0;
  if (arrc[12]==0){
   for (int i = 0; i<12; i++){if (arrs[i]==arrs[12]){m++;}}
  }else{if (arrs[12]==0){
   for (int i = 0; i<12; i++){if (arrc[i]==arrc[12]){m++;}}
  }else{
   for (int i = 0; i<12; i++){if (arrs[i]==arrs[12]&&arrc[i]==arrc[12]){m++;}}
  }}
  return m;
 }

 static int getrandnum(){ //0-11
  int m=99;
  while (m>11){m=getrandnum2();}
  return m;
 }
 static int getrandnum2(){
  int m = (int) ( Math.random() * 12.0 );
  return m;
 }

 static int getrandc(){
  int m = (int) ( Math.random() * 10.0 );
  if (m==8){m=3;} if (m==9){m=4;}
  return m;
 }

 static int getrands(){
  int m = (int) ( Math.random() * 10.0 );
  if (m==5){m=1;} if (m==6){m=3;} if (m==7){m=3;} if (m==8){m=4;} if (m==9){m=1;}
  return m;
 }

 static void clearf(){
  for (int i = 0; i<13; i++){arrc[i]= arrs[i]=0;}
 }

static void genf(){
 clearf();
 randt = (int) ( Math.random() * 10.0 );
 randt = randt%10;
  if (randt==3||randt==9){if (randt==3){randt=9;}else{randt=3;}}

  int c = getrandc();
  int s = getrands();

  if (c==0&&s==0){c=1;}
  arrc[12]=c;
  arrs[12]=s;
  int n =  0;

  while (countfl()<randt){ //fill field with guessed type start
   n =  getrandnum();
   int t=0;
   if (arrc[n]==0){
    t=arrc[12];
    if (arrc[12]==0){t = getrandc();}
    if (t==0) {t++;}
    arrc[n]=t;
    t=arrs[12];
    if (arrs[12]==0){t = getrands();}
    if (t==0) {t++;}
    arrs[n]=t;
   }
  } //fill field with guessed type end

 while (isfieldfull()!=0){ //fill field with other type start

  n =  getrandnum();
  int t=0;

  if (arrc[n]==0){
   t = getrandc();
   while(t==0||t==arrc[12]) {t = getrandc();}
   arrc[n]=t;
   t = getrands();
   while(t==0||t==arrs[12]) {t = getrands();}
   arrs[n]=t;

   if (arrc[12]!=0&&arrs[12]!=0){
    t = getrandc();
    while(t==0) {t = getrandc(); }
    arrc[n]=t;
    if (arrc[n]!=arrc[12]){
     t = getrands();
     while(t==0) {t = getrands(); }
     arrs[n]=t;
    }
   }

  } // if(arrc[n]==0) end
 } //fill field with other type end
 genl();
 }//genf() end

static void genl(){
String   sc = "";
  if (arrc[12]==1){sc="green ";}
  if (arrc[12]==2){sc="blue ";}
  if (arrc[12]==3){sc="yellow ";}
  if (arrc[12]==4){sc="aqua ";}
  if (arrc[12]==5){sc="violet ";}
  if (arrc[12]==6){sc="red ";}
  if (arrc[12]==7){sc="white ";}
  String sh = "";
  if (arrs[12]==1){sh="bubble ";}
  if (arrs[12]==2){sh="spike ";}
  if (arrs[12]==3){sh="cross ";}
  if (arrs[12]==4){sh="round ";}
  s="How many "+sc+sh+"flowers are there?";
 }

 static void answf(){
  if (phase==2||phase==3){
   phase=1;
   s2="";
   genf();
   field.drawf();
  }else{
    if (phase==1){
     if (answ==randt){phase=2;
      s2=answ+" is OK! Press <num> for new game";
      field.drawf();
     }
     else {phase=3;
      s2=answ+" is wrong. The answer is: "+randt+". Press <num> for new game";
      field.drawf();
     }
    }}
 }

 public static void main(String[] args) {
  field.setBackground(Color.black);
  jFrame.add(field);
  genf();
  field.drawf();
}
}
