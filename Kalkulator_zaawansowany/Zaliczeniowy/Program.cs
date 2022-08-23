using System;
using System.Threading.Tasks;
using static Zaliczeniowy.Calki;
using static Zaliczeniowy.Ulamek;
using static Zaliczeniowy.Calkowite;
using static Zaliczeniowy.Trygonom;
using System.Threading;

namespace Zaliczeniowy
{

    class Program
    {

        private static double funkcjaS(double f)
        {
            //Console.Write("\nf= ");
            //double f = double.Parse(Console.ReadLine());
            return f;
        }

        static void main_menu()
        {
            Console.WriteLine("" +
                "  1. Dodawanie\n" +
                "  2. Odejmowanie\n" +
                "  3. Wartość bezwzględna\n" +
                "  4. Mnożenie\n" +
                "  5. Dzielenie\n" +
                "  6. Potęgowanie\n" +
                "  7. Logarytmowanie\n" +
                "  8. Pierwiastkowanie\n" +
                "  9. Pierwiastkowanie zaawansowane\n" +
                "  10. Obliczanie całek\n" +
                "  11. Przeliczanie funkcji trygonometrycznych:" +
                "\n  0 - wyjście z programu");

        }

        static void menu_tryg()
        {
            Console.WriteLine("" +
                " Przeliczanie funkcji trygonometrycznych:" +
                "\n       a. Sinusów" +
                "\n       b. Cosinusów" +
                "\n       c. Tangensów" +
                "\n       d. Cotangensów" +
                "\n       e. Arcus sinusów" +
                "\n       f. Arcus cosinusów" +
                "\n       g. Arcus tangensów" +
                "\n       h. Arcus cotangensów" +
                "\n  w - wyjście do poprzedniego menu");

        }



        static void menu_calki()
        {
            Console.WriteLine("" +
                "\n Całkowanie: " +
                "\n       t. metodą trapezów" +
                "\n       p. metodą prostokątów" +
                "\n       s. metodą Simpsona" +
                "\n  w - wyjście do poprzedniego menu");

        }


        static void Main(string[] args)
        {
            Console.WriteLine("Witaj użytkowniku! " +
                "\nOto prosty, a zarazem rozszerzony kalkulator\n");

            Console.WriteLine("");

            int wybor = 1;// = int.Parse(Console.ReadLine());

            Calkowite liczba1, liczba2;
            Calkowite wynik = new Calkowite(0);

            while (wybor != 0)
            {

                    Console.WriteLine("\nDziałania jakie możesz wykonywać: ");
                    main_menu();
                    Console.WriteLine("");
                    Console.WriteLine("To co robimy? ");

                    wybor = int.Parse(Console.ReadLine());


                switch (wybor)
                {
                   
                    //##################################  DODAWANIE  #########################################################
                    case 1:

                        Console.WriteLine("Dodajemy liczby całkowite - c ,czy rzeczywiste - r? ");
                        char cr = char.Parse(Console.ReadLine());
                        switch (cr)
                        {
                            case 'c':
                                Console.WriteLine("To podaj proszę liczby całkowite, które chcesz dodać: \n");
                                // Rzeczywiste liczba1, liczba2;
                                Console.Write("Liczba 1: ");
                                int l1 = int.Parse(Console.ReadLine());
                                Console.Write("Liczba 2: ");
                                int l2 = int.Parse(Console.ReadLine());
                                liczba1 = new Calkowite(l1);
                                liczba2 = new Calkowite(l2);

                                wynik = liczba1 + liczba2;
                                wynik.view();
                                Thread.Sleep(2500);
                                break;

                            case 'r':
                                Console.WriteLine("To podaj proszę liczby rzeczywiste, które chcesz dodać: \n");
                                Console.Write("Liczba 1: ");
                                double r1 = double.Parse(Console.ReadLine());
                                Console.Write("Liczba 2: ");
                                double r2 = double.Parse(Console.ReadLine());

                                Console.WriteLine("Suma wynosi: {0}", r1 + r2);
                                Thread.Sleep(2500);
                                break;

                            default:
                                Console.WriteLine("Nie ma takiej opcji! Wybierz jeszcze raz.\n");
                                Thread.Sleep(2000);
                                break;


                        }

                        break;

                    //#####################################  ODEJMOWANIE  ######################################################
                    case 2:
                        Console.WriteLine("Dodajemy liczby całkowite - c, czy rzeczywiste - r? ");
                        cr = char.Parse(Console.ReadLine());

                        switch (cr)
                        {
                            case 'c':
                                Console.WriteLine("To podaj proszę liczby całkowite, które chcesz odjąć: ");
                                //Rzeczywiste liczba3, liczba4;
                                int l3 = int.Parse(Console.ReadLine());//tu mi zwraca inta
                                int l4 = int.Parse(Console.ReadLine());
                                liczba1 = new Calkowite(l3);
                                liczba2 = new Calkowite(l4);

                                wynik = liczba1 - liczba2;
                                wynik.view();
                                Thread.Sleep(2500);
                                break;
                            case 'r':
                                Console.WriteLine("To podaj proszę liczby rzeczywiste, które chcesz odjąć: ");
                                double r1 = double.Parse(Console.ReadLine());
                                double r2 = double.Parse(Console.ReadLine());
                                Console.WriteLine("Różnica wynosi: {0}", r1 - r2);
                                Thread.Sleep(2500);
                                break;
                            default:
                                Console.WriteLine("Nie ma takiej opcji! Wybierz jeszcze raz.\n");
                                Thread.Sleep(2000);
                                break;
                        }

                        Thread.Sleep(2500);
                        break;

                    //################################  WARTOŚĆ BEZWZGLĘDNA  #########################################################
                    case 3:
                        Console.WriteLine("Podaj proszę liczbę, dla której będzie podana jej wartość bezwzględna: ");
                        double r = double.Parse(Console.ReadLine());

                        Console.WriteLine("Wartość bezwzględna dla podanej liczby to: {0}", Math.Abs(r));

                        //    Console.WriteLine("To co robimy dalej? ");
                        Thread.Sleep(2500);
                        break;

                    //#########################################  MNOŻENIE  ##################################################
                    case 4:

                        Console.WriteLine("Mnożymy liczby całkowite - c, czy rzeczywiste - r? ");
                        cr = char.Parse(Console.ReadLine());

                        switch (cr)
                        {
                            case 'c':
                                Console.WriteLine("To podaj proszę liczby całkowite, które chcesz wymnożyć: \n");
                                Console.Write("Liczba 1: ");
                                int l5 = int.Parse(Console.ReadLine());
                                Console.Write("Liczba 2: ");
                                int l6 = int.Parse(Console.ReadLine());
                                liczba1 = new Calkowite(l5);
                                liczba2 = new Calkowite(l6);

                                wynik = liczba1 * liczba2;
                                wynik.view();
                                Thread.Sleep(2500);
                                break;

                            case 'r':
                                Console.WriteLine("To podaj proszę liczby rzeczywiste, które chcesz wymnożyć: \n");
                                Console.Write("Liczba 1: ");
                                double r1 = double.Parse(Console.ReadLine());
                                Console.Write("Liczba 2: ");
                                double r2 = double.Parse(Console.ReadLine());
                                Console.WriteLine("Iloczyn wynosi: {0}", r1 * r2);
                                Thread.Sleep(2500);
                                break;

                            default:
                                Console.WriteLine("Nie ma takiej opcji! Wybierz jeszcze raz.");
                                Thread.Sleep(2000);
                                break;
                        }

                        break;

                    //########################################  DZIELENIE  ###################################################
                    case 5:

                        Console.WriteLine("Dzielimy liczby całkowite - c, czy rzeczywiste - r? ");
                        cr = char.Parse(Console.ReadLine());

                        switch (cr)
                        {
                            case 'c':
                                Console.WriteLine("To podaj proszę liczby całkowite, które chcesz podzielić: \n");
                                Console.Write("Liczba 1: ");
                                int l7 = int.Parse(Console.ReadLine());
                                Console.Write("Liczba 2: ");
                                int l8 = int.Parse(Console.ReadLine());
                                liczba1 = new Calkowite(l7);
                                liczba2 = new Calkowite(l8);

                                if (l8 != 0)
                                {
                                    wynik = liczba1 / liczba2;
                                    wynik.view();
                                    Thread.Sleep(2500);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Nie dzielimy przez 0!");
                                    Thread.Sleep(3000);
                                    break;
                                }

                            case 'r':
                                Console.WriteLine("To podaj proszę liczby rzeczywiste, które chcesz podzielić: \n");
                                Console.Write("Liczba 1: ");
                                double r1 = double.Parse(Console.ReadLine());
                                Console.Write("Liczba 2: ");
                                double r2 = double.Parse(Console.ReadLine());

                                if (r2 != 0)
                                    Console.WriteLine("Iloraz wynosi: {0}", r1 / r2);
                                else
                                    Console.WriteLine("Nie dzielimy przez 0!");
                                Thread.Sleep(2500);
                                break;

                            default:
                                Console.WriteLine("Nie ma takiej opcji! Wybierz jeszcze raz.");
                                Thread.Sleep(2000);
                                break;
                        }

                        break;

                    //#########################################  POTĘGOWANIE  ##################################################
                    case 6:
                        Console.WriteLine("To podaj proszę liczbę, którą chcesz podnieść do potęgi " +
                            "\n(odpowiednio podstawę i jej wykładnik): ");
                        Console.Write("Podstawa: ");
                        double l9 = double.Parse(Console.ReadLine());
                        Console.Write("Wykładnik: ");
                        double l10 = double.Parse(Console.ReadLine());

                        if (l9 == 0 && l10 == 0)
                        {
                            Console.WriteLine("To jest znak nieoznaczony! Matematycy się troszkę przy tym spierali (:");
                        }
                        else
                        {
                            double wyn = Math.Pow(l9, l10);
                            Console.WriteLine("Wynik potęgowania to: " + wyn);
                        }

                        Thread.Sleep(2500);
                        break;

                    //#########################################  LOGARYTMOWANIE  ##################################################
                    case 7:
                        Console.WriteLine("Podaj proszę liczbę, która będzie logarytmowana oraz jej stopień: \n");
                        Console.Write("Liczba: ");
                        double l = double.Parse(Console.ReadLine());
                        Console.Write("Stopień: ");
                        double stopien = double.Parse(Console.ReadLine());
                        Console.WriteLine("Wartość logarytmu dla podanej liczby to: {0}", Math.Log(l, stopien));

                        Thread.Sleep(2500);
                        break;

                    //#########################################  PIERWIASTKOWANIE  ##################################################
                    case 8:
                        Console.WriteLine("To podaj proszę liczbę, którą chcesz spierwiastkować: \n");
                        Console.Write("Liczba: ");
                        double l11 = double.Parse(Console.ReadLine());
                        double wynP = Math.Round(Math.Sqrt(l11), 3);

                        Console.WriteLine("Wynik pierwiastkowania to: " + wynP + "\n");

                        Thread.Sleep(2500);
                        break;

                    //#########################################  PIERWIASTKOWANIE ZAAWANSOWANE  ######################################
                    case 9:
                        Console.WriteLine("To podaj proszę liczbę, którą chcesz spierwiastkować i jego stopień: \n");
                        Console.Write("Liczba: ");
                        double l17 = double.Parse(Console.ReadLine());
                        Console.Write("Stopień: ");
                        double st = double.Parse(Console.ReadLine());
                        double wynPZ = Math.Round(Math.Pow(l17, (1d / st)), 3);

                        Console.WriteLine("Wynik pierwiastkowania to: " + wynPZ + "\n");

                        Thread.Sleep(2500);
                        break;


                    //#########################################  OBLICZANIE CAŁEK  ################################################
                    case 10:
                       
                        Console.WriteLine("To pora na całki! Metody ich rozwiązywania, jakie są dostępne to:");
                        menu_calki();
                        Console.WriteLine("\nMetody te pozwalają na otrzymanie wyników w różnych stopniach dokładności. ");

                        char calki = 'c';
                        double a; double g; double h;
                        double suma, wynikP = 0;
                        double f;

                        while (calki != 'w')
                        {
                            Console.WriteLine("Którą metodę wybierasz?");
                            calki = char.Parse(Console.ReadLine());

                            switch (calki)
                            {
                                //----------Prostokątów
                                case 'p':
                                    Console.WriteLine("Zacznijmy więc od tego, jaką funkcję chcesz całkować? ");
                                    f = double.Parse(Console.ReadLine());
                                    Console.WriteLine("To teraz podaj przedziały całkowania: ");
                                    Console.Write("\na - początek: ");
                                    a = double.Parse(Console.ReadLine());
                                    Console.Write("\ng- koniec: ");
                                    g = double.Parse(Console.ReadLine());
                                    Console.WriteLine("Podaj jeszcze krok, jaki funkcja będzie przemierzała przez algorytm\n" +
                                    "   (decyduje on o dokładności rozwiązania)\n");
                                    Console.Write("h: ");
                                    h = double.Parse(Console.ReadLine());

                                    suma = (g - a) / h;

                                    for (int i = 1; i < h; i++)
                                    {
                                        wynikP = wynikP + funkcjaS(a + i * suma);
                                    }
                                    wynikP = wynikP * suma;

                                    Console.WriteLine("Wartość całki oznaczonej w przedziałach " + a + " - " + g + " wynosi: " + wynikP + "\n");
                                    Thread.Sleep(3000);
                                    break;

                                    //------------ Trapezów 
                                case 't':
                                    Console.WriteLine("Zacznijmy więc od tego, jaką funkcję chcesz całkować? ");
                                    f = double.Parse(Console.ReadLine());
                                    Console.WriteLine("To teraz podaj przedziały całkowania: ");
                                    Console.Write("\na - początek: ");
                                    a = double.Parse(Console.ReadLine());
                                    Console.Write("\ng - koniec: ");
                                    g = double.Parse(Console.ReadLine());
                                    Console.WriteLine("Podaj jeszcze krok, jaki funkcja będzie przemierzała przez algorytm\n" +
                                    "   (decyduje on o dokładności rozwiązania)\n");
                                    Console.Write("h: ");
                                    h = double.Parse(Console.ReadLine());

                                    suma = (g - a) / h;

                                    for (int i = 1; i < h; i++)
                                    {
                                        wynikP = wynikP + funkcjaS(a + i * suma);
                                    }
                                    wynikP = wynikP + (funkcjaS(a) + funkcjaS(g)) / 2;
                                    wynikP = wynikP * suma;

                                    Console.WriteLine("Wartość całki oznaczonej w przedziałach " + a + " - " + g + " wynosi: " + wynikP + "\n");
                                    Thread.Sleep(3000);
                                    break;
                                    

                                case 's':
                                    Console.WriteLine("Zacznijmy więc od tego, jaką funkcję chcesz całkować? ");
                                    f = double.Parse(Console.ReadLine());
                                    Console.WriteLine("To teraz podaj przedziały całkowania: ");
                                    Console.Write("\na - początek: ");
                                    a = double.Parse(Console.ReadLine());
                                    Console.Write("\ng - koniec: ");
                                    g = double.Parse(Console.ReadLine());
                                    Console.WriteLine("Podaj jeszcze krok, jaki funkcja będzie przemierzała przez algorytm\n" +
                                    "   (decyduje on o dokładności rozwiązania)\n");
                                    Console.Write("h: ");
                                    h = double.Parse(Console.ReadLine());

                                    suma = (g - a) / h;
                                    double w = 0;
                                    double x = 0;
                                    for (int i = 1; i < h; i++)
                                    {
                                        x = a + i * suma;
                                        w = w + funkcjaS(x - suma / 2);
                                        wynikP = wynikP + funkcjaS(x);
                                    }
                                    w = w + funkcjaS(g - suma / 2);
                                    wynikP = (suma / 6) * (funkcjaS(a) + funkcjaS(g) + (2 * wynikP) + 4 * suma);

                                    Console.WriteLine("Wartość całki oznaczonej w przedziałach " + a + " - " + g + " wynosi: " + wynikP + "\n");
                                    Thread.Sleep(3000);
                                    break;                                   

                                case 'w':
                                    Console.WriteLine("No to chodźmy do innych zadań!\n");
                                    break;

                                default:
                                    Console.WriteLine("Nie ma takiej opcji! Wybierz jeszcze raz\n");
                                    break;

                            }


                        }

                        break;
           
                    //############################################  FUNKCJE TRYGONOMETRYCZNE  ############################################
                    case 11:

                        Console.WriteLine("Funkcje trygonometryczne, dla których możemy wyliczyć wartość to: ");
                        menu_tryg();
                       
                        char tryg = 'a';

                        while(tryg != 'w')
                        {
                            Console.WriteLine("To którą opcję wybierasz?");
                            tryg = char.Parse(Console.ReadLine());

                            switch (tryg)
                            {
                                case 'a':
                                    Console.WriteLine("Podaj jeszcze kąt w zakresie od 0 do 360, dla którego chcesz poznać wartość: ");
                                    Console.Write("Kąt : ");
                                    int kat = int.Parse(Console.ReadLine());

                                    double s = Math.Sin(kat);
                                    Console.WriteLine("Sinus dla kąta " + kat + " wynosi: " + s + "\n");
                                    Thread.Sleep(4000);
                                    break;

                                case 'b':
                                    Console.WriteLine("Podaj jeszcze kąt w zakresie od 0 do 360, dla którego chcesz poznać wartość: ");
                                    Console.Write("Kąt : ");
                                    kat = int.Parse(Console.ReadLine());

                                    double c = Math.Cos(kat);
                                    Console.WriteLine("Cosinus dla kąta " + kat + " wynosi: " + c + "\n");
                                    Thread.Sleep(4000);
                                    break;

                                case 'c':
                                    Console.WriteLine("Podaj jeszcze kąt w zakresie od 0 do 360, dla którego chcesz poznać wartość: ");
                                    Console.Write("Kąt : ");
                                    kat = int.Parse(Console.ReadLine());

                                    double t = Math.Tan(kat);
                                    Console.WriteLine("Tangens dla kąta " + kat + " wynosi: " + t + "\n");
                                    Thread.Sleep(2500);
                                    break;

                                case 'd':
                                    Console.WriteLine("Podaj jeszcze kąt w zakresie od 0 do 360, dla którego chcesz poznać wartość: ");
                                    Console.Write("Kąt : ");
                                    kat = int.Parse(Console.ReadLine());

                                    double ct = 1 / Math.Tan(kat);
                                    Console.WriteLine("Cotangens dla kąta " + kat + " wynosi: " + ct + "\n");
                                    Thread.Sleep(2500);
                                    break;

                                case 'e':
                                    Console.WriteLine("Podaj jeszcze kąt w zakresie od 0 do 360, dla którego chcesz poznać wartość: ");
                                    Console.Write("Kąt : ");
                                    kat = int.Parse(Console.ReadLine());

                                    double asi = Math.Asin(kat);
                                    Console.WriteLine("Arcus Sinus dla kąta " + kat + " wynosi: " + asi + "\n");
                                    Thread.Sleep(2500);
                                    break;

                                case 'f':
                                    Console.WriteLine("Podaj jeszcze kąt w zakresie od 0 do 360, dla którego chcesz poznać wartość: ");
                                    Console.Write("Kąt : ");
                                    kat = int.Parse(Console.ReadLine());

                                    double aco = Math.Acos(kat);
                                    Console.WriteLine("Arcus Sinus dla kąta " + kat + " wynosi: " + aco + "\n");
                                    Thread.Sleep(2500);
                                    break;

                                case 'g':
                                    Console.WriteLine("Podaj jeszcze kąt w zakresie od 0 do 360, dla którego chcesz poznać wartość: ");
                                    Console.Write("Kąt : ");
                                    kat = int.Parse(Console.ReadLine());

                                    double ata = Math.Atan(kat);
                                    Console.WriteLine("Arcus Sinus dla kąta " + kat + " wynosi: " + ata + "\n");
                                    Thread.Sleep(2500);
                                    break;

                                case 'h':
                                    Console.WriteLine("Podaj jeszcze kąt w zakresie od 0 do 360, dla którego chcesz poznać wartość: ");
                                    Console.Write("Kąt : ");
                                    kat = int.Parse(Console.ReadLine());

                                    double act = 1 / Math.Atan(kat);
                                    Console.WriteLine("Arcus Sinus dla kąta " + kat + " wynosi: " + act + "\n");
                                    Thread.Sleep(2500);
                                    break;

                                case 'w':
                                    Console.WriteLine("No to chodźmy do innych zadań!\n");
                                    break;

                                default:
                                    Console.WriteLine("Nie ma takiej opcji! Wybierz jeszcze raz.\n");
                                    Thread.Sleep(2000);
                                    break;
                            }
                        }

                        break;

                    //############################################  WYJŚCIE  ###############################################
                    case 0:

                        Console.WriteLine("Do zobaczenia! Pomyślnych liczb (:");
                        Environment.Exit(-1);
                        break;

                    //############################################  W INNYM WYPADKU  ###############################################
                    default:

                        Console.WriteLine("Nie ma takiej opcji! Wybierz proszę jeszcze raz.\n");
                        Thread.Sleep(2000);
                        break;

                }

            }

            Console.ReadKey();
        }
    }
}
