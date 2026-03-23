(defun c::BigCircle ( / circles i rad radC Bcircle circleN ent entname cent)

  ;finding the biggest radius
  
  (setq circles (ssget "x" '((0 . "CIRCLE"))))				;create a selection set containing all the circles fron the entire database
  (setq i 0 								;index for ssname (element in a selection set)
	rad 0)
  
  (repeat (sslength circles)
  	(setq entname (ssname circles i))
	(setq ent (entget entname)) 					;the current entity of the iteration
    	(setq radC (cdr (assoc 40 ent)))	 			;the radius of the current circle
    	(if (>= radC rad) 						;looking for the biggest radius
	  (progn
	    	(setq rad radC)
	  	(setq Bcircle ent) 					;the circle with the biggest radius
	  )
	)
    	(setq i (+ i 1))
  )
  
  (princ)
  
  ;display the biggest circle
  
  (princ "The circle with the biggest radius is:")
  (print Bcircle)
  
  (princ "\n ------------------- \n")

  ;changing the drawing

  (setq drawing (ssget "x"))						;create a selection set containing all the entities fron the entire database
  (setq i 0
	cent (assoc 10 Bcircle))					;the group which contain the center of the biggest circle

  (repeat (sslength drawing)
  	(setq entname (ssname drawing i))
	(setq ent (entget entname))
    	(if (not (or (= (cdr (assoc 0 ent)) "LWPOLYLINE") (= (cdr (assoc 0 ent)) "LINE")))  ;modify every entity but lines and polylines
		(setq ent (subst cent (assoc 10 ent) ent)) 		;the center of the biggest circle becomes the center of every entity but lines and polylines
	)
	        (setq ent (subst (cons 62 7) (assoc 62 ent) ent)) 	;changing the color of every entity to white
	        (entmod ent)						;applying the changes to the entities
        (print ent)							;displaying every entity
    	(setq i (+ i 1))
        (princ "\n ------------------- \n")
  )

  ;changing the color of the biggest circle

  (if (not (member (assoc 62 Bcircle) Bcircle))
 	 (setq Bcircle (append Bcircle (list '(62 . 1))))		;changing the color of the biggest circle to red (if group code 62 doesn't exist) (62 dxf group code is for color)
  )
  (setq Bcircle (subst (cons 62 1) (assoc 62 Bcircle) Bcircle))		;changing the color of the biggest circle to red (if group code 62 exists)
  (entmod Bcircle)							;applying the changes to the biggest circle
)