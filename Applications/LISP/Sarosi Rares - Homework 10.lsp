(defun C:PD_SEARCH ( / current entry counter)

	 (setq low (getint "Enter the lower bound: "))
  	 (setq upp (getint "\nEnter the upper bound: "))
	 ; we don't want to destroy the pointer to the actual registry,
	 ; so we use an internal var to navigate over the entries
	 (setq current PD_DATA
	       counter 1) ; this is just for the looks of it
	 ; since the navigation pointer will eventually reach the NIL
	 ; at the end of the registry list, it's a perfectly good value
	 ; to use for the loop test
	 (while current
			 (setq entry (car current)) ; get the data
			 ; the actual data is in the CDRs of data items on the
			 ; entry's associative list, the CARs are the keys
	   		 (if (and
			       (<= low (cdr (assoc 'AGE entry)))
			       (<= (cdr (assoc 'AGE entry)) upp))
			    (progn
				 (princ (strcat "\nRecord #" (itoa counter)
				 ": " (cdr (assoc 'LN entry))
				 ", " (cdr (assoc 'FN entry))
				 ". Age " (itoa (cdr (assoc 'AGE entry)))
				 	)
			 	 )
			    )
			 )
			 (setq current (cdr current) ; next entry
			 counter (1+ counter)
			 )
	 )
	 ; suppress return
	 (princ)
 )


(defun C:PD_RMENTRY ( / current entry)
	 (initget 1)
	 (setq fname (getstring "\nEnter person's first name: "))
	 (initget 1)
	 (setq lname (getstring "\nEnter person's last name: "))
  	 (setq current PD_DATA)
  	 (while current
		 (setq entry (car current)) ; get the data
		 (if (and
		       (= fname (cdr (assoc 'FN entry)))
		       (= lname (cdr (assoc 'LN entry)))
		     )
		  (progn
		  		(setq PD_DATA (vl-remove entry PD_DATA))
		    		(princ "Successful!")
		  )
		 )
		 (setq current (cdr current)) ; next entry
  	 )
  (princ)
)


(defun C:Draw_David ( / center radius height brench point0 point1 point2)
  	(setq center (getpoint "Enter the center of the circle: "))
  	(setq radius (getreal "Enter the radius of the circle: "))

  	(setq height (/ radius 2))
  	(setq brench (* height (/ 2 (sqrt 3))))

  	(setq point0 (list (- (car center) (/ brench 2)) (+ (cadr center) height)))
	(setq point1 (list (car center) (+ (cadr center) radius)))
 	(setq point2 (list (+ (car center) (/ brench 2)) (+ (cadr center) height)))

  	(command "PLINE" point0 point1 point2 "")
  	(command "arraypolar" (entlast) "" center 6 360 "")
  (princ)
  
  	
  )