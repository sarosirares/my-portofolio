(defun geomean (x y / prod)
	(setq prod (* x y))
	(sqrt prod)
)

(defun C:ZW ()
	(command "ZOOM" "Window" pause pause)
	(princ)
)

(defun xlocal ( / x)
	(setq x 0)
  	(print x)
	(princ)
)

;;; Computes the factorial of an integer using the (repeat) looping
;;; function
(defun fact_iter_r (n / fact)
	; fact is the product accumulator
	(setq fact 1)
	; there is no need to multiply by 1, so repeat only (n - 1) times
	(repeat (1- n)
		(setq fact (* fact n) ; multiply by the current n
		      n (1- n) ; decrement n
		)
	)
; we need to evaluate fact so that it is returned, otherwise
; the last value of n (namely, 1) would have always been returned
	fact
)

;;; Sample redefinition of CIRCLE command in its simplest form
(defun C:CIRCLE1 (/ c rad cmdecho)
; save the environment status
(setq cmdecho (getvar "CMDECHO"))
; customize the environment as needed
; in our case, disable that garbage-generator command echo
(setvar "CMDECHO" 0)
; get the circle parameters using iniget / getXXX
(initget 1)
(setq c (getpoint "\nChoose center point for circle:"))
(initget 7)
(setq rad (getdist c "\nChoose circle radius:"))
; draw the circle
(command "circle" c rad)
; restore the environment to its previous state
(setvar "CMDECHO" cmdecho)
; supress return value
(princ)
)

;;; Personal data registry handling functions.
;;;
;;; The registry is a list containing as entries associative lists
;;; with the following structure:
;;; ((FN . <first name>) (LN . <last name>) (AGE . <age>))
;;; The registry is held in a global variable named PD_DATA.
;; Requests data for a new entry from the user and appends
;; the entry to the registry.
(defun C:PD_ADDENTRY ( / fname lname age entry)
 ; get the data from the user
 (initget 1)
 (setq fname (getstring "\nEnter person's first name: "))
 (initget 1)
 (setq lname (getstring "\nEnter person's last name: "))
 (initget 7)
 (setq age (getint "\nEnter person's age: "))
 ; create and append the entry

 ; note the usage of the (cons) function with two atom arguments
 ; and that the new entry must be wrapped in a list with the (list)
 ; function prior to being appended to the PD_DATA
 (setq entry (list (cons 'FN fname) (cons 'LN lname)
 (cons 'AGE age))
 PD_DATA (append PD_DATA (list entry))
 )

 ; supress return
 (princ)
 )

;; Lists the contents of the personal data registry in
;; human-readable form.
(defun C:PD_LIST ( / current entry counter)

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
 (princ (strcat "\nRecord #" (itoa counter)
 ": " (cdr (assoc 'LN entry))
 ", " (cdr (assoc 'FN entry))
 ". Age " (itoa (cdr (assoc 'AGE entry)))
 )
 )
 (setq current (cdr current) ; next entry
 counter (1+ counter)
 )
 )
 ; suppress return
 (princ)
 )