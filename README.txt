--------------------------------------------------------------------------------
  ____            _      _                        .-( '.' )-.
 |  _ \ _ __ ___ (_) ___| |_                     (   \ : /   )
 | |_) | '__/ _ \| |/ _ \ __|                   ( `'-.;;;.-'` )
 |  __/| | | (_) | |  __/ |_                   ( :-==;;;;;==-: )
 |_|___|_|  \___// |\___|\__|                _  (  .-';;;'-.  )
 |_   _|__  _  |__/ __ _ __   ___  ___  ___ | |  (`  / : \  `)
   | |/ _ \| | | | '__| '_ \ / _ \/ __|/ _ \| |   '-(_.'._)-'
   | | (_) | |_| | |  | | | |  __/\__ \ (_) | |
   |_|\___/ \__,_|_|  |_| |_|\___||___/\___/|_|

--------------------------------------------------------------------------------
 Projet Tournesol
 4ème Année INSA TOULOUSE - Automatique Électronique - Systèmes Embarqués
 Benoit CAHUZAC
 Kaveena PERSAND
--------------------------------------------------------------------------------
Pour compiler le projet:
--déplier l'archive 
--lancer la commande "$make" dans le dossier ou les fichiers ont été extraits
Pour lancer le projet:
--lancer la commande "$./latournesol"
--------------------------------------------------------------------------------
--------------------------LES CLASSES-&-HERITAGES-------------------------------
--------------------------------------------------------------------------------


	actionneur		digital		capteur		analog
	¦	¦		¦ ¦		¦ ¦		¦
 	¦	¦-------¦-------¦ ¦-----¦-------¦ ¦-----¦-------¦
	¦		¦		¦  		¦
¦-------¦-------¦	¦		¦		¦
¦		¦	¦		bouton		¦
servomotor	buzzer	¦				¦
			¦		¦---------------¦-------¦
			¦		¦		¦	¦
			led		photodiode	micro	potentiometer
--------------------------------------------------------------------------------

ATTENTION: On n'avons pas redéfini le constructeur de recopie de nos objets (qui contiennent des pointeurs) car nous les passons par référence au fonction et que comme un objet est toujours associé a un pin nous n'avons pas considérer le cas ou deux objets pouvait être associé au même pin.
