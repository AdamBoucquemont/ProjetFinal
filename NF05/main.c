#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/** \brief fonction pour sortir des nombre aléatoire pour répartir les patients dans les circuits.
 * \fn int my_rand (void)
 * \return numéro
 */

int my_rand (void)
{
   static int first = 0;

   if (first == 0)
   {
  	srand (time (NULL));
  	first = 1;
   }
   return (rand ());
}

/** \brief fonction pour vérifier que les heures, jours, mois et années respectent les règles de 60, 24, ~30, 12.
 * \fn void verification(int *minute, int *heure, int *jour, int *mois, int *annee)
 * \param *minute pointeur vers les minutes à vérifier
 * \param *heure pointeur vers les heures à vérifier
 * \param *jour pointeur vers les jours à vérifier
 * \param *mois pointeur vers les mois à vérifier
 * \param *annee pointeur vers les années à vérifier
 */

void verification(int *minute, int *heure, int *jour, int *mois, int *annee)
{


while (*minute>=60)
{
    	*minute=*minute-60;
    	*heure=*heure+1;
}

while (*heure>=24)
{
    	*heure=*heure-24;
    	*jour=*jour+1;
}

if (*jour>28)
{
   if ((*mois==1)||(*mois==3)||(*mois==5)||(*mois==7)||(*mois==8)||(*mois==10)||(*mois==12))
{
    while (*jour>31)
    {
        *jour=*jour-31;
        *mois=*mois+1;
    }
}

if ((*mois==4)||(*mois==6)||(*mois==9)||(*mois==11))
{
    while (*jour>30)
    {
        *jour=*jour-30;
        *mois=*mois+1;
    }
}

if (*mois==2)
{
    if (((*annee%4)==0 && (*annee%100)!=0) || ((*annee%400)==0))
    {
        while (*jour>29)
        {
            *jour=*jour-29;
            *mois=*mois+1;
        }
    }
    else
    {
        while (*jour>28)
        {
            *jour=*jour-28;
            *mois=*mois+1;
        }
    }
}
}



while (*mois>=13)
{
    	*mois=*mois-12;
    	*annee=*annee+1;
}

}

/** \brief comparaison de l'heure de sortie entre la salle d'examen 4 et 5 pour savoir laquelle est libérée en premier
 * \fn void comparaison2(int *minute, int *heure, int *jour, int *mois, int *annee, int *minute2, int *heure2, int *jour2, int *mois2, int *annee2, int *verif)
 * \param *minute pointeur vers les minutes du premier patient à vérifier
 * \param *heure pointeur vers les heures du premier patient à vérifier
 * \param *jour pointeur vers les jours du premier patient à vérifier
 * \param *mois pointeur vers les mois du premier patient à vérifier
 * \param *annee pointeur vers les années du premier patient à vérifier
 * \param *minute2 pointeur vers les minutes du deuxième patient à vérifier
 * \param *heure2 pointeur vers les heures du deuxième patient à vérifier
 * \param *jour2 pointeur vers les jours du deuxième patient à vérifier
 * \param *mois2 pointeur vers les mois du deuxième patient à vérifier
 * \param *annee2 pointeur vers les années du deuxième patient à vérifier
 * \param *vérif pointeur vers la valeur de vérif
 * \return
 */

void comparaison2(int *minute, int *heure, int *jour, int *mois, int *annee, int *minute2, int *heure2, int *jour2, int *mois2, int *annee2, int *verif)
{
	if (*annee!=*annee2)
	{
    	if (*annee<*annee2)
        	*verif=1;
    	else
        	*verif=2;
	}
	else if (*mois!=*mois2)
	{
    	if (*mois<*mois2)
        	*verif=1;
    	else
        	*verif=2;
	}
	else if (*jour!=*jour2)
	{
    	if (*jour<*jour2)
        	*verif=1;
    	else
        	*verif=2;
	}
	else if (*heure!=*heure2)
	{
    	if (*heure<*heure2)
        	*verif=1;
    	else
        	*verif=2;
	}
	else if (*minute!=*minute2)
	{
    	if (*minute<*minute2)
        	*verif=1;
    	else
        	*verif=2;
	}
	else if (*minute=*minute2)
    	*verif=1;
}

/** \brief comparaison de l'heure de sortie entre les salles d'examen 1, 2 et 3 pour savoir laquelle est libérée en premier
 * \fn void comparaison2(int *minute, int *heure, int *jour, int *mois, int *annee, int *minute2, int *heure2, int *jour2, int *mois2, int *annee2, int *minute3, int *heure3, int *jour3, int *mois3, int *annee3, int *verif)
 * \param *minute pointeur vers les minutes du premier patient à vérifier
 * \param *heure pointeur vers les heures du premier patient à vérifier
 * \param *jour pointeur vers les jours du premier patient à vérifier
 * \param *mois pointeur vers les mois du premier patient à vérifier
 * \param *annee pointeur vers les années du premier patient à vérifier
 * \param *minute2 pointeur vers les minutes du deuxième patient à vérifier
 * \param *heure2 pointeur vers les heures du deuxième patient à vérifier
 * \param *jour2 pointeur vers les jours du deuxième patient à vérifier
 * \param *mois2 pointeur vers les mois du deuxième patient à vérifier
 * \param *annee2 pointeur vers les années du deuxième patient à vérifier
 * \param *minute3 pointeur vers les minutes du troisième patient à vérifier
 * \param *heure3 pointeur vers les heures du troisième patient à vérifier
 * \param *jour3 pointeur vers les jours du troisième patient à vérifier
 * \param *mois3 pointeur vers les mois du troisième patient à vérifier
 * \param *annee3 pointeur vers les années du troisième patient à vérifier
 * \param *vérif pointeur vers la valeur de vérif
 * \return
 */

void comparaison3(int *minute, int *heure, int *jour, int *mois, int *annee, int *minute2, int *heure2, int *jour2, int *mois2, int *annee2, int *minute3, int *heure3, int *jour3, int *mois3, int *annee3, int *verif)
{
	/**< Comparaison entre fin d'examen n°1 et n°2 */
	if (*annee!=*annee2)
	{
    	if (*annee<*annee2)
        	*verif=1;
    	else
        	*verif=2;
	}
	else if (*mois!=*mois2)
	{
    	if (*mois<*mois2)
        	*verif=1;
    	else
        	*verif=2;
	}
	else if (*jour!=*jour2)
	{
    	if (*jour<*jour2)
        	*verif=1;
    	else
        	*verif=2;
	}
	else if (*heure!=*heure2)
	{
    	if (*heure<*heure2)
        	*verif=1;
    	else
        	*verif=2;
	}
	else if (*minute!=*minute2)
	{
    	if (*minute<*minute2)
        	*verif=1;
    	else
        	*verif=2;
	}
	else if (*minute=*minute2)
    	*verif=1;

    /**< Si exam1 finit en premier, comparaison entre fin d'examen n°1 et n°3 */
    if (*verif==1)
    {
        if (*annee!=*annee3)
	{
    	if (*annee<*annee3)
        	*verif=1;
    	else
        	*verif=3;
	}
	else if (*mois!=*mois3)
	{
    	if (*mois<*mois3)
        	*verif=1;
    	else
        	*verif=3;
	}
	else if (*jour!=*jour3)
	{
    	if (*jour<*jour3)
        	*verif=1;
    	else
        	*verif=3;
	}
	else if (*heure!=*heure3)
	{
    	if (*heure<*heure3)
        	*verif=1;
    	else
        	*verif=3;
	}
	else if (*minute!=*minute3)
	{
    	if (*minute<*minute3)
        	*verif=1;
    	else
        	*verif=3;
	}
	else if (*minute=*minute3)
    	*verif=1;
    }

    /**< Si exam2 finit en premier, comparaison entre fin d'exam n°2 et n°3 */
    else
    {
        if (*annee3!=*annee2)
	{
    	if (*annee3<*annee2)
        	*verif=3;
    	else
        	*verif=2;
	}
	else if (*mois3!=*mois2)
	{
    	if (*mois3<*mois2)
        	*verif=3;
    	else
        	*verif=2;
	}
	else if (*jour3!=*jour2)
	{
    	if (*jour3<*jour2)
        	*verif=3;
    	else
        	*verif=2;
	}
	else if (*heure3!=*heure2)
	{
    	if (*heure3<*heure2)
        	*verif=3;
    	else
        	*verif=2;
	}
	else if (*minute3!=*minute2)
	{
    	if (*minute3<*minute2)
        	*verif=3;
    	else
        	*verif=2;
	}
	else if (*minute3=*minute2)
    	*verif=2;
    }
}

/** \brief Programme principal, il contient toute la simulation.
 * \fn int main (void)
 * \return EXIT_SUCCESS - Arrêt normal du programme.
 *
 */

void main()
{
    int n=1; /**< n correspond au nombre de patients */
    int i; /**< i sert pour les boucles */

    /**< Les variables suivantes permettent de copier/coller et déplacer les valeurs des horraires des patients */


    int heure, minute, jour, mois, annee;
    int heure2, minute2, jour2, mois2, annee2;
    int heure3, minute3, jour3, mois3, annee3;

    double temps1, temps2, temps3, temps4, temps5;


    int verif=0; /**< verif permet de savoir quel box d'examen est libre */

    /**< Les variables suivantes permettent de compter le nombre de patient qui vont dans un circuit précis */
    int n1=0;
    int n2=0;
    int n3=0;
    int n4=0;
    int n5=0;

    /**< Les variables suivantes correspondent au temps d'attente moyen dans chaque salle d'attente */
    float moyenne_salle1=0;
    float moyenne_salle2=0;
    float moyenne_salle3=0;
    float moyenne_salle4=0;
    float moyenne_salle6=0;

    /**< Les pointeurs suivants vont permettre de faire un tableau dynamique pour les horraires de sortie de l'enregistrement */
    int *heure_enregistrement=NULL;
    int *minute_enregistrement=NULL;
    int *jour_enregistrement=NULL;
    int *mois_enregistrement=NULL;
    int *annee_enregistrement=NULL;

    /**< Les pointeurs suivants vont permettre de faire un tableau dynamique pour les horraires de sortie de l'examen IOA */
    int *heure_IOA=NULL;
    int *minute_IOA=NULL;
    int *jour_IOA=NULL;
    int *mois_IOA=NULL;
    int *annee_IOA=NULL;

    /**< Les pointeurs suivants vont permettre de faire un tableau dynamique pour les horraires de sortie de l'examen en circuit court ou long */
    int *heure_exam=NULL;
    int *minute_exam=NULL;
    int *jour_exam=NULL;
    int *mois_exam=NULL;
    int *annee_exam=NULL;

    /**< Les pointeurs suivants vont permettre de faire un tableau dynamique pour les horraires de sortie de l'examen complémentaire */
    int *heure_exam_comp=NULL;
    int *minute_exam_comp=NULL;
    int *jour_exam_comp=NULL;
    int *mois_exam_comp=NULL;
    int *annee_exam_comp=NULL;

    /**< Les variables suivantes correspondent au numéro du premier patient dans le circuit court et dans le cicuit long */
    int premier_court;
	int premier_long;

    /**< Les pointeurs suivants vont permettre de créer un tableau dynamique pour stocker le numéro des patients qui vont en cicuit court et ceux qui vont en circuit long */
    int *ccourt=NULL;
    int *clong=NULL;

    /**< Les pointeurs suivants vont permettre de créer un tableau dynamique pour stocker le numéro des patients qui sortent du circuit long et ceux qui font un examen complémentaire */
    int *clongc=NULL;
    int *clongl=NULL;

    /**< Les variables suivantes vont être utilisé pour calculer la moyenne de temps d'attente */
    int heure_arrivee, heure_passage, minute_arrivee, minute_passage, diff_heure;

/** \brief Structure qui rassemble toues les informations sur les patients.
 * \struct s_patient
 */
    typedef struct s_patient
{
    int tab_date[3];
    int heure;
    int minute;
    char nom[20];
    int enregistrement;
    int IOA;
    int exam;
    int exam_comp;
}                   t_patient;

    t_patient *patient_T;

    /**< Dans cette partie on va ouvrir le fichier texte et rentrer les information qui sont dessus dans la structure s_patient */
    FILE *ptr;

    char name[20]={'s', 'i', 'm', 'u', 'l', 'a', 't', 'i', 'o', 'n', '.', 't', 'x', 't'};
    char lecteur='a';
    ptr=fopen(name, "r"); /**< Appel du fichier texte en mode lecture */


    while ((lecteur=fgetc(ptr)) != EOF)
    {
        if (lecteur=='\n')
        {
            n++;                        /**< Calcul du nombre de patient */
        }
    }
    printf("il y a %d patients \n", n);

    patient_T = (t_patient*)malloc(sizeof(t_patient)*n); /**< Régulation de la taille du tableau de structure s_patient en fonction du nombre de patient */
    if (!patient_T)
        return (0);

    fclose(ptr); /**< Fermeture du fichier texte */

    /**< Dans cette partie on va réouvrir le fichier texte pour copier toutes les informations du fichier dans les structures pour chaque patient */
    FILE *fic;

    char lecteur2;
    int i_2, i_3=0, i_4; char poubelle;
    fic=fopen(name, "r"); /**< Ouverture fichier */

    for(i=0;i<n;i++)
    {
        for(i_2=0;i_2<3;i_2++) /**< Enregistrement de la date (jour/mois/année) */
        {
            fscanf(fic, "%d", &patient_T[i].tab_date[i_2]);
            printf("%d/", patient_T[i].tab_date[i_2]);
        }

        fscanf(fic, "%c", &poubelle); /**< Suppression du tiret */
        printf("\n");
        fscanf(fic, "%c", &lecteur2);

    while ((lecteur2!='-') && (i_3<20)) /**< Enregistrement du nom du patient */
    {
        	patient_T[i].nom[i_3]=lecteur2;
        	printf("%c", patient_T[i].nom[i_3]);
        	i_3++;
        	fscanf(fic, "%c", &lecteur2);
    }

    while (lecteur2!='-')
    {
        	fscanf(fic, "%c", &lecteur2); /**< Suppression du tiret */
    }

    i_3=0;
    printf("\n");

    while(lecteur2!='h')
    	{
        	fscanf(fic, "%d", &patient_T[i].heure); /**< Enregistrement de l'heure d'arrivée du patient */
        	printf("%dh", patient_T[i].heure);
        	fscanf(fic, "%c", &lecteur2);
    	}

    fscanf(fic, "%d", &patient_T[i].minute); /**< Enregistrement des minutes d'arrivée du patient */
    printf("%d", patient_T[i].minute);
    printf("\n");

        fscanf(fic, "%d", &patient_T[i].enregistrement); /**< Enregistrement du temps d'enregistrement du patient */
        printf("%d-", patient_T[i].enregistrement);
        fscanf(fic, "%d", &patient_T[i].IOA); /**< Enregistrement du temps d'examen IOA du patient */
        printf("%d-", patient_T[i].IOA);
        fscanf(fic, "%d", &patient_T[i].exam); /**< Enregistrement du temps d'examen du patient */
        printf("%d-", patient_T[i].exam);
        fscanf(fic, "%d", &patient_T[i].exam_comp); /**< Enregistrement du temps d'examen complémentaire du patient */
        printf("%d\n\n", patient_T[i].exam_comp);


    }
    fclose(fic); /**< Fermeture fichier */

    temps1= (double) clock()/CLOCKS_PER_SEC;
    printf("Le programme met %f secondes pour la partie enregistrement \n", temps1);


    heure_enregistrement=malloc(sizeof(int) * n);
    minute_enregistrement=malloc(sizeof(int) * n);
    jour_enregistrement=malloc(sizeof(int) * n);            /**< Création de tableaux dynamiques des horraires de sortie d'enregistrement des patients */
    mois_enregistrement=malloc(sizeof(int) * n);
    annee_enregistrement=malloc(sizeof(int) * n);


    heure=patient_T[0].heure;
    minute=patient_T[0].minute;
    jour=patient_T[0].tab_date[0];
    mois=patient_T[0].tab_date[1];
    annee=patient_T[0].tab_date[2];


    for (i=0;i<n;i++) /**< Cette boucle va permettre de faire se succéder les patient pour l'enregistrement en faisant attention à ce que l'enregistrement soit libre avant qu'un autre patient puisse y entrer */
    {
        if (annee<patient_T[i].tab_date[2])
        {
            annee=patient_T[i].tab_date[2];
            mois=patient_T[i].tab_date[1];
            jour=patient_T[i].tab_date[0];
            heure=patient_T[i].heure;
            minute=patient_T[i].minute;
        }
        else if (mois<patient_T[i].tab_date[1])
        {
            mois=patient_T[i].tab_date[1];
            jour=patient_T[i].tab_date[0];
            heure=patient_T[i].heure;
            minute=patient_T[i].minute;
        }
            else if (jour<patient_T[i].tab_date[0])
            {
                jour=patient_T[i].tab_date[0];
                heure=patient_T[i].heure;
                minute=patient_T[i].minute;
            }
                else if (heure<patient_T[i].heure)
                {
                    heure=patient_T[i].heure;
                    minute=patient_T[i].minute;
                }
                    else if (heure==patient_T[i].heure)
                    {
                        if (minute<patient_T[i].minute)
                        {
                            minute=patient_T[i].minute;
                        }
                    }



        verification (&minute, &heure, &jour, &mois, &annee);

        printf("le patient %d entre a l'enregistrement a %dh%d \n", i+1, heure, minute);

        /**< Calcul de la moyenne du temps d'attente de la salle d'attente 1 */
        heure_arrivee=patient_T[i].heure;  minute_arrivee=patient_T[i].minute;
        heure_passage=heure; minute_passage=minute;
        diff_heure=heure_passage-heure_arrivee;
        if (diff_heure>0)
        {
            minute_passage=minute_passage+diff_heure*60;
            moyenne_salle1=moyenne_salle1+(minute_passage-minute_arrivee);
        }
        else
        {
            moyenne_salle1=moyenne_salle1+(minute_passage-minute_arrivee);
        }
        /**< Fin calcul moyenne */

        minute=minute+patient_T[i].enregistrement;
        printf("patient %d temps d'enregistrement : %d \n", i+1, patient_T[i].enregistrement );

        verification (&minute, &heure, &jour, &mois, &annee);

        printf("Le patient %d sort de l'enregistrement a %dh%d \n", i+1, heure, minute);

        heure_enregistrement[i]=heure;
        minute_enregistrement[i]=minute;
        jour_enregistrement[i]=jour;        /**< Enregistrement des horrires de sortie de l'enregistrement de chaque patient */
        mois_enregistrement[i]=mois;
        annee_enregistrement[i]=annee;

    }

    moyenne_salle1=moyenne_salle1/n;
    printf("\n Le temps moyen passe dans la salle d'attente numero 1 est de %f minutes \n", moyenne_salle1);

	temps2= (double) clock()/CLOCKS_PER_SEC -temps1;
    printf("Le programme met %f secondes pour la partie enregistrement \n", temps2);



    heure_IOA=malloc(sizeof(int) * n);
    minute_IOA=malloc(sizeof(int) * n);
    jour_IOA=malloc(sizeof(int) * n);       /**< Création de tableaux dynamiques des horraires de sortie d'examen IOA des patients */
    mois_IOA=malloc(sizeof(int) * n);
    annee_IOA=malloc(sizeof(int) * n);

    heure=heure_enregistrement[0];
    minute=minute_enregistrement[0];
    jour=jour_enregistrement[0];
    mois=mois_enregistrement[0];
    annee=annee_enregistrement[0];

    printf("\n");

    for (i=0;i<n;i++) /**< Affichage de l'historique des horraires de sortie de l'enregistrement */
    {
    	printf("le patient numero %d est sorti de l'enregistrement a %dh%d le %d %d %d \n", i+1, heure_enregistrement[i], minute_enregistrement[i], jour_enregistrement[i], mois_enregistrement[i], annee_enregistrement[i]);
    }

    printf("\n");

    for (i=0;i<n;i++) /**< Cette boucle va permettre de faire se succéder les patient pour l'examen IOA en faisant attention à ce que la salle d'examen IOA soit libre avant qu'un autre patient puisse y entrer */
    {
        if (annee<annee_enregistrement[i])
        {
        	annee=annee_enregistrement[i];
        	mois=mois_enregistrement[i];
        	jour=jour_enregistrement[i];
        	heure=heure_enregistrement[i];
        	minute=minute_enregistrement[i];
        }
        else if (mois<mois_enregistrement[i])
        {
        	mois=mois_enregistrement[i];
        	jour=jour_enregistrement[i];
        	heure=heure_enregistrement[i];
        	minute=minute_enregistrement[i];
        }
        else if (jour<jour_enregistrement[i])
        {
        	jour=jour_enregistrement[i];
        	heure=heure_enregistrement[i];
        	minute=minute_enregistrement[i];
        }
        else if (heure<heure_enregistrement[i])
        {
        	heure=heure_enregistrement[i];
        	minute=minute_enregistrement[i];
        }
        else if (heure==heure_enregistrement[i])
        {
            if (minute<minute_enregistrement[i])
            {
                minute=minute_enregistrement[i];
            }
        }


        verification (&minute, &heure, &jour, &mois, &annee);

        printf("le patient %d entre a l'examen IOA a %dh%d \n", i+1, heure, minute);

        /**< Calcul de la moyenne du temps d'attente de la salle d'attente 2 */
        heure_arrivee=heure_enregistrement[i];  minute_arrivee=minute_enregistrement[i];
        heure_passage=heure; minute_passage=minute;
        diff_heure=heure_passage-heure_arrivee;
        if (diff_heure>0)
        {
            minute_passage=minute_passage+diff_heure*60;
            moyenne_salle2=moyenne_salle2+(minute_passage-minute_arrivee);
        }
        else
        {
            moyenne_salle2=moyenne_salle2+(minute_passage-minute_arrivee);
        }
        /**< Fin calcul moyenne */

        minute=minute+patient_T[i].IOA;
        printf("patient %d temps d'examen IOA : %d \n", i+1, patient_T[i].IOA );

        verification (&minute, &heure, &jour, &mois, &annee);

        printf("Le patient %d sort de l'examen IOA a %dh%d \n", i+1, heure, minute);

        heure_IOA[i]=heure;
        minute_IOA[i]=minute;
        jour_IOA[i]=jour;       /**< Enregistrement des horrires de sortie de l'examen IOA de chaque patient */
        mois_IOA[i]=mois;
        annee_IOA[i]=annee;
    }

    moyenne_salle2=moyenne_salle2/n;
    printf("\n Le temps moyen passa dans la salle d'attente numero 2 est de %f minutes \n", moyenne_salle2);

    printf("\n");

    for (i=0;i<n;i++) /**< Affichage de l'historique des horraires de sortie de l'examen IOA */
    {
    	printf("le patient numero %d est sorti de l'examen IOA a %dh%d le %d %d %d \n", i+1, heure_IOA[i], minute_IOA[i], jour_IOA[i], mois_IOA[i], annee_IOA[i]);
    }

    printf("\n");

    temps3= (double) clock()/CLOCKS_PER_SEC- temps2-temps1;
    printf("Le programme met %f secondes pour la partie IOA \n", temps3);

    ccourt=malloc(sizeof(int) * n); /**< Création du tableau dynamique qui va recueuillir les numéros des patient qui vont en circuit court */
	clong=malloc(sizeof(int) * n); /**< Création du tableau dynamique qui va recueuillir les numéros des patient qui vont en circuit long */

	for (i = 0; i<n; i++) /**< Initialisation à 0 des deux tableux */
	{
    	ccourt[i]=0;
    	clong[i]=0;
	}

	for (i = 0; i<n; i++) /**< Répartition aléatoire des patients dans les circuits court et long */
	{
    	if (my_rand()%10 <4)
    	{
        	printf("Le patient %d va dans le circuit court \n", i+1);
        	ccourt[n1]=i+1;
        	n1=n1+1;
    	}

    	else
    	{
        	printf("Le patient %d va dans le circuit long \n", i+1);
        	clong[n2]=i+1;
        	n2=n2+1;
    	}
	}

	printf("\n");

	heure_exam=malloc(sizeof(int) * n);
	minute_exam=malloc(sizeof(int) * n);
	jour_exam=malloc(sizeof(int) * n);      /**< Création de tableaux dynamiques des horraires de sortie d'examen des patients */
	mois_exam=malloc(sizeof(int) * n);
	annee_exam=malloc(sizeof(int) * n);

	premier_court=ccourt[0];
	premier_long=clong[0];


	if (premier_court!=0) /**< Vérification que le circuit court n'est pas vide et initialisation du premier patient en circuit court */
	{
    	heure=heure_IOA[premier_court-1];
    	minute=minute_IOA[premier_court-1];
    	jour=jour_IOA[premier_court-1];
    	mois=mois_IOA[premier_court-1];
    	annee=annee_IOA[premier_court-1];

    	heure2=heure_IOA[premier_court-1];
    	minute2=minute_IOA[premier_court-1];
    	jour2=jour_IOA[premier_court-1];
    	mois2=mois_IOA[premier_court-1];
    	annee2=annee_IOA[premier_court-1];
	}
	else
    	printf("il n'y a personne dans le circuit court \n");

	for (i = 0; i<n; i++) /**< Affichage de l'historique de la répartition des patients en circuit court et long */
	{
    	printf("court : %d, long : %d \n", ccourt[i], clong[i]);
	}

    printf("\nIl y a %d patients dans le circuit court et %d patients dans le circuit long\n", n1, n2);

	i=0;


/**< ENTREE DU CIRCUIT COURT */


	while (ccourt[i]!=0 && i<=n) /**< Cette boucle fait fonctionner les box d'examen du cicuit court, elle tourne jusqu'à ce qu'elle fasse tous les patients en circuit court */
	{
    	comparaison2 (&minute, &heure, &jour, &mois, &annee, &minute2, &heure2, &jour2, &mois2, &annee2, &verif);
    	if (verif==1) /**< Si le box 4 est libre ou se libère en premier alors le patient suivant prend place dans le box 4 en respectant les horraires */
    	{
        	printf("\nle patient %d est dans le circuit court, salle 1 \n", ccourt[i]);

        	if (annee<annee_IOA[ccourt[i]-1])
        	{
            	annee=annee_IOA[ccourt[i]-1];
            	mois=mois_IOA[ccourt[i]-1];
            	jour=jour_IOA[ccourt[i]-1];
            	heure=heure_IOA[ccourt[i]-1];
            	minute=minute_IOA[ccourt[i]-1];
        	}
        	else if (mois<mois_IOA[ccourt[i]-1])
        	{
            	mois=mois_IOA[ccourt[i]-1];
            	jour=jour_IOA[ccourt[i]-1];
            	heure=heure_IOA[ccourt[i]-1];
            	minute=minute_IOA[ccourt[i]-1];
        	}
        	else if (jour<jour_IOA[ccourt[i]-1])
        	{
            	jour=jour_IOA[ccourt[i]-1];
            	heure=heure_IOA[ccourt[i]-1];
            	minute=minute_IOA[ccourt[i]-1];
        	}
        	else if (heure<heure_IOA[ccourt[i]-1])
        	{
            	heure=heure_IOA[ccourt[i]-1];
            	minute=minute_IOA[ccourt[i]-1];
        	}
        	else if (minute<minute_IOA[ccourt[i]-1])
        	{
            	minute=minute_IOA[ccourt[i]-1];
        	}


        	verification (&minute, &heure, &jour, &mois, &annee);

        	printf("le patient %d entre a l'examen du circuit court a %dh%d \n", ccourt[i], heure, minute);

        	/**< Calcul de la moyenne du temps d'attente dans la salle d'attente 4 */
        	heure_arrivee=heure_IOA[ccourt[i]-1];  minute_arrivee=minute_IOA[ccourt[i]-1];
            heure_passage=heure; minute_passage=minute;
            diff_heure=heure_passage-heure_arrivee;
            if (diff_heure>0)
            {
                minute_passage=minute_passage+diff_heure*60;
                moyenne_salle4=moyenne_salle4+(minute_passage-minute_arrivee);
            }
            else
            {
                moyenne_salle4=moyenne_salle4+(minute_passage-minute_arrivee);
            }
            /**< Fin calcul moyenne */

        	minute=minute+patient_T[ccourt[i]-1].exam;
        	printf("patient %d temps d'examen du circuit court : %d \n", ccourt[i], patient_T[ccourt[i]-1].exam );

        	verification (&minute, &heure, &jour, &mois, &annee);

        	printf("Le patient %d sort de l'examen du circuit court a %dh%d \n", ccourt[i], heure, minute);

        	heure_exam[ccourt[i]-1]=heure;
        	minute_exam[ccourt[i]-1]=minute;
        	jour_exam[ccourt[i]-1]=jour;        /**< Enregistrement des horrires de sortie de l'examen du circuit court de chaque patient */
        	mois_exam[ccourt[i]-1]=mois;
        	annee_exam[ccourt[i]-1]=annee;


    	}
    	else if (verif==2) /**< Si le box 5 est libre ou se libère en premier alors le patient suivant prend place dans le box 5 en respectant les horraires */
     	{
        	printf("le patient %d est dans le circuit court, salle 2 \n", ccourt[i]);

        	if (annee2<annee_IOA[ccourt[i]-1])
        	{
            	annee2=annee_IOA[ccourt[i]-1];
            	mois2=mois_IOA[ccourt[i]-1];
            	jour2=jour_IOA[ccourt[i]-1];
            	heure2=heure_IOA[ccourt[i]-1];
            	minute2=minute_IOA[ccourt[i]-1];
        	}
        	else if (mois2<mois_IOA[ccourt[i]-1])
        	{
            	mois2=mois_IOA[ccourt[i]-1];
            	jour2=jour_IOA[ccourt[i]-1];
            	heure2=heure_IOA[ccourt[i]-1];
            	minute2=minute_IOA[ccourt[i]-1];
        	}
        	else if (jour2<jour_IOA[ccourt[i]-1])
        	{
            	jour2=jour_IOA[ccourt[i]-1];
            	heure2=heure_IOA[ccourt[i]-1];
            	minute2=minute_IOA[ccourt[i]-1];
        	}
        	else if (heure2<heure_IOA[ccourt[i]-1])
        	{
            	heure2=heure_IOA[ccourt[i]-1];
            	minute2=minute_IOA[ccourt[i]-1];
        	}
        	else if (minute2<minute_IOA[ccourt[i]-1])
        	{
            	minute2=minute_IOA[ccourt[i]-1];
        	}


        	verification (&minute2, &heure2, &jour2, &mois2, &annee2);

        	printf("le patient %d entre a l'examen du circuit court a %dh%d \n", ccourt[i], heure2, minute2);

        	/**< Calcul de la moyenne du temps d'attente dans la salle d'attente 4 */
        	heure_arrivee=heure_IOA[ccourt[i]-1];  minute_arrivee=minute_IOA[ccourt[i]-1];
            heure_passage=heure2; minute_passage=minute2;
            diff_heure=heure_passage-heure_arrivee;
            if (diff_heure>0)
            {
                minute_passage=minute_passage+diff_heure*60;
                moyenne_salle4=moyenne_salle4+(minute_passage-minute_arrivee);
            }
            else
            {
                moyenne_salle4=moyenne_salle4+(minute_passage-minute_arrivee);
            }
            /**< Fin calcul moyenne */

        	minute2=minute2+patient_T[ccourt[i]-1].exam;
        	printf("patient %d temps d'examen du circuit court : %d \n", ccourt[i], patient_T[ccourt[i]-1].exam );

        	verification (&minute2, &heure2, &jour2, &mois2, &annee2);

        	printf("Le patient %d sort de l'examen du circuit court a %dh%d \n", ccourt[i], heure2, minute2);

        	heure_exam[ccourt[i]-1]=heure2;
        	minute_exam[ccourt[i]-1]=minute2;
        	jour_exam[ccourt[i]-1]=jour2;       /**< Enregistrement des horrires de sortie de l'examen du circuit court de chaque patient */
        	mois_exam[ccourt[i]-1]=mois2;
        	annee_exam[ccourt[i]-1]=annee2;

    	}
    	i=i+1;
	}

	if (n1!=0)
    {
        moyenne_salle4=moyenne_salle4/n1;
        printf("\nLe temps moyen passe dans la salle d'attente numero 4 est de %f minutes \n", moyenne_salle4);
    }
    else
        printf("Il n'y a personne dans le circuit court");


	printf("\n\n");


/**< ENTREE DU CIRCUIT LONG */


	if (premier_long!=0) /**< Vérification que le circuit long n'est pas vide et initialisation du premier patient en circuit long */
	{
    	heure=heure_IOA[premier_long-1];
    	minute=minute_IOA[premier_long-1];
    	jour=jour_IOA[premier_long-1];
    	mois=mois_IOA[premier_long-1];
    	annee=annee_IOA[premier_long-1];

    	heure2=heure_IOA[premier_long-1];
    	minute2=minute_IOA[premier_long-1];
    	jour2=jour_IOA[premier_long-1];
    	mois2=mois_IOA[premier_long-1];
    	annee2=annee_IOA[premier_long-1];

    	heure3=heure_IOA[premier_long-1];
    	minute3=minute_IOA[premier_long-1];
    	jour3=jour_IOA[premier_long-1];
    	mois3=mois_IOA[premier_long-1];
    	annee3=annee_IOA[premier_long-1];
	}
	else
    	printf("il n'y a personne dans le circuit long \n");

    i=0;

    while (clong[i]!=0 && i<=n) /**< Cette boucle fait fonctionner les box d'examen du cicuit long, elle tourne jusqu'à ce qu'elle fasse tous les patients en circuit long */
	{
    	comparaison3 (&minute, &heure, &jour, &mois, &annee, &minute2, &heure2, &jour2, &mois2, &annee2, &minute3, &heure3, &jour3, &mois3, &annee3, &verif);

    	if (verif==1) /**< Si le box 1 est libre ou se libère en premier alors le patient suivant prend place dans le box 1 en respectant les horraires */
    	{
        	printf("le patient %d est dans le circuit long, salle 1 \n", clong[i]);

        	if (annee<annee_IOA[clong[i]-1])
        	{
            	annee=annee_IOA[clong[i]-1];
            	mois=mois_IOA[clong[i]-1];
            	jour=jour_IOA[clong[i]-1];
            	heure=heure_IOA[clong[i]-1];
            	minute=minute_IOA[clong[i]-1];
        	}
        	else if (mois<mois_IOA[clong[i]-1])
        	{
            	mois=mois_IOA[clong[i]-1];
            	jour=jour_IOA[clong[i]-1];
            	heure=heure_IOA[clong[i]-1];
            	minute=minute_IOA[clong[i]-1];
        	}
        	else if (jour<jour_IOA[clong[i]-1])
        	{
            	jour=jour_IOA[clong[i]-1];
            	heure=heure_IOA[clong[i]-1];
            	minute=minute_IOA[clong[i]-1];
        	}
        	else if (heure<heure_IOA[clong[i]-1])
        	{
            	heure=heure_IOA[clong[i]-1];
            	minute=minute_IOA[clong[i]-1];
        	}
        	else if (minute<minute_IOA[clong[i]-1])
        	{
            	minute=minute_IOA[clong[i]-1];
        	}


        	verification (&minute, &heure, &jour, &mois, &annee);

        	printf("le patient %d entre a l'examen du circuit long a %dh%d \n", clong[i], heure, minute);

        	/**< Calcul de la moyenne du temps d'attente dans la salle d'attente 3 */
        	heure_arrivee=heure_IOA[clong[i]-1];  minute_arrivee=minute_IOA[clong[i]-1];
            heure_passage=heure; minute_passage=minute;
            diff_heure=heure_passage-heure_arrivee;
            if (diff_heure>0)
            {
                minute_passage=minute_passage+diff_heure*60;
                moyenne_salle3=moyenne_salle3+(minute_passage-minute_arrivee);
            }
            else
            {
                moyenne_salle3=moyenne_salle3+(minute_passage-minute_arrivee);
            }
            /**< Fin calcul moyenne */

        	minute=minute+patient_T[clong[i]-1].exam;
        	printf("patient %d temps d'examen du circuit long : %d \n", ccourt[i], patient_T[clong[i]-1].exam );

        	verification (&minute, &heure, &jour, &mois, &annee);

        	printf("Le patient %d sort de l'examen du circuit long a %dh%d \n", clong[i], heure, minute);

        	heure_exam[clong[i]-1]=heure;
        	minute_exam[clong[i]-1]=minute;
        	jour_exam[clong[i]-1]=jour;         /**< Enregistrement des horrires de sortie de l'examen du circuit long de chaque patient */
        	mois_exam[clong[i]-1]=mois;
        	annee_exam[clong[i]-1]=annee;


    	}
    	else if (verif==2) /**< Si le box 2 est libre ou se libère en premier alors le patient suivant prend place dans le box 2 en respectant les horraires */
     	{
        	printf("le patient %d est dans le circuit long, salle 2 \n", clong[i]);

        	if (annee2<annee_IOA[clong[i]-1])
        	{
            	annee2=annee_IOA[clong[i]-1];
            	mois2=mois_IOA[clong[i]-1];
            	jour2=jour_IOA[clong[i]-1];
            	heure2=heure_IOA[clong[i]-1];
            	minute2=minute_IOA[clong[i]-1];
        	}
        	else if (mois2<mois_IOA[clong[i]-1])
        	{
            	mois2=mois_IOA[clong[i]-1];
            	jour2=jour_IOA[clong[i]-1];
            	heure2=heure_IOA[clong[i]-1];
            	minute2=minute_IOA[clong[i]-1];
        	}
        	else if (jour2<jour_IOA[clong[i]-1])
        	{
            	jour2=jour_IOA[clong[i]-1];
            	heure2=heure_IOA[clong[i]-1];
            	minute2=minute_IOA[clong[i]-1];
        	}
        	else if (heure2<heure_IOA[clong[i]-1])
        	{
            	heure2=heure_IOA[clong[i]-1];
            	minute2=minute_IOA[clong[i]-1];
        	}
        	else if (minute2<minute_IOA[clong[i]-1])
        	{
            	minute2=minute_IOA[clong[i]-1];
        	}

        	verification (&minute2, &heure2, &jour2, &mois2, &annee2);

        	printf("le patient %d entre a l'examen du circuit long a %dh%d \n", clong[i], heure2, minute2);

        	/**< Calcul de la moyenne du temps d'attente de la salle d'attente 3 */
            heure_arrivee=heure_IOA[clong[i]-1];  minute_arrivee=minute_IOA[clong[i]-1];
            heure_passage=heure2; minute_passage=minute2;
            diff_heure=heure_passage-heure_arrivee;
            if (diff_heure>0)
            {
                minute_passage=minute_passage+diff_heure*60;
                moyenne_salle3=moyenne_salle3+(minute_passage-minute_arrivee);
            }
            else
            {
                moyenne_salle3=moyenne_salle3+(minute_passage-minute_arrivee);
            }
            /**< Fin calcul moyenne */

        	minute2=minute2+patient_T[clong[i]-1].exam;
        	printf("patient %d temps d'examen du circuit long : %d \n", clong[i], patient_T[clong[i]-1].exam );

        	verification (&minute2, &heure2, &jour2, &mois2, &annee2);

        	printf("Le patient %d sort de l'examen du circuit long a %dh%d \n", clong[i], heure2, minute2);

        	heure_exam[clong[i]-1]=heure2;
        	minute_exam[clong[i]-1]=minute2;
        	jour_exam[clong[i]-1]=jour2;        /**< Enregistrement des horrires de sortie de l'examen du circuit long de chaque patient */
        	mois_exam[clong[i]-1]=mois2;
        	annee_exam[clong[i]-1]=annee2;

    	}
    	else if (verif==3) /**< Si le box 3 est libre ou se libère en premier alors le patient suivant prend place dans le box 3 en respectant les horraires */
     	{
        	printf("le patient %d est dans le circuit long, salle 3 \n", clong[i]);

        	if (annee3<annee_IOA[clong[i]-1])
        	{
            	annee3=annee_IOA[clong[i]-1];
            	mois3=mois_IOA[clong[i]-1];
            	jour3=jour_IOA[clong[i]-1];
            	heure3=heure_IOA[clong[i]-1];
            	minute3=minute_IOA[clong[i]-1];
        	}
        	else if (mois3<mois_IOA[clong[i]-1])
        	{
            	mois3=mois_IOA[clong[i]-1];
            	jour3=jour_IOA[clong[i]-1];
            	heure3=heure_IOA[clong[i]-1];
            	minute3=minute_IOA[clong[i]-1];
        	}
        	else if (jour3<jour_IOA[clong[i]-1])
        	{
            	jour3=jour_IOA[clong[i]-1];
            	heure3=heure_IOA[clong[i]-1];
            	minute3=minute_IOA[clong[i]-1];
        	}
        	else if (heure3<heure_IOA[clong[i]-1])
        	{
            	heure3=heure_IOA[clong[i]-1];
            	minute3=minute_IOA[clong[i]-1];
        	}
        	else if (minute3<minute_IOA[clong[i]-1])
        	{
            	minute3=minute_IOA[clong[i]-1];
        	}

        	verification (&minute3, &heure3, &jour3, &mois3, &annee3);

        	printf("le patient %d entre a l'examen du circuit long a %dh%d \n", clong[i], heure3, minute3);

        	/**< Calcul de la moyenne du temps d'attente de la salle d'attente 3 */
        	heure_arrivee=heure_IOA[clong[i]-1];  minute_arrivee=minute_IOA[clong[i]-1];
            heure_passage=heure3; minute_passage=minute3;
            diff_heure=heure_passage-heure_arrivee;
            if (diff_heure>0)
            {
                minute_passage=minute_passage+diff_heure*60;
                moyenne_salle3=moyenne_salle3+(minute_passage-minute_arrivee);
            }
            else
            {
                moyenne_salle3=moyenne_salle3+(minute_passage-minute_arrivee);
            }
            /**< Fin calcul moyenne */

        	minute3=minute3+patient_T[clong[i]-1].exam;
        	printf("patient %d temps d'examen du circuit long : %d \n", clong[i], patient_T[clong[i]-1].exam );

        	verification (&minute3, &heure3, &jour3, &mois3, &annee3);

        	printf("Le patient %d sort de l'examen du circuit long a %dh%d \n", clong[i], heure3, minute3);

        	heure_exam[clong[i]-1]=heure3;
        	minute_exam[clong[i]-1]=minute3;
        	jour_exam[clong[i]-1]=jour3;        /**< Enregistrement des horriares de sortie de l'examen du circuit long de chaque patient */
        	mois_exam[clong[i]-1]=mois3;
            annee_exam[clong[i]-1]=annee3;

    	}

    	i=i+1;
	}

printf("\n");

	if (n2!=0)
	{
   	moyenne_salle3=moyenne_salle3/n2;
    	printf("\nLe temps moyen passe dans la salle d'attente numero 3 est de %f minutes \n", moyenne_salle3);
	}
	else
    	printf("Il n'y a personne dans le circuit long");



	printf("\n");

	for (i=0; i<n; i++) /**< Affichage de l'historique des horraires de sortie des box d'examen des patients*/
	{
    	printf("patient %d sort de l'examen le %d %d %d a %dh%d \n", i+1, jour_exam[i], mois_exam[i], annee_exam[i], heure_exam[i], minute_exam[i]);
	}

	printf("\n");

    temps4= (double) clock()/CLOCKS_PER_SEC -temps3-temps2-temps1;
    printf("Le programme met %f secondes pour la partie examen \n", temps4);

	heure_exam_comp=malloc(sizeof(int) * n);
	minute_exam_comp=malloc(sizeof(int) * n);
	jour_exam_comp=malloc(sizeof(int) * n);     /**< Création de tableaux dynamiques des horraires de sortie d'examen complémentaire des patients */
	mois_exam_comp=malloc(sizeof(int) * n);
	annee_exam_comp=malloc(sizeof(int) * n);

	clongc=malloc(sizeof(int) * n); /**< Création du tableau dynamique qui va recueuillir les numéros des patient qui sorte du circuit long */
	clongl=malloc(sizeof(int) * n); /**< Création du tableau dynamique qui va recueuillir les numéros des patient qui vont en examen complémentaire */

	for (i = 0; i<n; i++) /**< Initialisation des tableaux à 0 */
	{
    	clongc[i]=0;
    	clongl[i]=0;
	}

	i=0;


	while ((clong[i]!=0)&&(i<=n2)) /**< Répartition aléatoire des patients entre la sortie et l'examen complémentaire */
	{
    	if (my_rand()%10 <8)
    	{
        	printf("Le patient %d va dans les examens complementaires \n", clong[i]);
        	clongl[n3]=clong[i];
        	n3=n3+1;
    	}

    	else
    	{
        	printf("Le patient %d sort de l'hopitale \n", clong[i]);
        	clongc[n4]=clong[i];
        	n4=n4+1;
    	}
    	i=i+1;
	}

	printf("\n");

	premier_court=clongc[0];
	premier_long=clongl[0];


	if (premier_long!=0) /**< Vérification que le circuit examen complémentaire n'est pas vide et initialisation du premier patient en examen complémentaire */
	{
    	heure=heure_exam[premier_court-1];
    	minute=minute_exam[premier_court-1];
    	jour=jour_exam[premier_court-1];
    	mois=mois_exam[premier_court-1];
    	annee=annee_exam[premier_court-1];

    	heure2=heure_exam[premier_court-1];
    	minute2=minute_exam[premier_court-1];
    	jour2=jour_exam[premier_court-1];
    	mois2=mois_exam[premier_court-1];
    	annee2=annee_exam[premier_court-1];
	}
	else
    	printf("il n'y a personne dans les examens complementaires \n");


	printf("\n");

	for (i = 0; i<n2; i++) /**< Affichage de l'historique de la répartition des patients entre la sortie et l'examen complémentaire */
	{
    	printf("sort de l'hopital : %d, examen complementaire : %d \n", clongc[i], clongl[i]);
	}

	printf("\n");

	printf("Il y a %d patients qui vont faire des examens complementaires et %d patients qui vont sortir de l'hopital\n", n3, n4);

	i=0;

	printf("\n");

	while (clongl[i]!=0 && i<=n2) /**< Cette boucle fait fonctionner les box d'examen complémentaire du cicuit long, elle tourne jusqu'à ce qu'elle fasse tous les patients en examen complémentaire */
	{
    	comparaison2 (&minute, &heure, &jour, &mois, &annee, &minute2, &heure2, &jour2, &mois2, &annee2, &verif);
    	if (verif==1) /**< Si le box comp. 1 est libre ou se libère en premier alors le patient suivant prend place dans le box comp. 1 en respectant les horraires */
    	{
        	printf("le patient %d est aux examens complementaires, salle 1 \n", clongl[i]);

        	if (annee<annee_exam[clongl[i]-1])
        	{
            	annee=annee_exam[clongl[i]-1];
            	mois=mois_exam[clongl[i]-1];
            	jour=jour_exam[clongl[i]-1];
            	heure=heure_exam[clongl[i]-1];
            	minute=minute_exam[clongl[i]-1];
        	}
        	else if (mois<mois_exam[clongl[i]-1])
        	{
            	mois=mois_exam[clongl[i]-1];
            	jour=jour_exam[clongl[i]-1];
            	heure=heure_exam[clongl[i]-1];
            	minute=minute_exam[clongl[i]-1];
        	}
        	else if (jour<jour_exam[clongl[i]-1])
        	{
            	jour=jour_exam[clongl[i]-1];
            	heure=heure_exam[clongl[i]-1];
            	minute=minute_exam[clongl[i]-1];
        	}
        	else if (heure<heure_exam[clongl[i]-1])
        	{
            	heure=heure_exam[clongl[i]-1];
            	minute=minute_exam[clongl[i]-1];
        	}
        	else if (minute<minute_exam[clongl[i]-1])
        	{
            	minute=minute_exam[clongl[i]-1];
        	}

        	verification (&minute, &heure, &jour, &mois, &annee);

        	printf("le patient %d entre a l'examen complementaire a %dh%d \n", clongl[i], heure, minute);

        	/**< Calcul de la moyenne du temps d'attente dans la salle d'attente 6 */
        	heure_arrivee=heure_exam[clongl[i]-1];  minute_arrivee=minute_exam[clongl[i]-1];
            heure_passage=heure; minute_passage=minute;
            diff_heure=heure_passage-heure_arrivee;
            if (diff_heure>0)
            {
                minute_passage=minute_passage+diff_heure*60;
                moyenne_salle6=moyenne_salle6+(minute_passage-minute_arrivee);
            }
            else
            {
                moyenne_salle6=moyenne_salle6+(minute_passage-minute_arrivee);
            }
            /**< Fin calcul moyenne */

        	minute=minute+patient_T[clongl[i]-1].exam_comp;
        	printf("patient %d temps d'examen du circuit court : %d \n", clongl[i], patient_T[clongl[i]-1].exam_comp);

        	verification (&minute, &heure, &jour, &mois, &annee);

        	printf("Le patient %d sort de l'examen complementaire a %dh%d \n", clongl[i], heure, minute);

        	heure_exam_comp[clongl[i]-1]=heure;
        	minute_exam_comp[clongl[i]-1]=minute;
        	jour_exam_comp[clongl[i]-1]=jour;       /**< Enregistrement des horriares de sortie de l'examen complémentaire de chaque patient */
        	mois_exam_comp[clongl[i]-1]=mois;
        	annee_exam_comp[clongl[i]-1]=annee;


    	}
    	else if (verif==2) /**< Si le box comp. 2 est libre ou se libère en premier alors le patient suivant prend place dans le box comp. 2 en respectant les horraires */
     	{
        	printf("le patient %d est dans le circuit complementaire, salle 2 \n", clongl[i]);

        	if (annee2<annee_exam[clongl[i]-1])
        	{
            	annee2=annee_exam[clongl[i]-1];
            	mois2=mois_exam[clongl[i]-1];
            	jour2=jour_exam[clongl[i]-1];
            	heure2=heure_exam[clongl[i]-1];
            	minute2=minute_exam[clongl[i]-1];
        	}
        	else if (mois2<mois_exam[clongl[i]-1])
        	{
            	mois2=mois_exam[clongl[i]-1];
            	jour2=jour_exam[clongl[i]-1];
            	heure2=heure_exam[clongl[i]-1];
            	minute2=minute_exam[clongl[i]-1];
        	}
        	else if (jour2<jour_exam[clongl[i]-1])
        	{
            	jour2=jour_exam[clongl[i]-1];
            	heure2=heure_exam[clongl[i]-1];
            	minute2=minute_exam[clongl[i]-1];
        	}
        	else if (heure2<heure_exam[clongl[i]-1])
        	{
            	heure2=heure_exam[clongl[i]-1];
            	minute2=minute_exam[clongl[i]-1];
        	}
        	else if (minute2<minute_exam[clongl[i]-1])
        	{
            	minute2=minute_exam[clongl[i]-1];
        	}


        	verification (&minute2, &heure2, &jour2, &mois2, &annee2);

        	printf("le patient %d entre a l'examen complementaire a %dh%d \n", clongl[i], heure2, minute2);

        	/**< Calcul de la moyenne du temps d'attente dans la salle d'attente 6 */
        	heure_arrivee=heure_exam[clongl[i]-1];  minute_arrivee=minute_exam[clongl[i]-1];
        	heure_passage=heure2; minute_passage=minute2;
        	diff_heure=heure_passage-heure_arrivee;
        	if (diff_heure>0)
        	{
            	minute_passage=minute_passage+diff_heure*60;
            	moyenne_salle6=moyenne_salle6+(minute_passage-minute_arrivee);
        	}
        	else
        	{
            	moyenne_salle6=moyenne_salle6+(minute_passage-minute_arrivee);
        	}
        	/**< Fin calcul moyenne */

        	minute2=minute2+patient_T[clongl[i]-1].exam_comp;
        	printf("patient %d temps d'examen du circuit complementaire : %d \n", clongl[i], patient_T[clongl[i]-1].exam_comp );

        	verification (&minute2, &heure2, &jour2, &mois2, &annee2);

        	printf("Le patient %d sort de l'examen complementaire a %dh%d \n", clongl[i], heure2, minute2);

        	heure_exam_comp[clongl[i]-1]=heure2;
        	minute_exam_comp[clongl[i]-1]=minute2;
        	jour_exam_comp[clongl[i]-1]=jour2;      /**< Enregistrement des horraires de sortie de l'examen complémentaire de chaque patient */
        	mois_exam_comp[clongl[i]-1]=mois2;
        	annee_exam_comp[clongl[i]-1]=annee2;

    	}
    	i=i+1;
    	printf("\n");
	}

	if (n3!=0)
	{
  	moyenne_salle6=moyenne_salle6/n3;
    	printf("\nLe temps moyen passe dans la salle d'attente numero 6 est de %f minutes \n\n", moyenne_salle6);
	}
	else
    	printf("Il n'y a personne qui est alle faire les examens complémentaires\n");


	for (i=0; i<n; i++) /**< Affichage de l'historique des horraires de sortie du service d'urgence */
	{
    	if (clongl[n5]!=0 && clongl[n5]==i+1)
    	{
        	printf("Le patient %d a quitte l'hopital le %d %d %d a %dh%d \n", i+1, jour_exam_comp[i], mois_exam_comp[i], annee_exam_comp[i], heure_exam_comp[i], minute_exam_comp[i]);
        	n5=n5+1;
    	}
    	else
    	{
        	printf("Le patient %d a quitte l'hopital le %d %d %d a %dh%d \n", i+1, jour_exam[i], mois_exam[i], annee_exam[i], heure_exam[i], minute_exam[i]);
    	}
	}


	temps5= (double) clock()/CLOCKS_PER_SEC -temps4-temps3-temps2-temps1;
    printf("Le programme met %f secondes pour la partie examen complémentaire \n", temps5);

    printf("Le prgogramme met %f secondes\n", (double) clock()/CLOCKS_PER_SEC);



    return (0);
}

