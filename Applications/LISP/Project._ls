(defun c::BigCircle ( / circles i rad radC Bcircle circleN ent entname)

  ;finding the biggest radius
  
  (setq circles (ssget "x" '((0 . "CIRCLE"))))
  (setq i 0
	rad 0)
  
  (repeat (sslength circles)
  	(setq entname (ssname circles i))
	(setq ent (entget entname))
    	(setq radC (cdr (assoc 40 ent)))
    	(if (>= radC rad) ;looking for the biggest radius
	  (progn
	    	(setq rad radC)
	  	(setq Bcircle ent)
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

  (setq drawing (ssget "x"))
  (setq i 0
	cent (assoc 10 Bcircle))

  (repeat (sslength drawing)
  	(setq entname (ssname drawing i))
	(setq ent (entget entname))
    	(if (not (or (= (cdr (assoc 0 ent)) "LWPOLYLINE") (= (cdr (assoc 0 ent)) "LINE")))  ;modify every entity but lines and polylines
		(setq ent (subst cent (assoc 10 ent) ent)) ;the center of the biggest circle becomes the center of every entity but lines and polylines
	)
        (setq ent (subst (cons 62 7) (assoc 62 ent) ent)) ;changing the color of every entity to white
        (entmod ent)
        (print ent)
    	(setq i (+ i 1))
        (princ "\n ------------------- \n")
  )

  ;changing the color of the biggest circle

  (if (not (member (assoc 62 Bcircle) Bcircle))
 	 (setq Bcircle (append Bcircle (list '(62 . 1)))) ;changing the color of the biggest circle to red (if group code 62 doesn't exist) (62 dxf group code is for color)
  )
  (setq Bcircle (subst (cons 62 1) (assoc 62 Bcircle) Bcircle)) ;changing the color of the biggest circle to red (if group code 62 exists)
  (entmod Bcircle)
)