;;; spiral.lsp/c:spiral
;;;
;;; Draws a spiral consisting of points, evenly spaced at a
;;; given distance. The spiral can be clockwise- or
;;; counterclockwise-oriented, starts at a given initial radius
;;; and its radius increases uniformly over rotations with a
;;; specified increment. The spiral winds about a center point
;;; and contains a finite given number of points.
(defun C:SPIRAL ( / center radius rinc delta points direction
 distprompts distances angoffset FULLCIRCLE
 cmdecho_store)
 ; init constants
 (setq FULLCIRCLE (* 2 pi))

 ; retrieve spiral characteristics
 ; center point
 (setq center (getpoint "Center of spiral: "))

 ; since the various various needed distances are similarly
 ; obtained, this is done in a loop
 (setq distprompts '("\nInitial spiral radius: "
 "\nRadius increment per full rotation: "
 "\nLinear distance between consecutive
points: "
 )
 distances nil)
 (while distprompts ; while we haven't gone thru all the prompts
 (initget 7) ; allow only strictly positive values
 ; place read distance on the head of the list
 (setq distances (cons (getdist (car distprompts)) distances)
 distprompts (cdr distprompts) ; next
 )
 )
 ; the distances list looks now something like:
 ; (points_spacing radius_increment initial_radius)
 ; - due to the (cons), values are reversed with respect to prompts
 (setq radius (caddr distances)
 rinc (cadr distances)
 delta (car distances)
 )
 ; # of points on the spiral
 (initget 7)
 (setq points (getint "\nNumber of points on the spiral: "))
 ; spiral direction
 (initget 1 "Clockwise counteRclockwise")
 (setq direction (getkword "\nSpiral direction (Clockwise
counteRclockwise): "))

 ; store and customize environment settings
 (setq cmdecho_store (getvar "CMDECHO"))
 (setvar "CMDECHO" 0) ; no commands echo
 (setvar "PDMODE" 33) ; points represented as circles
 ; all set, we are ready to begin drawing
 (setq ang 0) ; we start at a horizontal angle
 (while (/= points 0)
 ; place point at the current orientation and radius with respect
 ; to the center
 (command "point" (polar center ang radius))
 ; linear distance between points (length of arc) must
 ; be (more or less) constant; therefore, we must take
 ; the radius into consideration when modifying the angle
 (setq angoffset (/ delta radius)
 ang (if (= direction "Clockwise") (- ang angoffset)
 (+ ang angoffset))
 )
 ; confine within [0, 2pi)
 (if (< ang 0) (setq ang (+ ang FULLCIRCLE)))
 (if (>= ang FULLCIRCLE) (setq ang (- ang FULLCIRCLE)))
 ; increase the radius by a fraction of the radius increment
 ; corresponding to the displaced angle
 (setq radius (+ radius (* rinc (/ angoffset FULLCIRCLE)))
 points (1- points) ; decrement #points
 )
 ) ; points iteration
 (setvar "CMDECHO" cmdecho_store)

 (princ) ; suppress return
 ) ; C:SPIRAL


(defun c:exampleSS ( / )

  (setq ss1 (ssget "x"))
  (setq i 0 increment 0)
  (setq userInput (getpoint "\n Please give me a new point for all!\n"))
  (repeat (sslength ss1)
	  (setq entname (ssname ss1 i))
	  (setq ent (entget entname))
    	  (print ent)
    	  (setq entFPoint (assoc 10 ent))
    	  (setq oX (car userInput)
		oY (cadr userInput)
		oZ (caddr userInput)
	  )
    	  (setq nX (+ oX increment))
    	  (setq entNewFPoint (list 10 nX oY oZ))
    
    	  ;(setq entNewFPoint (cons 10 userInput))
    
    	  (setq ent (subst entNewFPoint entFPoint ent))
    	  (entmod ent)
    	  (print entFPoint)
    	  (setq i (+ i 1))
    	  (setq increment (+ increment 150))
    	  (princ "\--------------n")
	)

)

(defun c:exampleCircle ( / )

  (setq ss1 (ssget "x" '((0 . "CIRCLE")) ))
  (setq i 0 increment 0)
  (setq userInput (getpoint "\n Please give me a new point for all!\n"))
  (repeat (sslength ss1)
	  (setq entname (ssname ss1 i))
	  (setq ent (entget entname))
    	  (print ent)
    	  (setq entFPoint (assoc 10 ent))
    	  (setq entNewFPoint (cons 10 userInput))
    	  (setq ent (subst entNewFPoint entFPoint ent))
    	  (entmod ent)
    	  (print entFPoint)
    	  (setq i (+ i 1))
    	  (princ "\--------------n")
	)

)